<?php
date_default_timezone_set("UTC");
echo date('Y-m-d H:i:s P e',time())."\n";
echo "\n";

echo time()."\n";
echo microtime(true)."\n";
usleep(1000);
echo microtime(true)."\n";
echo "\n";

date_default_timezone_set("America/Sao_Paulo");
echo date('Y-m-d H:i:s P e',time())."\n";
echo "\n";

echo date('c',time())."\n";
echo "\n";

echo strtotime('2020-01-20T15:56:52-03:00')."\n";
echo "\n";

print_r(getdate());
echo "\n";

setlocale(LC_ALL, "en_US.UTF-8");
echo setlocale(LC_ALL, 0);

?>

