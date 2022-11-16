<?php
require_once 'db.php';
require_once 'validation.php';
require_once 'global.php';

use function SushiValidation\validate_username;
use function SushiValidation\validate_password;
use function SushiValidation\clear_input;

if ($_SESSION["logged"]) {
    display_info('Hai già effettuato l\'accesso', "/srizzato/php/area_personale.php", "../html/area_personale.html");
}

$page = file_get_contents("../html/login.html");
$error_message = "";
$general_error = "";
$username = '';
$password = '';

if (isset($_POST["submit_login"])) {
    $username = clear_input($_POST["username"]);
    $password = clear_input($_POST["password"]);
    if (validate_username($username) && validate_password($password)) {
        $conn = new sushiDB();
        if ($conn->open_connection()) {
            $user_info = $conn->validate_user($username, $password);
            if ($user_info) {
                $_SESSION["active_cart"] = $conn->get_active_cart($user_info[0]["username"])[0]["id"];
                $conn->close_connection();
                $_SESSION["logged"] = true;
                $_SESSION["admin"] = $user_info[0]["is_admin"];
                $_SESSION["username"] = $user_info[0]["username"];
                $_SESSION["first_name"] = $user_info[0]["first_name"];
                $_SESSION["last_name"] = $user_info[0]["last_name"];
                $_SESSION["email"] = $user_info[0]["email"];
                header("Location: area_personale.php");
                exit();
            }
            $conn->close_connection();
            $error_message = '  <strong class="error-message"><span lang="en">username</span> 
                                o <span lang="en">password</span> errati</strong>';
        } else
            $general_error = '  <strong class="error-message">Si è verificato
                                un problema interno, riprovare</strong>';
    } else
        $error_message = '  <strong class="error-message"><span lang="en">username</span> o 
                            <span lang="en">password</span> errati</strong>';
}

$base_path = get_page_name(file_get_contents("../html/home.html"));
$current_page = get_page_name($page);
$breadcrumb = '<a lang="en" href="/srizzato/php/home.php">' . $base_path . '</a> &gt; <span>' . $current_page . '</span>';
$page = remove_page_name($page);
$header = build_header($breadcrumb);
$page = str_replace("<page-header />", set_current_header_tags($header, '/srizzato/php/login.php', 'user-action-current'), $page);
$page = str_replace("<username-value />", $username, $page);
$page = str_replace("<password-value />", $password, $page);
$page = str_replace("<error-message />", $error_message, $page);
echo str_replace("<general-error />", $general_error, $page);
