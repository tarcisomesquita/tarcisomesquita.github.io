<?php
$data = implode("", file("php.txt"));
$gzdata = gzencode($data, 9);
$fp = fopen("php.txt.gz", "w");
fwrite($fp, $gzdata);
fclose($fp);
?>


<?php
$compressed   = gzdeflate('Compress me', 9);
$uncompressed = gzinflate($compressed);
echo $uncompressed;
?>

<?php
$compressed = gzcompress('Compress me', 9);
$uncompressed = gzuncompress($compressed);
echo $uncompressed;
?>


