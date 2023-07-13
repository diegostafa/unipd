<?php

require_once "global.php";
require_once 'db.php';
require_once 'validation.php';

use function SushiValidation\validate_img_size;
use function SushiValidation\validate_img_type;
use function SushiValidation\validate_img_alt;
use function SushiValidation\validate_dish_description;
use function SushiValidation\validate_dish_name;
use function SushiValidation\validate_dish_price;

function build_combobox($category, $insert)
{
    if ($insert)
        $result =  '<select name="dish_category" id="dish_category" >';
    else
        $result =  '<select name="categoryDelete" id="dropdownCategory" >';

    foreach ($category as $row) {
        $result .= '<option value="' . $row["c_id"] . '">';
        $result .=  $row["c_name"] . '</option>';
    }
    $result .= '</select>';
    return $result;
}

function build_category($category)
{
    $result =  '';
    $first = true;
    foreach ($category as $row) {
        if ($first && !isset($_GET["current_category"])) {
            $result .= '<li><button value="' . $row["c_id"] . '" type="submit" name="current_category" class="selected category admin">' . $row["c_name"] . '</button></li>';
            $first = false;
        } else {
            if (isset($_GET["current_category"]) && $row["c_id"] == $_GET["current_category"]) {
                $result .= '<li><button value="' . $row["c_id"] . '" type="submit" name="current_category" class="selected category admin">' . $row["c_name"] . '</button></li>';
            } else {
                $result .= '<li><button value="' . $row["c_id"] . '" type="submit" name="current_category" class="category admin">' . $row["c_name"] . '</button></li>';
            }
        }
    }
    return $result;
}

function build_dish($dishes)
{
    $result = '';
    $count = 0;
    foreach ($dishes as $row)
    {
        $count++;
        $dishLabel = 'dish'.$count;
        $result .= '<li class="dish admin">
                    <input class="checkbox" id='.$dishLabel.' type="checkbox" name="check_dish[]" value="' . $row["d_name"] . '">
                    <img class="photo" src="' . $row["p_path"] . '" alt="' . $row["alt"] .  '">
                    <label class="name" for="'.$dishLabel.'">' . $row["d_name"] . '</label>
                    <p class="description">' . $row["summary"] . '</p>
                    <span class="price">' . $row["price"] . '</span>
                    </li>';

    }
    return $result;
}

$conn = new sushiDB();
$conn->open_connection();

