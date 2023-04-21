<!DOCTYPE html>
<html class="bg-8"> 
    <head>
        <meta charset="utf-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>Maximizing Utility</title>
        <meta name="description" content="">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link rel="icon" type="image/ico" href="https://images-na.ssl-images-amazon.com/images/I/41TVVos4V4L._AC_.jpg">
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
        <link rel='stylesheet' type='text/css' media='screen' href='Ben.css'>
    </head>
    <body>
    <nav class="navbar navbar-inverse">
        <div class="container-fluid">
            <div class="navbar-header">
            <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#myNavbar">
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>                        
            </button>
            <a class="navbar-brand" href="#">Logo</a>
            </div>
            <div class="collapse navbar-collapse" id="myNavbar">
            <ul class="nav navbar-nav">
                <li><a href="Ben.php">Home</a></li>
                <li><a href="#">About</a></li>
                <li class="active"><a href="MaxUtil.php">Maximizing Utility Calculator</a></li>
                <li><a href="#">Contact</a></li>
            </ul>
            </div>
        </div>
    </nav>
    <h1>Maximizing Utility</h1>
        <form action="MaxUtilPost.php" method="POST">
            <div class="container-fluid squish-center3">
            <h3>Let's calculate a Lagrangian!</h3>
                <div class="col-lg-12">
                    <label for="inputIncome">Income</label>
                    <input name="inputIncome" type="text" class="form-control" placeholder="Enter the Income"> <!-- I -->
                    <label for="inputGoodX">Good X's Utility</label>
                    <input name="inputGoodX" type="text" class="form-control" placeholder="Enter X's Utility"> <!-- Alpha -->
                    <label for="inputGoodY">Good Y's Utility</label>
                    <input name="inputGoodY" type="text" class="form-control" placeholder="Enter Y's Utility"> <!-- Beta -->
                    <label for="inputPriceX">Price of X</label>
                    <input name="inputPriceX" type="text" class="form-control" placeholder="Enter Price of X"> <!-- px -->
                    <label for="inputPriceY">Price of Y</label>
                    <input name="inputPriceY" type="text" class="form-control" placeholder="Enter Price of Y"> <!-- py -->
                </div>
            </div>
            <br>
            <button type="submit" class="btn btn-primary">Submit</button>
        </form>
    </body>
</html>