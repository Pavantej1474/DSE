<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Employee Details</title>


    /* Apply styles to the body */
    <style>
        
body {
    font-family: Arial, sans-serif;
    background-color: #f4f4f4;
    margin: 0;
    padding: 0;
}

/* Center the content in the page */
h2 {
    text-align: center;
    color: #333;
}

/* Style the table */
table {
    border-collapse: collapse;
    width: 50%;
    margin: 20px auto; /* Center the table */
    background-color: #fff;
    box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
}

/* Style table header */
th, td {
    border: 1px solid #dddddd;
    text-align: left;
    padding: 8px;
}

th {
    background-color: #4CAF50; /* Green header background */
    color: white;
}

/* Style table rows */
tr:nth-child(even) {
    background-color: #f9f9f9; /* Light gray background for even rows */
}

/* Hover effect on table rows */
tr:hover {
    background-color: #e0e0e0;
}

    <!-- <style>
        table {
            border-collapse: collapse;
            width: 50%;
            margin: 20px;
        }

        th, td {
            border: 1px solid #dddddd;
            text-align: left;
            padding: 8px;
        }
    </style> -->

    <!-- <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/water.css@2/out/water.css"> -->

</head>
<body>

    <h2>Employee Details</h2>

    <?php
    // Read JSON file
    $jsonContent = file_get_contents('p7.json');
    $employees = json_decode($jsonContent, true);

    if ($employees !== null) {
        // Display employees in a table
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
        echo 'Error decoding JSON file.';
    }
    ?>

</body>
</html>
