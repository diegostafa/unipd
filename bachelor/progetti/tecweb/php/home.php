<?php

require_once "db.php";
require_once 'global.php';

function build_news($raw_news)
{
    $news = '';
    if ($raw_news) {
        $news = '<ul>';
        foreach ($raw_news as $item)
            $news .= '  <li class="news-item">
                          <img src="' . $item["p_path"] . '" alt="'  . $item["alt"] . '">
                        <div class="news-content">
                        <h2>' . $item["title"] . '</h2>
                        <p>' . $item["summary"] . '</p>
                        <span>' . date("d/m/Y", strtotime($item["creation_date"])) . '</span>
                        </div>
                        </li>';
        $news .= '</ul>';
    } else $news = '<p class="warning">Nessun news disponibile</p>';
    return $news;
}

function build_dish($raw_dish)
{
    $dish = '';
    if ($raw_dish) {
        $dish = '<ul id="dish-container">';
        foreach ($raw_dish as $item)
            $dish .= '  <li class="dish">
                        <img class="photo" src="' . $item["p_path"] . '" alt="' . $item["alt"] .  '">
                        <div class="name">' . $item["d_name"] . '</div>
                        <p class="description">' . $item["summary"] . '</p>
                        <span class="price">' . $item["price"] . '</span>
                        </li>';
        $dish .= '</ul>';
    } else $dish = '<p class="warning">Nessun piatto disponibile</p>';
    return $dish;
}

$page = file_get_contents("../html/home.html");
$conn = new sushiDB();

if ($conn->open_connection()) {
    $raw_dish = $conn->get_top_dish(3);
    $raw_news = $conn->get_last_news(2);
    $conn->close_connection();
    $news = build_news($raw_news);
    $dish = build_dish($raw_dish);
} else {
    $news = '<p class="error">errore interno: nessun dato disponibile</p>';
    $dish = $news;
}

$current_page = get_page_name($page);
$breadcrumb = '<span lang="en">' . $current_page . "</span>";
$page = remove_page_name($page);
$header = build_header($breadcrumb);

$page = str_replace('<page-header />', set_current_header_tags($header, '/srizzato/php/home.php', 'top-nav-current'), $page);
$page = str_replace("<last-news />", $news, $page);
$page = str_replace("<top-dish />", $dish, $page);

echo $page;
