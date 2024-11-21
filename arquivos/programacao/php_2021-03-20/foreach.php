<?php
$arr = array(1, 2, 3, 4);
foreach ($arr as &$value) {
    $value = $value * 2;
}
// $arr is now array(2, 4, 6, 8)
print_r($arr);

// sem um unset($value), $value continuará como referência ao último item: $arr[3]

foreach ($arr as $key => $value) {
    // $arr[3] será atualizado com cada valor de $arr...
    echo "{$key} => {$value} \n";
}
print_r($arr);
?>
