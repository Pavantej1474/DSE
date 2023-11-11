<?php
session_start();

// Check if the session variable is set
if (!isset($_SESSION['page_views'])) {
    $_SESSION['page_views'] = 1;
} else {
    $_SESSION['page_views']++;
}

$pageViews = $_SESSION['page_views'];
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Page Views Counter</title>
</head>
<body>

    <h2>Welcome to the Page</h2>

    <p>This page has been viewed <?php echo $pageViews; ?> times.</p>

</body>
</html>
