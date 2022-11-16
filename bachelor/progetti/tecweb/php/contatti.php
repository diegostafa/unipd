<?php

require_once 'global.php';

$page = file_get_contents("../html/contatti.html");
$base_path = get_page_name(file_get_contents("../html/home.html"));
$current_page = get_page_name($page);
$breadcrumb = '<a lang="en" href="/srizzato/php/home.php">'. $base_path .'</a> &gt; <span>'. $current_page .'</span>';
$page = remove_page_name($page);

$header = build_header($breadcrumb);
$page = str_replace("<page-header />", set_current_header_tags($header, '/srizzato/php/contatti.php', 'top-nav-current'), $page);

echo $page;
