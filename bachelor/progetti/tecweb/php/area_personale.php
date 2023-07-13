<?php
require_once 'db.php';
require_once 'global.php';

if (!$_SESSION["logged"]) {
    header('Location: login.php');
    exit();
}

$page = file_get_contents('../html/area_personale.html');

$list_orders = '';
$conn = new sushiDB();

if ($conn->open_connection()) {
    $user_orders = $conn->get_order_by_user($_SESSION["username"]);
    $conn->close_connection();
    if ($user_orders) {
        foreach ($user_orders as $order) {
            $delivery = $order["take_away"] ? 'take away' : 'domicilio';
            $attribute_lang = $order["take_away"] ? 'lang="en"' : '';
            $delivery_date = date_create($order["delivery_date"]);
            $list_orders .= '
                <tr>
                <th scope="row" data-title="ordine">' . $order["cart_id"] . '</th>
                <td ' . $attribute_lang . ' data-title="tipo">' . $delivery . '</td>
                <td data-title="data">' . date_format($delivery_date, 'd-m-Y') . '</td>
                <td data-title="tot">' . number_format($order["tot_price"], 2, ',', '') . '€</td>
                </tr>
            ';
        }
    }
}
else
    display_info("Si è verificato un errore interno, riprova più tardi", "/srizzato/php/area_personale.php", "../html/area_personale.html");

$admin_menu = '';
if ($_SESSION["admin"]) {
    $admin_menu = '
        <section class="section-block reversed">
        <h1 class="section-title">gestisci il sito</h1>
        <div class="section-content">
        <ul>
        <li class="functionality"><a href="/srizzato/php/news_admin.php">Gestisci le <span lang="en">news</span></a></li>
        <li class="functionality"><a href="/srizzato/php/menu_admin.php">Gestisci il menù</a></li>
        </ul>
        </div>
        </section>
        <hr />
    ';
}

$base_path = get_page_name(file_get_contents('../html/home.html'));
$current_page = get_page_name($page);
$page = remove_page_name($page);
$breadcrumb = '<a lang="en" href="/srizzato/php/home.php">' . $base_path . '</a> &gt; <span>' . $current_page . '</span>';
$header = build_header($breadcrumb);

$page = str_replace('<page-header />', set_current_header_tags($header, '/srizzato/php/area_personale.php', 'user-action-current'), $page);
$page = str_replace('<first-name />', $_SESSION["first_name"], $page);
$page = str_replace('<last-name />', $_SESSION["last_name"], $page);
$page = str_replace('<username />', $_SESSION["username"], $page);
$page = str_replace('<email />', $_SESSION["email"], $page);
$page = str_replace('<admin-menu />', $admin_menu, $page);
echo str_replace('<orders />', $list_orders, $page);
