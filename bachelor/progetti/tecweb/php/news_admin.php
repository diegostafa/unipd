<?php

use function SushiValidation\validate_img_size;
use function SushiValidation\validate_img_type;
use function SushiValidation\validate_img_alt;
use function SushiValidation\validate_news_content;
use function SushiValidation\validate_news_title;

require_once "db.php";
require_once "validation.php";
require_once 'global.php';

function build_news($raw_news)
{
    $news = '';
    if ($raw_news) {
        $count=0;
        $news .= '<ul id="news-container">';
        foreach ($raw_news as $item)
            {
                $news .= '  <li class="news-item">
                <input id="news'.$count.'" type="checkbox" name="selected_news[]" value="' . $item["n_id"] . '"/>
                <img src="' . $item["p_path"] . '" alt="'  . $item["alt"] . '">
                <div class="news-content">
                <label for="news'.$count.'">' . $item["title"] . '</label>
                <p>' . $item["summary"] . '</p>
                <span>' . date("d/m/Y", strtotime($item["creation_date"])) . '</span>
                </div>
                </li>';
                $count++;
            }
        $news .= '</ul>';
    } else $news = '<p class="warning">Nessuna news disponibile</p>';
    return $news;
}

date_default_timezone_set('Europe/Rome');
$page = file_get_contents("../html/news_admin.html");

$conn = new sushiDB();
if ($_SESSION["admin"]) {
    if (isset($_POST["submit_add_news"])) {
        if (!validate_img_size($_FILES["img_file"]["size"]))
            display_info("azione fallita: il file inviato supera la grandezza massima consentita di 4MB.", "/srizzato/php/news_admin.php", "../html/news_admin.html");
        elseif (!validate_img_type($_FILES["img_file"]["tmp_name"]))
            display_info("azione fallita: l'immagine inviata non appartiene alle seguenti estensioni: jpg, jpeg, png.", "/srizzato/php/news_admin.php", "../html/news_admin.html");
        elseif (!validate_img_alt($_POST["img_alt"]))
            display_info("azione fallita: la descrizione dell'immagine non rispetta i vincoli richiesti di validazione", "/srizzato/php/news_admin.php", "../html/news_admin.html");
        elseif (!validate_news_title($_POST["news_title"]))
            display_info("azione fallita: il titolo della news non rispetta i vincoli richiesti di validazione.", "/srizzato/php/news_admin.php", "../html/news_admin.html");
        elseif (!validate_news_content($_POST["news_desc"]))
            display_info("azione fallita: il contenuto della news non rispetta i vincoli richiesti di validazione.", "/srizzato/php/news_admin.php", "../html/news_admin.html");
        else {
            $created_at = date('Y-m-d H:i:s');
            $ext = pathinfo($_FILES["img_file"]["tmp_name"], PATHINFO_EXTENSION);
            $file = '../img/news/' . (new DateTime($created_at))->getTimestamp() . $ext;
            if ($conn->open_connection()) {
                if (!$conn->add_picture($file, 'immagine caricata') || !move_uploaded_file($_FILES["img_file"]["tmp_name"], $file)) {
                    $conn->close_connection();
                    display_info("errore interno: non è stato possibile creare l'immagine inviata all'interno del database.","/srizzato/php/news_admin.php", "../html/news_admin.html");
                } elseif (!$conn->add_news($_POST["news_title"], $_POST["news_desc"], $created_at, $file)) {
                    $conn->close_connection();
                    display_info("errore interno: non è stato possibile creare la news all'interno del database.","/srizzato/php/news_admin.php", "../html/news_admin.html");
                }
            }
        }
    } elseif (isset($_POST["submit_remove_news"])) {
        if ($conn->open_connection()) {
            if (!$conn->remove_news($_POST["selected_news"])) {
                $conn->close_connection();
                display_info("errore interno: non è stato possibile eliminare le news selezionate","/srizzato/php/news_admin.php", "../html/news_admin.html");
            } else {
                $conn->close_connection();
                display_info("news eliminate correttamente","/srizzato/php/news_admin.php", "../html/news_admin.html");
            }
        }
    }
    if ($conn->open_connection()) {
        $raw_news = $conn->get_all_news();
        $conn->close_connection();
        $news = build_news($raw_news);
        $page = str_replace("<news-list />", $news, $page);
    }
} else
display_info("Non hai il permesso per l'accesso a questa pagina","/srizzato/php/news_admin.php", "../html/news_admin.html");




$base_path = get_page_name(file_get_contents("../html/home.html"));
$area_path = get_page_name(file_get_contents("../html/area_personale.html"));
$current_page = get_page_name($page);
$breadcrumb = '<a lang="en" href="/srizzato/php/home.php">' . $base_path . '</a> &gt;<a lang="en" href="/srizzato/php/area_personale.php">' . $area_path . '</a>&gt; <span>' . $current_page . '</span>';

$page = remove_page_name($page);
$page = str_replace("<page-header />", build_header($breadcrumb), $page);

echo $page;
