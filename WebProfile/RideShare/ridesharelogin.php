<?php // Login
    session_start();
    if ($_SESSION["loggedIn"] == false) {
        header("Location: ridesharelanding.php");
    }

    try {
        require "dbConnect.php";
        $db = get_db();
    } catch (Exception $e) {
        exit;
    }

    $username = htmlspecialchars($_POST["usernameLogin"]);
    $password = htmlspecialchars($_POST["pwdLogin"]);

    try {
        $login = $db->prepare('SELECT password_hash FROM riders WHERE username = :username');
        $login->bindValue(':username', $username, PDO::PARAM_STR);
        $login->execute();
        
        while ($row = $login->fetch(PDO::FETCH_ASSOC)) {
            if (password_verify($password, $row["password_hash"])) {
                $authenticate = true;
            }
        }

        if ($authenticate == true)
        {
            $_SESSION["loggedIn"] = true;
            $_SESSION["auth"] = 1;
            $_SESSION["username"] = $username;
            header("Location: riders.php");
            die();
        }
    } 
    
    catch (Exception $e) {
        echo "Error: $e";
        echo "Login failed!";
        die();
    }

?>