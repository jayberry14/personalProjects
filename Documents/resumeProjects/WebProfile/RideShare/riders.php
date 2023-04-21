<?php
    session_start();
    if ($_SESSION["loggedIn"] != true && $_SESSION["auth"] != 1) {
        header("Location: ridesharelanding.php");
    }

    try {
        require "dbConnect.php";
        $db = get_db();
    } catch (Exception $e) {
        die();
    }

    $_SESSION["id"];
    $_SESSION["auth"];
    $_SESSION["location"];
    $_SESSION["destination"];
    $_SESSION["date"];
    $_SESSION["time"];
    $_SESSION["price"];
    $_SESSION["driver_id"];
    $_SESSION["rider_id"];
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset='utf-8'>
    <meta http-equiv='X-UA-Compatible' content='IE=edge'>
    <title>BYU-I Ride Board</title>
    <link rel="icon" type="image/ico" href="https://web.byui.edu/mybyui/img/header/byui_logo.png">
    <meta name='viewport' content='width=device-width, initial-scale=1'>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.4.1/js/bootstrap.min.js"></script>
    <link rel='stylesheet' type='text/css' media='screen' href='directory.css'>
    <script>
			// prevents refresh from submitting form and clears out unneeded variables
            // Thank you Brother Birch for this section of JS!
            if ( window.history.replaceState ) {
                window.history.replaceState( null, null, window.location.href );
            }
    </script>
</head>
<body>
<header>
    <div class="container-fluid bg-3">
        <img src="https://web.byui.edu/mybyui/img/header/byui_logo.png" class="img-3" width="82" height="82" alt="BYU-IDAHO in white letters on black background" />
        <h1>Ride Share</h1>
    </div>
</header>
    <div class="container-fluid row" style="height:60vw">
        <form action="" method="post">
            <div class="form-group col-lg-6">
                <label for="location">Where from..?</label>
                <select class="form-control" id="location" name="location">
                    <option value="Rexburg">Rexburg</option>
                    <option value="Provo">Provo</option>
                    <option value="Salt Lake City">Salt Lake City</option>
                    <option value="Boise">Boise</option>
                </select>
            </div>
            <div class="form-group col-lg-6">
                <label for="destination">Going to..?</label>
                <select class="form-control" id="destination" name="destination">
                    <option value="Salt Lake City">Salt Lake City</option>
                    <option value="Provo">Provo</option>
                    <option value="Rexburg">Rexburg</option>
                    <option value="Logan">Logan</option>
                </select>
            </div>
            <div class="form-group col-lg-4">
                <label for="time">What time to depart...?</label>
                <select class="form-control" id="time" name="time">
                    <option value="05:00">05:00</option>
                    <option value="09:30">09:30</option>
                    <option value="11:30">11:30</option>
                    <option value="12:00">12:00</option>
                    <option value="18:30">18:30</option>
                </select>
            </div>
            <div class="form-group col-lg-4">
                <label for="date">What day to depart...?</label>
                <select class="form-control" id="date" name="date">
                    <option value="03/15/2020">03/15/2020</option>
                    <option value="03/17/2020">03/17/2020</option>
                    <option value="02/29/2020">02/29/2020</option>
                    <option value="02/21/2020">02/21/2020</option>
                    <option value="02/20/2020">02/20/2020</option>
                </select>
            </div>
            <div class="form-group col-lg-4">
                <label for="price">Max to pay...?</label>
                <select class="form-control" id="price" name="price">
                    <option value="12">$12</option>
                    <option value="11">$11</option>
                    <option value="10">$10</option>
                    <option value="9">$9</option>
                    <option value="8">$8</option>
                </select>            </div>
            <button type="submit" class="btn btn-default squish-center" id="search" name="search">Submit Search</button>
        </form>
        <?php
        if(isset($_POST["search"])) {
            $location = $_POST["location"];
            $destination = $_POST["destination"];
            $price = $_POST["price"];
            $date = $_POST["date"];
            $time = $_POST["time"];

            try {
                $rides = $db->prepare('SELECT location, destination, date, time, price 
                                       FROM rides 
                                       WHERE (rider_id IS NULL
                                       AND     location IS NOT NULL
                                       AND     destination IS NOT NULL
                                       AND     date = :date
                                       AND     time = :time
                                       AND     price <= :price)');
                $rides->bindValue(':date', $date, PDO::PARAM_STR);
                $rides->bindValue(':time', $time, PDO::PARAM_STR);
                $rides->bindValue(':price', $price, PDO::PARAM_INT);
                $rides->execute();

                echo "<table class='table squish-center3' style='box-sizing:border-box'>";
                    echo "<tr>";
                        echo "<td>Select</td>";
                        echo "<td>Location</td>";
                        echo "<td>Destination</td>";
                        echo "<td>Time</td>";
                        echo "<td>Date</td>";
                        echo "<td>Price</td>";
                    echo "</tr>";

                while ($row = $rides->fetch(PDO::FETCH_ASSOC)) { ?>
                    <form method="post" action="">
                    <tr>
                        <td><button type="submit" id="<?php echo $row["id"] ?>" name="selectRide" value="<?php echo $row["id"] ?>">Go!</button>
                        <?php
                            echo "<td>" . $row["location"] . "</td>";
                            echo "<td>" . $row["destination"] . "</td>";
                            echo "<td>" . $row["time"] . "</td>";
                            echo "<td>" . $row["date"] . "</td>";
                            echo "<td>" . $row["price"] . "</td>";
                        ?>
                    </tr>
                    </form>
                    <?php 
                }
                ?>
                </table>
                <?php 
                    if($_POST["selectRide"] != NULL) {
                        $rideSelect = $db->prepare('INSERT INTO rides (rider_id) VALUES (9999)');
                        $rideSelect->execute();
                        header("Location: rideshare.php");
                    }
            } catch (Exception $e) {
                echo "Error: $e";
                echo "Search query failed";
                die();
            }
        }
        ?>
    </div>
</body>

<footer class="container-fluid bg-3 navbar-fixed-bottom">
    <h4>Copyright ©2019 Brigham Young University - Idaho</h4>
</footer>
</html>
