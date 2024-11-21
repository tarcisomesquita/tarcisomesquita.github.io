<?php
/*
superglobais são:
$GLOBALS
$_SERVER
$_GET
$_POST
$_FILES
$_COOKIE
$_SESSION
$_REQUEST
$_ENV
*/
echo "<p>";
var_dump($_SERVER);
echo "</p>\n";


// Variables start with a $
// Name must start with a letter or the underscore character _.
// Name contain characters [A-z0-9_]

echo "<p>";
$data = array(1, 1., NULL, new stdClass, 'foo');
echo gettype($data) . "<br>";

foreach ($data as $value) {
  echo gettype($value)  . "<br>";
}
echo "</p>\n";


echo "<p>";
$a = 'hello';
$$a = "world";
echo "$a ${$a}<br>";

echo "$a $hello<br>";
echo "</p>\n";

// Constant
define("SITE_URL", "https://www.tutorialrepublic.com/");
 
$color_codes = array(
    "Red" => "#ff0000",
    "Green" => "#00ff00",
    "Blue" => "#0000ff"
);

// Class definition
class greeting{
    // properties
    public $str = "Hello World!";
    
    // methods
    function show_greeting(){
        return $this->str;
    }
}
 
// Create object from class
$message = new greeting;
var_dump($message);

$handle = fopen("note.txt", "r");

$my_str = 'World';
echo "Hello, $my_str!<br>";  


echo strlen($my_str);
echo str_replace("facts", "truth", $my_str);

// Perform string replacement
str_replace("facts", "truth", $my_str, $count);
 
// Display number of replacements performed
echo "The text was replaced $count times.";


$x = 10;
$y = 4;
echo($x + $y); // 0utputs: 14

$x += $y



$x = array("a" => "Red", "b" => "Green", "c" => "Blue");
$y = array("u" => "Yellow", "v" => "Orange", "w" => "Pink");
$z = $x + $y; // Union of $x and $y
var_dump($z);
var_dump($x == $y);   // Outputs: boolean false
var_dump($x === $y);  // Outputs: boolean false
var_dump($x != $y);   // Outputs: boolean true

$_SERVER['REQUEST_METHOD']
