<?php

require_once "db.php";
require_once 'global.php';

function build_news($raw_news)
{
    $news = '';
    if ($raw_news) {
        $news .= '<ul id="news-container">';
        foreach ($raw_news as $item) {
            $news .= '  <li class="news-item">
                        <img alt="' . $item["alt"] . '" src="' . $item["p_path"] . '">
                        <div class="news-content">
                        <h2>' . $item["title"] . '</h2>
                        <p>' . $item["summary"] . '</p>
                        <span>' . date("d/m/Y", strtotime($item["creation_date"])) . '</span>
                        </div>
                        </li>';
        }
        $news .= '</ul>';
    } else $news = '<p class="warning">Nessuna news disponibile</p>';
    return $news;
}

$page = file_get_contents("../html/news.html");

$conn = new sushiDB();

if (!$conn->is_open()) {
    $conn->open_connection();
    $raw_news = $conn->get_all_news();
    $conn->close_connection();
    $news = build_news($raw_news);
}

$base_path = get_page_name(file_get_contents("../html/home.html"));
$current_page = get_page_name($page);
$breadcrumb = '<a lang="en" href="/srizzato/php/home.php">' . $base_path . '</a> &gt; <span>' . $current_page . '</span>';
$page = remove_page_name($page);
$header = build_header($breadcrumb);
$page = str_replace("<page-header />", set_current_header_tags($header, '/srizzato/php/news.php', 'top-nav-current'), $page);
$page = str_replace("<news-list />", $news, $page);

echo $page;
