<?php
session_start();

// Hardcoded array of user details
$userDetailsArray = array(
    "user1" => array("John", "Doe", "user1", "123 Main St"),
    "user2" => array("Jane", "Smith", "user2", "456 Oak Ave"),
    // Add more user details as needed
);

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $submittedUsername = $_POST['uname'];

    // Check if the submitted username exists in the hardcoded array
    if (array_key_exists($submittedUsername, $userDetailsArray)) {
        // Match found, set session variable
        $_SESSION['userDetails'] = $userDetailsArray[$submittedUsername];
        echo "User details matched. Session variable set.";

        // Create a cookie with the user details
        setcookie('userDetails', json_encode($userDetailsArray[$submittedUsername]), time() + (86400 * 30), "/");

        // Display the content of the cookie
        echo "<br>Cookie created with the following content: " . $_COOKIE['userDetails'];
    } else {
        echo "Username not found in the records.";
    }
}

// Redirect back to the form after processing
header("refresh:;url=index1.html"); // Redirect after 3 seconds
?>
