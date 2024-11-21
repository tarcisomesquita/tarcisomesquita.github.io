<?php
$array = [
    "foo" => "bar",
    "bar" => "foo",
    100   => -100,
    -100  => 100,
];
var_dump($array);
print_r($array);
?>
<br />

<?php
$array2 = ["foo", "bar", "hello", "world"];
var_dump($array2);

$array2["x"] = 42; // Isto acrescenta um novo elemento
                // para o array com a chave "x"

unset($arrey2[4]); // Isto remove um elemento do array

unset($arrey2);    // E isto apaga todo o array

// Agora apagando todos os itens, mas deixando o array intacto:
foreach ($array as $i => $value) {
	echo " $i: $array[$i]\n";
    unset($array[$i]);
}
print_r($array);


?>

<?php

$cores = array('vermelho', 'azul', 'verde', 'amarelo');
foreach ($cores as &$cor) {
    $cor = strtoupper($cor);
}
unset($cor); /* ensure that following writes to       $color will not modify the last array element */

print_r($cores);
?>

<?php
// preenchendo um array com todos os itens de um diretório
$handle = opendir('.');
while (false !== ($file = readdir($handle))) {
    $files[] = $file;
}
closedir($handle);
sort($files);
print_r($files);
?>


