<?php
// O arquivo test.xml contém um documento XML com um elemento root
// e ao menos um elemento /[root]/title.

if (file_exists('test.xml')) {
    $xml = simplexml_load_file('test.xml');

    print_r($xml);
} else {
    exit('Falha ao abrir test.xml.');
}
?>
