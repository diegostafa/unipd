<?php
require_once 'global.php';
require_once 'db.php';
require_once 'validation.php';
use function SushiValidation\validate_first_name;
use function SushiValidation\validate_last_name;
use function SushiValidation\validate_username;
use function SushiValidation\validate_email;
use function SushiValidation\validate_password;
use function SushiValidation\clear_input;

if ($_SESSION["logged"]) {
    display_info('Hai già effettuato l\'accesso', "/srizzato/php/area_personale.php", "../html/area_personale.html");
}

$page = file_get_contents("../html/registrazione.html");

$messages = array(
    "first-name-message" => '',
    "last-name-message" => '',
    "username-message" => '',
    "email-message" => '',
    "password-message" => '',
    "confirm-password-message" => '',
    "general-error" => ''
);

$fields_values = array(
    "first-name" => '',
    "last-name" => '',
    "username" => '',
    "email" => '',
    "password" => '',
    "confirm-password" => ''
);

if (isset($_POST["submit_signup"])) {
    $success = true;

    foreach ($fields_values as $key => $value) {
        $name_attr = str_replace('-', '_', $key);
        $fields_values[$key] = clear_input($_POST[$name_attr]);
    }
    if (!validate_first_name($fields_values["first-name"])) {
        $messages["first-name-message"] = '
        <strong class="error-message">
            siamo spiacenti sono consentite lettere, spazi, apostrofi e massimo 50 caratteri
        </strong>';
        $success = false;
    }
    if (!validate_last_name($fields_values["last-name"])) {
        $messages["last-name-message"] = '
        <strong class="error-message">
            siamo spiacenti sono consentite lettere, spazi, apostrofi e massimo 50 caratteri
        </strong>';
        $success = false;
    }
    if (!validate_username($fields_values["username"])) {
        $messages["username-message"] = '
        <strong class="error-message"> 
            siamo spiacenti sono consentite lettere, numeri e al massimo 50 caratteri
        </strong>';
        $success = false;
    }
    if (!validate_email($fields_values["email"])) {
        $messages["email-message"] = '
        <strong class="error-message">
            inserire una <span lang="en">email</span>valida
        </strong>';
        $success = false;
    }
    if (!validate_password($fields_values["password"])) {
        $messages["password-message"] = '
        <strong class="error-message"> 
            inserire una password di almeno 4 caratteri
        </strong>';
        $success = false;
    }
    if (!validate_password($fields_values["confirm-password"]) || 
        $fields_values["confirm-password"] != $fields_values["password"]) {

        $messages["confirm-password-message"] = '
        <strong class="error-message">
            confermare la password inserita in precedenza
        </strong>';
        $success = false;
    }
    if ($success) {
        $conn = new sushiDB();
        if ($conn->open_connection()) {
            if ($conn->is_user_present($fields_values["username"])) {
                $messages["username-message"] = '<strong class="error-message">
                <span lang="en">username</span> già utilizzato</strong>';
            } else {
                $result = $conn->add_user(
                    $fields_values["first-name"], 
                    $fields_values["last-name"], 
                    $fields_values["username"], 
                    $fields_values["email"], 
                    $fields_values["password"]
                );
                if ($result) {
                    $conn->add_cart($fields_values["username"]);
                    $_SESSION["active_cart"] = $conn->get_active_cart($fields_values["username"])[0]["id"];
                    $conn->close_connection();

                    $_SESSION["logged"] = true;
                    $_SESSION["admin"] = false;
                    $_SESSION["first_name"] = $fields_values["first-name"];
                    $_SESSION["last_name"] = $fields_values["last-name"];
                    $_SESSION["username"] = $fields_values["username"];
                    $_SESSION["email"] = $fields_values["email"];
                    display_info('Registrazione effettuata con successo', "/srizzato/php/area_personale.php", "../html/area_personale.html");
                    exit();
                }
                $conn->close_connection();
                $messages["general-error"] = '<strong class="error-message">
                                             Errore durante la registrazione, riprovare</strong>';
            }
        } else {
            $messages["general-error"] = '<strong class="error-message">Si è verificato
                                         un problema interno, riprovare</strong>';
        }
    }
}

foreach ($messages as $key => $value)
    $page = str_replace("<$key />", $value, $page);

foreach ($fields_values as $key => $value)
    $page = str_replace("<$key />", $value, $page);

$base_path = get_page_name(file_get_contents("../html/home.html"));
$current_page = get_page_name($page);
$breadcrumb = '<a lang="en" href="/srizzato/php/home.php">'. $base_path .'</a> &gt; <span>'. $current_page .'</span>';
$page = remove_page_name($page);
$header = build_header($breadcrumb);
echo str_replace("<page-header />", set_current_header_tags($header, '/srizzato/php/registrazione.php', 'user-action-current'), $page);
