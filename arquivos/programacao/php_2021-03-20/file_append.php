<?php
$myfile = fopen("newfile.txt", "w") or die("Unable to open file!");
$txt = "John Doe\n";
fwrite($myfile, $txt);
$txt = "Jane Doe\n";
fwrite($myfile, $txt);
fclose($myfile);
?>

<?php
$tfp = fopen('data.txt', 'a');//opens file in append mode.
fwrite($tfp, ' this is additional text ');
fwrite($tfp, 'appending data');
fclose($tfp);
echo "File appended successfully";
?>
