<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8" />
<meta viewport='width=device-width, initial-scale=1' />
<title>shell_exec</title>
</head>
<body>

<?php
$output = shell_exec('ls -la');
echo "<pre>$output</pre>";
?>

<?php
$output = `ls -la`;
echo "<pre>$output</pre>";
?>

</body>
</html>
