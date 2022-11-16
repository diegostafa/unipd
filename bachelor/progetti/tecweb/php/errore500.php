<?php

require_once 'global.php';

$page = file_get_contents('../html/errore500.html');

$base_path = get_page_name(file_get_contents('../html/home.html'));
$current_page = get_page_name($page);
$page = remove_page_name($page);
$breadcrumb = '<a lang="en" href="/srizzato/php/home.php">'. $base_path .'</a> &gt; <span>' . $current_page . '</span>';

echo str_replace('<page-header />', build_header($breadcrumb), $page);

?>