<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $uploadDir = "uploads/"; // Directory where uploaded files will be stored
    $resumeName = $_FILES["resume"]["name"];
    $resumeTmpName = $_FILES["resume"]["tmp_name"];
    $resumeType = $_FILES["resume"]["type"];

    $allowedTypes = ["application/pdf"];

    if (in_array($resumeType, $allowedTypes)) {
        $destination = $uploadDir . $resumeName;

        if (move_uploaded_file($resumeTmpName, $destination)) {
            echo "Resume uploaded successfully.";
        } else {
            echo "Error uploading the resume.";
        }
    } else {
        echo "Invalid file type. Please upload a PDF file.";
    }
}
?>