if ($_SESSION["admin"]) {
    if (isset($_POST["submit_add_dish"])) {
        if (!validate_img_size($_FILES["img_file"]["size"]))
            display_info("azione fallita: il file inviato supera la grandezza massima consentita di 4MB.", "/srizzato/php/menu_admin.php","../html/menu_admin.html");
        elseif (!validate_img_type($_FILES["img_file"]["tmp_name"]))
            display_info("azione fallita: l'immagine inviata non appartiene alle seguenti estensioni: jpg, jpeg, png.", "/srizzato/php/menu_admin.php","../html/menu_admin.html");        
        elseif (!validate_dish_name($_POST["dish_name"]))
            display_info("azione fallita: il nome del piatto non rispetta i vincoli richiesti di validazione.", "/srizzato/php/menu_admin.php","../html/menu_admin.html");
        elseif (!validate_dish_description($_POST["dish_description"]))
            display_info("azione fallita: la descrizione del piatto non rispetta i vincoli richiesti di validazione.", "/srizzato/php/menu_admin.php","../html/menu_admin.html");
        elseif (!validate_dish_price($_POST["dish_price"]))
            display_info("azione fallita: il prezzo del piatto non rispetta i vincoli richiesti di validazione.", "/srizzato/php/menu_admin.php","../html/menu_admin.html");
        else {
            $file = '../img/dish/' . $_POST["dish_name"];
            if (!$conn->add_picture($file, 'foto'.$_POST["dish_name"]) || !move_uploaded_file($_FILES["img_file"]["tmp_name"], $file)) {
                $conn->close_connection();
                display_info("errore interno: non è stato possibile creare l'immagine inviata all'interno del database.", "/srizzato/php/menu_admin.php","../html/menu_admin.html");
            } elseif (!$conn->add_dish($_POST["dish_name"], $_POST["dish_description"], $_POST["dish_category"], $file, $_POST["dish_price"])) {
                $conn->close_connection();
                display_info("errore interno: non è stato possibile creare il piatto all'interno del database.","/srizzato/php/menu_admin.php","../html/menu_admin.html");
            }
            else{
              $conn->close_connection();
              display_info("Il piatto " . $_POST["dish_name"] . " è stato inserito correttamente", "/srizzato/php/menu_admin.php","../html/menu_admin.html");
            }
        }
    }
    if (isset($_GET["submit_add_category"]))
        if (!(!$conn->is_category_present($_GET["new_category"]) && $conn->add_category($_GET["new_category"]))) {
            $conn->close_connection();
            display_info("errore interno: non è stato possibile aggiungere la categoria","/srizzato/php/menu_admin.php","../html/menu_admin.html");
        } else {
            $conn->close_connection();
            display_info("La categoria " . $_GET["new_category"] . " è stata inserita correttamente", "/srizzato/php/menu_admin.php","../html/menu_admin.html");
        }
    if (isset($_GET["submit_remove_category"]))
        if (!($conn->get_category_by_id($_GET["categoryDelete"]) && $conn->remove_category($_GET["categoryDelete"]))) {
            $conn->close_connection();
            display_info("errore interno: non è stato possibile eliminare la categoria","/srizzato/php/menu_admin.php","../html/menu_admin.html");
        }
        else {
            $conn->close_connection();
            display_info("La categoria " . $_GET["submit_remove_category"] . " è stata eliminata correttamente", "/srizzato/php/menu_admin.php","../html/menu_admin.html");
        }
    if (isset($_GET["submit_remove_dish"])) {
        if (!$conn->remove_dish($_GET["check_dish"])) {
            $conn->close_connection();
            display_info("errore interno: non è stato possibile eliminare il piatto","/srizzato/php/menu_admin.php","../html/menu_admin.html");
        }
        else {
            $conn->close_connection();
            display_info("I piatti sono stati eliminati correttamente", "/srizzato/php/menu_admin.php","../html/menu_admin.html");
        }
    }

    $pageHTML = file_get_contents("../html/menu_admin.html");

    $category = $conn->get_menu_category();
    if ($category) {
        $listCategory = '<form method="get" action="menu_admin.php" class="formFilter"><fieldset>
                        <legend class="menuLegend">Seleziona categoria del piatto</legend>
                        <ul class="filter admin">';
        
        $listCategory .= build_category($category);
        $listCategory .= '</ul></fieldset></form>';
        $pageHTML = str_replace('<category-list />', $listCategory, $pageHTML);
    } else {
        $pageHTML = str_replace('<category-list />', '', $pageHTML);
    }

    $category = $conn->get_all_category();
    $listCategory = build_combobox($category, 1);
    $pageHTML = str_replace('<insert-category-list />', $listCategory, $pageHTML);

    $category = $conn->get_deletable_category();
    if ($category) {
        $listCategory = '<form method="get" action="menu_admin.php" id="form_delete_category"><fieldset><legend>Categorie senza piatti</legend>';
        $listCategory .= '<label for="dropDownCategory">Seleziona categoria che vuoi eliminare:</label>';
        $listCategory .= build_combobox($category, 0);
        $listCategory .= '<div class="button-delete-category"><input type="submit" id="category_name" name="submit_remove_category" value="Elimina" /></div></fieldset></form>';
        $pageHTML = str_replace('<delete-category-list />', $listCategory, $pageHTML);
    } else
        $pageHTML = str_replace('<delete-category-list />', '<p>non ci sono categorie eliminabili<p>', $pageHTML);


    if (isset($_GET["current_category"]))
        $dishes = $conn->get_dish_by_category($_GET["current_category"]);
    else {
        $category = $conn->get_menu_category();
        if ($category) {
            $row = $category[0];
            $dishes = $conn->get_dish_by_category($row["c_id"]);
        }
    }

    if ($category) {
        $listDishes = '<form method="get" action="menu_admin.php" class="container-content"><fieldset>
                       <legend class="menuLegend">Seleziona il piatto da eliminare</legend>
                       <ul id="dish-container">';
        $listDishes .= build_dish($dishes);
        $listDishes .= '</ul><input type="submit" name="submit_remove_dish" value="Elimina piatti" /></fieldset></form>';
        $pageHTML = str_replace('<dish-list />', $listDishes, $pageHTML);
    } else {
        $pageHTML = str_replace('<dish-list />', '<p>Nessun piatto da rimuovere</p>', $pageHTML);
    }
    
    $base_path = get_page_name(file_get_contents("../html/home.html"));
    $area_path = get_page_name(file_get_contents("../html/area_personale.html"));
    $current_page = get_page_name($pageHTML);
    $breadcrumb = '<a lang="en" href="/srizzato/php/home.php">' . $base_path . '</a> &gt;<a lang="en" href="/srizzato/php/area_personale.php">' . $area_path . '</a>&gt; <span>' . $current_page . '</span>';

    $pageHTML = remove_page_name($pageHTML);
    $pageHTML = str_replace("<page-header />", build_header($breadcrumb), $pageHTML);

    
    echo $pageHTML;
} else
    display_info("Non hai il permesso per l'accesso a questa pagina", "/srizzato/php/menu_admin.php","../html/menu_admin.html");
