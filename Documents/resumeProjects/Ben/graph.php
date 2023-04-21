<?php
	$dataPoints1 = array(
		array()
	);
	$dataPoints2 = array(
		array()
	);
	$income = htmlspecialchars($_POST["inputIncome"]);
	$priceX = htmlspecialchars($_POST["inputPriceX"]);
	$priceY = htmlspecialchars($_POST["inputPriceY"]);
	$goodsXUtility = htmlspecialchars($_POST["inputGoodX"]);
	$goodsYUtility = htmlspecialchars($_POST["inputGoodY"]);

	$x = $income / ($priceX * (1 + $goodsYUtility / $goodsXUtility));
	$y = ($income * $goodsYUtility) / ($priceY * ($goodsXUtility + $goodsYUtility));
	$z = pow($x, $goodsXUtility) * pow($y, $goodsYUtility);

	function L($x, $z, $goodsXUtility, $goodsYUtility) {
		return ((pow($z, (1/$goodsYUtility)))/(pow($x, ($goodsXUtility/$goodsYUtility))));
	}
	
	function C($income, $priceX, $x, $priceY) { 
		return (($income - $priceX * $x) / $priceY);
	}

	$xFloor = floor($x);
	$yFloor = floor($y);

	$totalSpendX = $priceX * $x;
	$totalSpendY = $priceY * $y;
	$totalSpendXRounded = $priceX * $xFloor;
	$totalSpendYRounded = $priceY * $yFloor;

	$totalSpend = $totalSpendX + $totalSpendY;
	$totalSpendRounded = $totalSpendXRounded + $totalSpendYRounded;
	
	for ($i = 0; $i < 100; $i++)
	{
		$dataPoints1[] = L($i, $z, $goodsXUtility, $goodsYUtility);
		$dataPoints2[] = C($income, $priceX, $i--, $priceY);
	}

	echo "Data points 1 is $dataPoints1";
	echo "Data points 2 is $dataPoints2";
?>
<!DOCTYPE HTML>
<html>
<head> 
<meta charset="UTF-8"> 
<script>
	window.onload = function () {
	
	var chart = new CanvasJS.Chart("chartContainer", {
		animationEnabled: true,
		title:{
			text: "Dynamic Viscosity Vs Density over Temperature of Water"
		},
		axisX:{
			title: "Temperature [°C]"
		},
		axisY:{
			title: "Dynamic Viscosity [mPa.s]",
			titleFontColor: "#4F81BC",
			lineColor: "#4F81BC",
			labelFontColor: "#4F81BC",
			tickColor: "#4F81BC"
		},
		axisY2:{
			title: "Density [g/cm³]",
			titleFontColor: "#C0504E",
			lineColor: "#C0504E",
			labelFontColor: "#C0504E",
			tickColor: "#C0504E",
			includeZero: false
		},
		legend:{
			cursor: "pointer",
			dockInsidePlotArea: true,
			itemclick: toggleDataSeries
		},
		data: [{
			type: "line",
			name: "Dynamic Viscosity",
			markerSize: 0,
			toolTipContent: "Temperature: {x} °C <br>{name}: {y} mPa.s",
			showInLegend: true,
			dataPoints: <?php echo json_encode($dataPoints1, JSON_NUMERIC_CHECK); ?>
		},{
			type: "line",
			axisYType: "secondary",
			name: "Density",
			markerSize: 0,
			toolTipContent: "Temperature: {x} °C <br>{name}: {y} g/cm³",
			showInLegend: true,
			dataPoints: <?php echo json_encode($dataPoints2, JSON_NUMERIC_CHECK); ?>
		}]
	});
	chart.render();
	
	function toggleDataSeries(e){
		if (typeof(e.dataSeries.visible) === "undefined" || e.dataSeries.visible) {
			e.dataSeries.visible = false;
		}
		else{
			e.dataSeries.visible = true;
		}
		chart.render();
	}
}
</script>
</head>
<body>
<div id="chartContainer" style="height: 370px; width: 100%;">
	<table class="table table-striped">
		<thead>
			<tr>
				<th><?php echo "Title";?></th>
				<th><?php echo "Results/Input"?></th>
			</tr>
		</thead>
		<tbody>
			<tr>
				<td><?php echo "Income";?></td>
				<td><?php echo "$$income";?></td>
			</tr>
			<tr>
				<td><?php echo "Price of X";?></td>
				<td><?php echo "$$priceX";?></td>
			</tr>
			<tr>
				<td><?php echo "Price of Y";?></td>
				<td><?php echo "$$priceY";?></td>
			</tr>
			<tr>
				<td><?php echo "Utility for X goods";?></td>
				<td><?php echo "$goodsXUtility";?></td>
			</tr>
			<tr>
				<td><?php echo "Utility for Y goods";?></td>
				<td><?php echo "$goodsYUtility";?></td>
			</tr>
			<tr>
				<td><?php echo "The total cost of goods X";?></td>
				<td><?php echo "$$totalSpendX";?></td>
			</tr>
			<tr>
				<td><?php echo "The total cost of goods Y";?></td>
				<td><?php echo "$$totalSpendY";?></td>
			</tr>
			<tr>
				<td><?php echo "Quantity of X to purchase";?></td>
				<td><?php echo "$xFloor";?></td>
			</tr>
			<tr>
				<td><?php echo "Quantity of Y to purchase";?></td>
				<td><?php echo "$yFloor";?></td>
			</tr>
			<tr>
				<td><?php echo "The total cost overall";?></td>
				<td><?php echo "$$totalSpendRounded out of $$totalSpend";?></td>
			</tr>
		</tbody>
	</table>
</div>
<script src="https://canvasjs.com/assets/script/canvasjs.min.js"></script>
</body>
</html> 