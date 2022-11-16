<?php
require_once 'global.php';


if (isset($_SESSION["info_msg"])) {
    $message = '<p class="section-desc">' . $_SESSION["info_msg"] . '</p>';
    unset($_SESSION["info_msg"]);
} else
    $message = '<p class="section-desc">Nessun evento da segnalare.</p>';

$redirect_page_name = get_page_name(file_get_contents($_SESSION["html_page"]));
$redirect_message = '<p class="section-desc">Torna in <a href="' . $_SESSION["redirect_link"] . '">' . $redirect_page_name .  '</a></p>';
$_SESSION["redirect_link"] = "/srizzato/php/home.php";
$_SESSION["html_page"] = "../html/home.html";

$page = file_get_contents("../html/info.html");
$base_path = get_page_name(file_get_contents("../html/home.html"));
$current_page = get_page_name($page);
$page = remove_page_name($page);
$breadcrumb = '<a lang="en" href="/srizzato/php/home.php">' . $base_path . '</a> &gt; <span>' . $current_page . '</span>';

$page = str_replace("<page-header />", build_header($breadcrumb), $page);
$page =  str_replace("<info />", $message, $page);
$page =  str_replace("<redirect-message />", $redirect_message, $page);
echo $page;
