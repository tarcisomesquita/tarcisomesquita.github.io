<?php
$uploaddir = 'uploads/';
$uploadfile = $uploaddir . basename($_FILES['userfile']['name']);

echo '<h2>';
if (move_uploaded_file($_FILES['userfile']['tmp_name'], $uploadfile)) {
    echo "Enviado com sucesso.\n";
} else {
    echo "Falhou. Tente outra vez!\n";
}
print "</h2>";

echo "<pre>";
echo "name: {$_FILES['userfile']['name']}\n";
echo "type: {$_FILES['userfile']['type']}\n";
echo "size: {$_FILES['userfile']['size']}\n";
echo "</pre>";

?>
