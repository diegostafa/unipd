<?php
require_once 'db.php';
require_once 'global.php';
require_once 'validation.php';
use function SushiValidation\validate_address;


if (!$_SESSION["logged"]) {
    display_info('Per usare il carrello devi prima effettuare l\'accesso', "/srizzato/php/login.php","../html/login.html");
}

date_default_timezone_set('Europe/Rome');
$page = file_get_contents("../html/carrello.html");

$dishes_list = '';
$total_price = 0;
$messages = array(
    "place" => '',
    "date" => '',
    "general" => ''
);
$time_options = '';

$conn = new sushiDB();
$dishes = array();

if ($conn->open_connection()) {

    $cart_content = $conn->get_cart_content($_SESSION["active_cart"]);
    $conn->close_connection();

    if ($cart_content) {
        $dishes = $cart_content;
        foreach ($cart_content as $dish)
            $total_price += $dish["price"]*$dish["quantity"];
    }
} else {
    $messages["general"] = '<strong class="error-message">Si è verificato
                                un problema interno, riprovare</strong>';
}

if (isset($_GET["submit_add_order"])) {
    $success = true;
    if (!validate_address($_GET["place"])) {
        $success = false;
        $messages["place"] = '<strong class="error-message">inserire un indirizzo valido</strong>';
    }
    
    
    $delivery_time = strtotime($_GET["date"] . ' ' . $_GET["schedule"]);
    if ($delivery_time < time()) {
        $success = false;
        $messages["date"] = '<strong class="error-message">inserire una data valida</strong>';
    }

    if ($success) {
        if ($conn->open_connection()) {
            $result = $conn->add_order($_SESSION["active_cart"], date("Y-m-d H:i:s", time()), 
                                        date("Y-m-d H:i:s", $delivery_time), $_GET["place"],
                                        $_GET["delivery"] == "take", $total_price);
            if ($result) {
                $conn->add_cart($_SESSION["username"]);
                $_SESSION["active_cart"] = $conn->get_active_cart($_SESSION["username"])[0]["id"];

                $conn->close_connection();
                display_info("Ordine effetuato con successo", "/srizzato/php/menu.php","../html/menu.html");
            }
            $conn->close_connection();
            $messages["general"] = '<strong class="error-message">Si è verificato
                                        un problema interno, riprovare</strong>';
        } else {
            $messages["general"] = '<strong class="error-message">Si è verificato
                                        un problema interno, riprovare</strong>';
        }
    }
}

if (sizeof($dishes) > 0) {
    $dishes_list = '<ul>';
    foreach($dishes as $dish) {
        $dishes_list .= '<li><img class="photo" src="'. $dish["p_path"].
                        '" alt="'. $dish["alt"] .'" />'.
                        '<span class="name">'. $dish["d_name"] . '</span>'.
                        '<p class="description">' . $dish["summary"] . '</p>'.
                        '<div class="item-right"><p>Quantità: '. $dish["quantity"].
                        '</p><p>'. number_format($dish["price"], 2, ',', '') .
                        '€</p></div></li>';
    }
    $dishes_list .= '</ul>';
    $tag_total_price = '
    <p id="total-price" class="section-desc">
        Totale ' . number_format($total_price, 2, ',', '') . '€
    </p>';
    $page = str_replace('<total-price />', $tag_total_price, $page);
    $page = str_replace('<cart-form />', file_get_contents('../html/carrello_form.html'), $page);
} 
else {
    $page = str_replace('<total-price />', '', $page);
    $page = str_replace('<cart-form />', '', $page);
    $messages["general"] = '<p class="section-desc">Il carrello è vuoto, ti sei forse dimenticato di salvare il carrello? </p>';
}

$base_path = get_page_name(file_get_contents('../html/home.html'));
$current_page = get_page_name($page);
$page = remove_page_name($page);
$breadcrumb = '<a lang="en" href="/srizzato/php/home.php">' . $base_path . '</a> &gt; <span>' . $current_page . '</span>';$header = build_header($breadcrumb);

$page = str_replace('<page-header />', set_current_header_tags($header, '/srizzato/php/carrello.php', 'user-action-current'), $page);
foreach ($messages as $key => $value) {
    $page = str_replace("<$key />", $value, $page);
}

echo str_replace('<dishes />', $dishes_list, $page);
