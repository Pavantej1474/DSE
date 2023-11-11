<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Employee Details</title>
    <style>
        body {
    font-family: Arial, sans-serif;
    background-color: #f4f4f4;
    margin: 0;
    padding: 20px;
}

h2 {
    text-align: center;
    color: #333;
}

table {
    border-collapse: collapse;
    width: 50%;
    margin: 20px auto;
    background-color: #fff;
}

th, td {
    border: 1px solid #dddddd;
    text-align: left;
    padding: 8px;
}

th {
    background-color: #4CAF50;
    color: white;
}

form {
    max-width: 600px;
    margin: 0 auto;
}

label {
    display: block;
    margin-bottom: 8px;
    color: #333;
}

textarea {
    width: 100%;
    padding: 8px;
    margin-bottom: 16px;
    box-sizing: border-box;
}

input[type="submit"] {
    background-color: #4CAF50;
    color: white;
    padding: 10px 20px;
    border: none;
    border-radius: 5px;
    cursor: pointer;
}

input[type="submit"]:hover {
    background-color: #45a049;
}

input[type="submit"]:disabled {
    background-color: #cccccc;
    cursor: not-allowed;
}

    </style>
</head>
<body>

    <h2>Employee Details</h2>

    <?php
    // Check if the form is submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Get the JSON input from the form
        $jsonInput = $_POST['jsonInput'];

        // Decode the JSON input
        $employees = json_decode($jsonInput, true);

        // Display employees in a table
        if ($employees !== null) {
            echo '<table>';
            echo '<tr><th>ID</th><th>Name</th><th>Position</th><th>Salary</th></tr>';
            foreach ($employees as $employee) {
                echo '<tr>';
                echo '<td>' . $employee['id'] . '</td>';
                echo '<td>' . $employee['name'] . '</td>';
                echo '<td>' . $employee['position'] . '</td>';
                echo '<td>' . $employee['salary'] . '</td>';
                echo '</tr>';
            }
            echo '</table>';
        } else {
            echo 'Error decoding JSON input.';
        }
    }
    ?>

    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
        <label for="jsonInput">Enter Employee Details (JSON format):</label>
        <textarea id="jsonInput" name="jsonInput" rows="4" cols="50" required></textarea>
        <br>
        <input type="submit" value="Submit">
    </form>

</body>
</html>
