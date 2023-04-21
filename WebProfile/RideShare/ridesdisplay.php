<?php
    session_start();
    try {
        require "dbConnect.php";
        $db = get_db();
    } catch (Exception $e) {
        exit;
    }

    $location = htmlspecialchars($_POST["location"]);
    $destination = htmlspecialchars($_POST["destination"]);
    $price = htmlspecialchars($_POST["price"]);
    $date = htmlspecialchars($_POST["date"]);
    $time = htmlspecialchars($_POST["time"]);

    try{
    $rides = $db->prepare('SELECT location, destination, date, time, price 
                           FROM rides 
                           WHERE rider_id IS NULL');
    // $rides->bindValue(':location', $location, PDO::PARAM_STR);
    // $rides->bindValue(':destination', $destination, PDO::PARAM_STR);
    // $rides->bindValue(':date', $date, PDO::PARAM_STR);
    // $rides->bindValue(':time', $time, PDO::PARAM_STR);
    // $rides->bindValue(':price', $price, PDO::PARAM_INT);
    $rides->execute();

    echo "<table class='table'>";
    echo "<tr>";
        echo "<td>Select</td>";
        echo "<td>Location</td>";
        echo "<td>Destination</td>";
        echo "<td>Time</td>";
        echo "<td>Date</td>";
        echo "<td>Price</td>";
    echo "</tr>";

        while ($row = $rides->fetch(PDO::FETCH_ASSOC)) { ?>
            <tr>
                <td><input type="checkbox" id= <?php echo $row["id"] ?> name= <?php echo $row["id"] ?> value= <?php echo $row["id"] ?>>
                <?php
                echo "<td>" . $row["location"] . "</td>";
                echo "<td>" . $row["destination"] . "</td>";
                echo "<td>" . $row["time"] . "</td>";
                echo "<td>" . $row["date"] . "</td>";
                echo "<td>" . $row["price"] . "</td>";
                ?>
            </tr>
        <?php } ?>
        </table>
    
<?php } catch (Exception $e) {
    echo "Error: $e";
    echo "Search query failed";
    die();
    }
?>