<?php
require_once 'db.php';
require_once 'global.php';


function build_category($category_table)
{
    $html_category_list =  '';
    $first = true;
    if ($category_table) {
        foreach ($category_table as $row) {
            if ($first && !isset($_GET["current_category"])) {
                $html_category_list .= '<li><button name="current_category" value="' . $row["c_id"] . '" class="category selected">';
                $first = false;
            } elseif (isset($_GET["current_category"]) && $row["c_id"] == $_GET["current_category"])
                $html_category_list .= '<li><button name="current_category" value="' . $row["c_id"] . '" class="category selected">';
            else
                $html_category_list .= '<li><button name="current_category" value="' . $row["c_id"] . '" class="category">';
            $html_category_list .=  $row["c_name"];
            $html_category_list .= '</button></li>';
        }
        return $html_category_list;
    }
}

function build_dish($dish_table)
{
    $html_dish_list = '';
    foreach ($dish_table as $row) {
        $html_dish_list .= '<li class="dish">'
            . '<img class="photo" src="' . $row["p_path"] . '" alt="' . $row["alt"] .  '">'
            . '<div class="name">' . $row["d_name"] . '</div>'
            . '<p class="description">' . $row["summary"] . '</p>'
            . '<span class="price">' . $row["price"] . '</span>'
            . '<button class="btnAdd ns-hide" type="button" onclick="addCart(event)">Aggiungi</button>'
            . '</li>';
    }
    return $html_dish_list;
}
function build_cart($cart_table)
{
    $html_cart_list = '';
    $count = 0;
    if ($cart_table) {
        foreach ($cart_table as $row) {
            $html_cart_list .= '<li class="cart-item">'
                . '<span class="name' . $count . '">' . $row["d_name"] . '</span>'
                . '<input value="' . $row["d_name"] . '" name="cart_dish_name[]" type="hidden">'
                . '<span class="price' . $count . '">' . $row["price"] . '</span>'
                . '<div class="container-function">'
                . '<div class="container-function">'
                . '<button class="btn-qnt" type="button" onclick="decrease(event,' . $count . ')">'
                . '<img src="/srizzato/img/utils/minus.png" alt="bottone diminuisci">'
                . '</button>'
                . '<input class="quantity' . $count . '" type="number" name="cart_dish_qnt[]" value="' . $row["quantity"] . '" min="1" max="99">'
                . '<button class="btn-qnt" type="button" onclick="increase(event,' . $count . ')">'
                . '<img src="/srizzato/img/utils/plus.png" alt="bottone aumenta"></button>'
                . '</div>'
                . ' <button class="btn-remove" onclick="removeCart(' . $count . ')">rimuovi</button>'
                . '</li>';
            $count++;
        }
    }
    $html_cart_list .= '<input id="count_cart" type="hidden" name="count_cart" value="' . $count . '">';
    return $html_cart_list;
}

$page = file_get_contents("../html/menu.html");

$conn = new sushiDB();
$conn->open_connection();
$category_table = $conn->get_menu_category();
$html_category_list = build_category($category_table);
$cartList = "";
$html_cart_list = '';
if ($_SESSION["logged"]) {
    if (!isset($_SESSION["active_cart"]))
        $_SESSION["active_cart"] = $conn->get_active_cart($_SESSION["username"]);


    if (isset($_POST["submit_replace_cart"]) && isset($_POST["count_cart"])) {
        $contentValues = array();
        for ($i = 0; $i < $_POST["count_cart"]; $i++)
            if (isset($_POST["cart_dish_name"][$i]) && isset($_POST["cart_dish_qnt"][$i]))
                $contentValues[$i] = array($_POST["cart_dish_name"][$i], $_POST["cart_dish_qnt"][$i]);
        if (!$conn->replace_cart_content($_SESSION["active_cart"], $contentValues)) {
            $conn->close_connection();
            display_info("non è stato possibile salvare il carrello", "/srizzato/php/menu.php","../html/menu.html");
        }
    }
    $cart_table = $conn->get_cart_content($_SESSION["active_cart"]);
    $html_cart_list = build_cart($cart_table);
}
else{
    if (isset($_POST["submit_replace_cart"])){
        $conn->close_connection();
            display_info("Per continuare è necessario eseguire il login", "/srizzato/php/menu.php","../html/menu.html");
    }
}
if (isset($_GET["current_category"]) && $conn->get_category_by_id($_GET["current_category"]))
    $dish_table = $conn->get_dish_by_category($_GET["current_category"]);
else
    $dish_table = $conn->get_dish_by_category($conn->get_menu_category()[0]["c_id"]);

$html_dish_list = build_dish($dish_table);

$base_path = get_page_name(file_get_contents("../html/home.html"));
$current_page = get_page_name($page);
$breadcrumb = '<a lang="en" href="/srizzato/php/home.php">' . $base_path . '</a> &gt; <span>' . $current_page . '</span>';
$page = remove_page_name($page);
$header = build_header($breadcrumb);
$page = str_replace("<page-header />", set_current_header_tags($header, '/srizzato/php/menu.php', 'top-nav-current'), $page);
$page = str_replace('<category-list />', $html_category_list, $page);
$page = str_replace('<cart-items />', $html_cart_list, $page);
$page = str_replace('<dish-list />', $html_dish_list, $page);

echo $page;
