<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Check if 'fname' is set in the $_POST array
    if (isset($_POST['fname'])) {
        $name = $_POST['fname'];
        if (empty($name)) {
            echo "Name is empty";
        } else {
            echo $name;
        }
    } else {
        echo "Name is not set in the form submission.";
    }

    // Check if 'femail' is set in the $_POST array
    if (isset($_POST['femail'])) {
        $email = $_POST['femail'];
        if (empty($email)) {
            echo "Email is empty";
        } else {
            echo $email;
        }
    } else {
        echo "Email is not set in the form submission.";
    }
}
?>
