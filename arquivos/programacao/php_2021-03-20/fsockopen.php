<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8" />
<meta viewport='width=device-width, initial-scale=1' />
<title>teste</title>
</head>
<body>

<?php
$request = "GET / HTTP/1.1\r\n";
$request .= "Host: t7m8.com.br\r\n";
$request .= "\r\n"; // We need to add a last new line after the last header

// We open a connection to www.example.com on the port 80
$connection = fsockopen('t7m8.com.br', 80);

// The information stream can flow, and we can write and read from it
fwrite($connection, $request);

// As long as the server returns something to us...
while(!feof($connection)) {
    // ... print what the server sent us
    echo fgets($connection);
}

// Finally, close the connection
fclose($connection);
?>
</body>
</html>
