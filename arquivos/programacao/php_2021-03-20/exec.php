<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8" />
<meta viewport='width=device-width, initial-scale=1' />
<title>exec</title>
</head>
<body>

<?php
exec('ls -la', $output);
echo "<pre>T ";
print_r($output);
echo " </pre>";
?>

</body>
</html>
