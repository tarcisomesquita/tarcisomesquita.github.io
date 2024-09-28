<?php
$record = geoip_record_by_name('www.unicamp.br');
if ($record) {
    print_r($record);
}

$record = geoip_record_by_name('201.55.46.177');
if ($record) {
    print_r($record);
}
?>
