<?php

require_once 'global.php';
require_once 'db.php';
require_once 'validation.php';

use function SushiValidation\validate_first_name;
use function SushiValidation\validate_last_name;
use function SushiValidation\validate_email;
use function SushiValidation\clear_input;

$page = file_get_contents("../html/modifica_utente.html");

$messages = array(
    "first-name-message" => '',
    "last-name-message" => '',
    "email-message" => '',
);

$fields_values = array(
    "first-name" => '',
    "last-name" => '',
    "email" => '',
);


if (isset($_POST["submit_update_user"])) {
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
    if (!validate_email($fields_values["email"])) {
        $messages["email-message"] = '
        <strong class="error-message">
            inserire una <span lang="en">email</span>valida
        </strong>';
        $success = false;
    }
    if ($success) {
        $conn = new sushiDB();
        if ($conn->open_connection())
            if (!$conn->update_user(
                $_SESSION["username"],
                $fields_values["first-name"],
                $fields_values["last-name"],
                $fields_values["email"]
            )) {
                $conn->close_connection();
                display_info("errore interno: non è stato possibile aggiornare i dati.", "/srizzato/php/area_personale.php","../html/area_personale.html");
            } else {
                $conn->close_connection();
                $_SESSION["first_name"] = $fields_values["first-name"];
                $_SESSION["last_name"] = $fields_values["last-name"];
                $_SESSION["email"] = $fields_values["email"];
                display_info("I tuoi dati sono stati modificati correttamente", "/srizzato/php/area_personale.php","../html/area_personale.html");

            }
    }
}

foreach ($messages as $key => $value)
    $page = str_replace("<$key />", $value, $page);

foreach ($fields_values as $key => $value)
    $page = str_replace("<$key />", $value, $page);

$base_path = get_page_name(file_get_contents("../html/home.html"));
$area_path = get_page_name(file_get_contents("../html/area_personale.html"));
$current_page = get_page_name($page);
$breadcrumb = '<a lang="en" href="/srizzato/php/home.php">' . $base_path . '</a> &gt;<a lang="en" href="/srizzato/php/area_personale.php">' . $area_path . '</a>&gt; <span>' . $current_page . '</span>';

$page = remove_page_name($page);
$page = str_replace('<page-header />', build_header($breadcrumb), $page);
$page = str_replace('<firstname />', $_SESSION["first_name"], $page);
$page = str_replace('<lastname />', $_SESSION["last_name"], $page);
$page = str_replace('<usermail />', $_SESSION["email"], $page);
echo $page;
