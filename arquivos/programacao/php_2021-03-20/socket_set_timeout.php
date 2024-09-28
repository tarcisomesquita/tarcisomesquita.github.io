<?php
// stream_set_timeout ( resource $stream , int $seconds [, int $microseconds = 0 ] ) : bool

$fp = fsockopen("www.google.com", 80);
if (!$fp) {
    echo "Unable to open\n";
} else {

    fwrite($fp, "GET / HTTP/1.0\r\n\r\n");
    stream_set_timeout($fp, 2);
    $res = fread($fp, 2000);

    $info = stream_get_meta_data($fp);
    fclose($fp);

    if ($info['timed_out']) {
        echo 'Connection timed out!';
    } else {
        echo $res;
    }

}
?>

