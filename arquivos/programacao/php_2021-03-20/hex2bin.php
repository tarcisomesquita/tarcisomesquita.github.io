<?php

echo bin2hex('Hello'); // result: 48656c6c6f
echo hex2bin('48656c6c6f'); // result: Hello

$hex = hex2bin("6578616d706c65206865782064617461");
var_dump($hex);
?> 
