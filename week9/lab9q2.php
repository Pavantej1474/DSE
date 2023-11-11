<?php
// Function to get the current date and time
function getCurrentDateTime() {
    return date("Y-m-d H:i:s");
}

// Check if the 'last_visited' cookie is set
if (isset($_COOKIE['last_visited'])) {
    $lastVisited = $_COOKIE['last_visited'];
    echo "Last visited on: $lastVisited";
}

// Set a new cookie with the current date and time
$currentDateTime = getCurrentDateTime();
setcookie('last_visited', $currentDateTime, time() + (86400 * 30), "/"); // Cookie expires in 30 days
?>

<!DOCTYPE html>
<html>
<head>
    <title>Cookie Example</title>
</head>
<body>

    <h1>Welcome to the Paxaage</h1>

</body>
</html>

