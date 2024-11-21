<?php

$zip = new ZipArchive();
$filename = "./zip_create.zip";

if ($zip->open($filename, ZipArchive::CREATE)!==TRUE) {
    exit("cannot open <$filename>\n");
}

$zip->addFromString("testfilephp.txt", "#1 This is a test string added as testfilephp.txt.\n");
$zip->addFromString("testfilephp2.txt", "#2 This is a test string added as testfilephp2.txt.\n");
$zip->addFile("mpdf.pdf");
$zip->addFile("mpdf.php");
echo "numfiles: " . $zip->numFiles . "\n";
echo "status:" . $zip->status . "\n";
$zip->close();
?>
