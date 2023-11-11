<?php
// Function to set a cookie with the current date and time
function setVisitCookie() {
    $currentDateTime = date("Y-m-d H:i:s");
    setcookie("lastVisit", $currentDateTime, time() + 3600 * 24 * 30); // Cookie expires in 30 days
}

// Check if the "lastVisit" cookie exists
if (isset($_COOKIE["lastVisit"])) {
    $lastVisitDateTime = $_COOKIE["lastVisit"];
} else {
    // If the cookie doesn't exist, set it and retrieve the current date-time
    setVisitCookie();
    $lastVisitDateTime = date("Y-m-d H:i:s");
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Last Visited Time</title>
</head>
<body>
    <h1>Welcome to the Page</h1>
    <?php
    // Display the "Last visited on" date-time
    echo "<p>Last visited on: $lastVisitDateTime</p>";
    ?>
</body>
</html>
