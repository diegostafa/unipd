<?php
session_start();
session_destroy();
header("Location: home.php");
exit();

/*
TODO:
- prima del logout controllare se nel carrello temporaneo sono presenti dei piatti non salvati
*/

?>