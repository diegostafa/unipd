<?php

require_once 'global.php';
require_once 'db.php';
require_once 'validation.php';

use function SushiValidation\validate_password;
use function SushiValidation\clear_input;

$page = file_get_contents("../html/reset_password.html");

$messages = array(
    "password-message" => '',
    "new-password-message" => '',
    "confirm-new-password-message" => '',
);

$fields_values = array(
    "password" => '',
    "new-password" => '',
    "confirm-new-password" => ''
);


if (isset($_POST["submit_reset_password"])) {
    $success = true;

    foreach ($fields_values as $key => $value) {
        $name_attr = str_replace('-', '_', $key);
        $fields_values[$key] = clear_input($_POST[$name_attr]);
    }
    if (!validate_password($fields_values["password"])) {
        $messages["old-password-message"] = '
        <strong class="error-message"> 
            inserire una password di almeno 4 caratteri
        </strong>';
        $success = false;
    }
    if (!validate_password($fields_values["new-password"])) {
        $messages["password-message"] = '
        <strong class="error-message"> 
            inserire una password di almeno 4 caratteri
        </strong>';
        $success = false;
    }
    if (
        !validate_password($fields_values["confirm-new-password"]) ||
        $fields_values["confirm-new-password"] != $fields_values["new-password"]
        ) {            
        $messages["confirm-new-password-message"] = '
        <strong class="error-message">
            confermare la password inserita in precedenza
        </strong>';
        $success = false;
    }
    if ($success) {
        $conn = new sushiDB();
        if ($conn->open_connection()) {
            if (!$conn->validate_user(
                $_SESSION["username"],
                $fields_values["password"]
            )) {
                $conn->close_connection();
                display_info("La password non è stata aggiornata: la password corrente non corrisponde a quella inserita", "/srizzato/php/area_personale.php", "../html/area_personale.html");
            } else {
                if (!$conn->reset_user_password(
                    $_SESSION["username"],
                    $fields_values["new-password"]
                )) {
                    $conn->close_connection();
                    display_info("errore interno: non è stato possibile aggiornare i dati.", "/srizzato/php/area_personale.php", "../html/area_personale.html");
                } else {
                    $conn->close_connection();
                    display_info("La password è stata aggiornata correttamente", "/srizzato/php/area_personale.php", "../html/area_personale.html");
                }
            }
        }
    }
}
$base_path = get_page_name(file_get_contents("../html/home.html"));
$area_path = get_page_name(file_get_contents("../html/area_personale.html"));
$current_page = get_page_name($page);
$breadcrumb = '<a lang="en" href="/srizzato/php/home.php">' . $base_path . '</a> &gt;<a lang="en" href="/srizzato/php/area_personale.php">' . $area_path . '</a>&gt; <span>' . $current_page . '</span>';
foreach ($messages as $key => $value)
    $page = str_replace("<$key />", $value, $page);
$page = remove_page_name($page);
$page = str_replace('<old-password-message />', "", $page);
$page = str_replace('<password-message />', "", $page);
$page = str_replace('<confirm-password-message />', "", $page);
$page = str_replace('<new-password />', $fields_values['new-password'], $page);
$page = str_replace('<confirm-new-password />', $fields_values['confirm-new-password'], $page);
echo str_replace("<page-header />", build_header($breadcrumb), $page);
