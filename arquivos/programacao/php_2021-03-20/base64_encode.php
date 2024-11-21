<?php
  $str = 'This is an encoded string';
  echo base64_encode($str), "\n";
  echo chunk_split(base64_encode($str),8);

  $str = 'VGhpcyBpcyBhbiBlbmNvZGVkIHN0cmluZw==';
echo base64_decode($str);
?>



