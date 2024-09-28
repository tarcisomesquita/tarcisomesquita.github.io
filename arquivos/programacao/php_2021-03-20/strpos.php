<?php
$mystring = 'abc';
$findme   = 'a';
$pos = strpos($mystring, $findme);

// Note o uso de ===.  Simples == não funcionaria como esperado
// por causa da posição de 'a' é 0 (primeiro) caractere.
if ($pos === false) {
    echo "A string '$findme' não foi encontrada na string '$mystring'";
} else {
    echo "A string '$findme' foi encontrada na string '$mystring'";
    echo " e existe na posição $pos";
}

?>
