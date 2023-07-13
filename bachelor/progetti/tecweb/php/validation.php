<?php
namespace SushiValidation;

function validate_email($email) {
    return filter_var($email, FILTER_VALIDATE_EMAIL) && strlen($email) < 100;
}

function validate_first_name($first_name) {
    return preg_match("/^[A-Za-zàèìòùé\s']{1,50}$/", $first_name);
}

function validate_last_name($last_name) {
    return preg_match("/^[A-Za-zàèìòùé\s']{1,50}$/", $last_name);
}

function validate_username($username) {
    return preg_match("/^[A-Za-zàèìòùé0-9]{1,50}$/", $username);
}

function validate_password($pw) {
    return preg_match("/^.{4,20}$/", $pw);
}

function validate_address($address) {
    return preg_match("/^[a-zA-Z0-9\s']{2,}$/", $address);
}

function validate_dish_name($dish_name) {
 return preg_match("/^[A-Za-zàèìòùé0-9\s']{1,100}$/", $dish_name);
}

function validate_dish_description($dish_desc) {
    return preg_match("/^[A-Za-zàèìòùé0-9\s\.\,]{1,255}$/", $dish_desc);
}

function validate_dish_category($dish_category) {
    return preg_match("/^[A-Za-zàèìòùé0-9]{1,100}$/", $dish_category);
}

function validate_dish_price($dish_price) {
    return filter_var($dish_price, FILTER_VALIDATE_FLOAT) && round($dish_price, 2) <= 1000;
}

function validate_news_title($news_title) {
    return preg_match("/^[A-Za-zàèìòùé0-9\s']{1,50}$/", $news_title);
}

function validate_news_content($news_cont) {
    return preg_match("/^[A-Za-zàèìòùé0-9\s'\,\.]{1,255}/", $news_cont);
}

function validate_img_alt($img_alt){
    return preg_match("/^[A-Za-zàèìòùé0-9\s']{1,100}$/", $img_alt);
}

function validate_img_size($img_size){
    return $img_size < 4000000;
}

function validate_img_type($tmp_name){
    if (is_uploaded_file($tmp_name)) {
        $mime_type = mime_content_type($tmp_name);
        $allowed_file_types = ["image/png", "image/jpeg", "image/jpg"];
        if (in_array($mime_type, $allowed_file_types))
            return true;
    }
    return false;
}

function clear_input($input) {
    $input = trim($input);
    $input = htmlentities($input);
    $input = strip_tags($input);
    return $input;
}
