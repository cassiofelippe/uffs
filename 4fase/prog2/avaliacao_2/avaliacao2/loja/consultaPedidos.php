<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="css/style.css">
	<title>addProduct</title>
</head>
	<div class="col-sm-12 col-md-12 col-lg-12 container text-center">

	<?php 

		$connection = mysqli_connect('localhost', 'admin', 'sys123', 'loja');

		mysqli_query($connection, "SET NAMES 'utf8'");
		mysqli_query($connection, 'SET character_set_connection=utf8');
		mysqli_query($connection, 'SET character_set_client=utf8');
		mysqli_query($connection, 'SET character_set_results=utf8');


		$query = "select codigo from pedidos";

		$codigos = mysqli_query($connection, $query);

		?> 

	  <form action="result.php">
	  	
	  	<div class="col-100">&nbsp;</div>
	  	<div class="col-100">
				Código do pedido
				<select name="codigo" id="codigo">
					<?php
						if(mysqli_num_rows($codigos) == 0){
							echo "Nenhum registro encontrado";
						}else{
							while ($codigo = mysqli_fetch_array($codigos)) {
								echo	"<option>".$codigo['codigo']."</option>";
					 		} 
						}
					?> 
				</select>

				<input type="submit" name="query">

	    </div>

		  <div class="col-100">&nbsp;</div>
	  
	  </form>

	</div>

	<div class="col-100">&nbsp;</div>

	<a href="index.php">Voltar à tela inicial</a>

</html>