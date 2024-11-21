<?php
$email  = 'name@example.com';
$domain = strstr($email, '@');
echo $domain; // prints @example.com

$user = strstr($email, '@', true); // A partir do PHP 5.3.0
echo $user; // prints name
?>
