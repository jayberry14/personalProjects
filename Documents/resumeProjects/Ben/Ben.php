<!DOCTYPE html>
<html class="no-js"> 
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
    <style>
        /* Remove the navbar's default margin-bottom and rounded borders */ 
        .navbar {
        margin-bottom: 0;
        border-radius: 0;
        }
        
    .carousel-inner img {
        width: 100%; /* Set width to 100% */
        margin: auto;
        min-height:2vw;
    }

    /* Hide the carousel text when the screen is less than 600 pixels wide */
    @media (max-width: 600px) {
        .carousel-caption {
        display: none; 
        }
    }
    </style>
    </head>
    <body class="bg-8">

    <nav class="navbar navbar-inverse">
        <div class="container-fluid">
            <div class="navbar-header">
            <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#myNavbar">
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>                        
            </button>
            <a class="navbar-brand" href="https://images-na.ssl-images-amazon.com/images/I/41TVVos4V4L._AC_.jpg">Logo</a>
            </div>
            <div class="collapse navbar-collapse" id="myNavbar">
            <ul class="nav navbar-nav">
                <li class="active"><a href="Ben.php">Home</a></li>
                <li><a href="#">About</a></li>
                <li><a href="MaxUtil.php">Maximizing Utility Calculator</a></li>
                <li><a href="#">Contact</a></li>
            </ul>
            </div>
        </div>
    </nav>
    <h1>Ben's Economic Calculators</h1>
    <div id="myCarousel" class="carousel slide" data-ride="carousel">
        <!-- Indicators -->
        <ol class="carousel-indicators">
            <li data-target="#myCarousel" data-slide-to="0" class="active"></li>
            <li data-target="#myCarousel" data-slide-to="1"></li>
            <li data-target="#myCarousel" data-slide-to="2"></li>
        </ol>

        <!-- Wrapper for slides -->
        <div class="carousel-inner" role="listbox">
            <div class="item active">
                <img class="img-1" src="https://scitechdaily.com/images/Gravity-Mysteries-Chalkboard.jpg" alt="Lagrangian">
                <div class="carousel-caption">
                <h3>Chalkboard</h3>
                <p>with stuff on it</p>
                </div>      
            </div>
            <div class="item">
                <img class="img-1" src="https://d3n8a8pro7vhmx.cloudfront.net/prosperousamerica/pages/4040/features/original/manufacturing_5.jpg?1512760258" alt="Manufacturing">
                <div class="carousel-caption">
                <h3>Manufacturing</h3>
                <p>all the things</p>
                </div>      
            </div>
            <div class="item">
                <img class="img-1" src="https://ast.porttechnology.org/wp-content/media/20190527053126/container_weighing_header_1280_800_84_s_c1.jpg" alt="Cargo">
                <div class="carousel-caption">
                <h3>Cargo Containers in Port</h3>
                <p>Ain't they purdy?</p>
                </div>      
            </div>
        </div>

        <!-- Left and right controls -->
        <a class="left carousel-control" href="#myCarousel" role="button" data-slide="prev">
        <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
        <span class="sr-only">Previous</span>
        </a>
        <a class="right carousel-control" href="#myCarousel" role="button" data-slide="next">
        <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
        <span class="sr-only">Next</span>
        </a>
    </div>
</body>
</html>