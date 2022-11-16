<?php

session_start();
date_default_timezone_set('Europe/Rome');
$_SESSION["logged"] = isset($_SESSION["logged"]) && $_SESSION["logged"];
$_SESSION["admin"] = isset($_SESSION["admin"]) && $_SESSION["admin"];

function display_info($message, $redirect_link = "/srizzato/php/home.php", $html_page)
{
    $_SESSION["info_msg"] = $message;
    $_SESSION["redirect_link"] = $redirect_link;
    $_SESSION["html_page"] = $html_page;
    header("Location: info.php");
    exit();
}

function get_page_name($page)
{
    preg_match("/<page-name>(.*?)<\/page-name>/s", $page, $matches);
    return $matches[1];
}

function remove_page_name($page)
{
    preg_match("/<page-name>(.*?)<\/page-name>/s", $page, $matches);
    return str_replace($matches[0], "", $page);
}

function set_current_header_tags($header, $current_link, $class)
{
    $current_link = preg_quote($current_link, '/srizzato/');
    preg_match("/<li>[\s\r\n]*?<a.*?href=\"$current_link\".*?>.*?<\/a>[\s\r\n]*?<\/li>/", $header, $match);
    $current_tag = preg_replace("/<li/", '<li class="'. $class . '"', $match[0]);
    return preg_replace("/<li>[\s\r\n]*?<a.*?href=\"$current_link\".*?>.*?<\/a>[\s\r\n]*?<\/li>/", $current_tag, $header);
}

function build_header($breadcrumb)
{
    $header = file_get_contents('../html/header.html');
    $header = str_replace('<breadcrumb />', $breadcrumb, $header);

    $links = '<ul>';
    if ($_SESSION["logged"]) {
        $links .= '<li><a href="/srizzato/php/carrello.php">Carrello</a></li>
                   <li><a class="logged" href="/srizzato/php/area_personale.php">Ciao, ' . $_SESSION["username"] . '</a></li>
                   <li><a href="/srizzato/php/logout.php">Esci</a></li>';
    } else {
        $links .= '<li><a href="/srizzato/php/login.php">Accedi</a></li>
                   <li><a href="/srizzato/php/registrazione.php">Registrati</a></li>';
    }
    $links .= '</ul>';
    return str_replace('<login-links />', $links, $header);
}
