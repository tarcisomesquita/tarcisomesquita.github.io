<?php
$str = 'string';
$chars = preg_split('//', $str, -1, PREG_SPLIT_NO_EMPTY);
print_r($chars);
?>

<?php
$str = 'hypertext language programming';
$chars = preg_split('/ /', $str, -1, PREG_SPLIT_OFFSET_CAPTURE);
print_r($chars);
?>

<?php
$content = '<strong>Lorem ipsum dolor</strong> sit <img src="test.png" />amet <span class="test" style="color:red">consec<i>tet</i>uer</span>.';
$chars = preg_split('/<[^>]*[^\/]>/i', $content, -1, PREG_SPLIT_NO_EMPTY | PREG_SPLIT_DELIM_CAPTURE);
print_r($chars);
?>

<?php
$chars = preg_split('/(<[^>]*[^\/]>)/i', $content, -1, PREG_SPLIT_NO_EMPTY | PREG_SPLIT_DELIM_CAPTURE);
print_r($chars); //parentheses added
?>

