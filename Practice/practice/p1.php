<?php
session_start();
if(!isset($_SESSION['pageViews']))
{
    $_SESSION['pageViews']=1;
}
else
{
    $_SESSION['pageViews']++;
}


$pageviews=$_SESSION['pageViews'];


?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h1>Welcome to this page</h1>
    <p>This page has been viewd<?php echo $pageviews; ?> times.</p>
    
</body>
</html>