<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="css/style.css">
	<title>addProduct</title>
</head>
	<div class="col-sm-12 col-md-12 col-lg-12 container text-center">
	<?php 

		$nomeCliente = $_GET["nome-cliente"];
		$email = $_GET["email-cliente"];
		$tipoEvento = $_GET["tipo-evento"];
		$nomeEvento = $_GET["nome-evento"];
		$mesAno = $_GET["data-evento"];
		$qtP = $_GET["quantidade-p"];
		$qtM = $_GET["quantidade-m"];
		$qtG = $_GET["quantidade-g"];
		$qtGG = $_GET["quantidade-gg"];
		$cor = $_GET["cor-tecido"];
		$nomeArquivo = $_GET["arquivo"];
		$tipoGola = $_GET["tipo-gola"];
		$adicionalNome = $_GET["nome-camisa"] == "on" ? true : false;
		$adicionalArte = $_GET["miniatura-camisa"] == "on" ? true : false;
		$adicionalPunho = $_GET["acabamento-camisa"] == "on" ? true : false;
		$dataRetirada = $_GET["data-evento"];
		$horaRetirada = $_GET["hora-evento"];
		$observacoes = "nada";
		$totalPedido = $_GET["total-pedido"];
		

		$connection = mysqli_connect('localhost', 'admin', 'sys123', 'loja');
		mysqli_query($connection, "SET NAMES 'utf8'");
		mysqli_query($connection, 'SET character_set_connection=utf8');
		mysqli_query($connection, 'SET character_set_client=utf8');
		mysqli_query($connection, 'SET character_set_results=utf8');

		$query = "
							insert into pedidos
							(nomeCliente, email, tipoEvento, nomeEvento, mesAno, qtP, qtM, qtG, qtGG, cor, nomeArquivo, tipoGola, adicionalNome, adicionalArte, adicionalPunho, dataRetirada, horaRetirada, observacoes, totalPedido)
							values
							('{$nomeCliente}', '{$email}', '{$tipoEvento}', '{$nomeEvento}', '{$mesAno}', {$qtP}, {$qtM}, {$qtG}, {$qtGG}, '{$cor}', '{$nomeArquivo}', {$tipoGola}, {$adicionalNome}, {$adicionalArte}, {$adicionalPunho}, '{$dataRetirada}', '{$horaRetirada}', '{$observacoes}', {$totalPedido})
							";
		// $query = "select * from pedidos";
		mysqli_query($connection, $query);
	?>
		
		<p class="alert-success">
			<ul>
				<!-- <li> <?php echo $codigo; ?> </li> -->
				<li> nome: <?php echo $nomeCliente; ?> </li>
				<li> email: <?php echo $email; ?> </li>
				<li> nome evento: <?php echo $nomeEvento; ?> </li>
				<li> tipo evento: <?php echo $tipoEvento; ?> </li>
				<li> mesAno: <?php echo $mesAno; ?> </li>
				<li> qtP: <?php echo $qtP; ?> </li>
				<li> qtM: <?php echo $qtM; ?> </li>
				<li> qtG: <?php echo $qtG; ?> </li>
				<li> qtGG: <?php echo $qtGG; ?> </li>
				<li> cor: <?php echo $cor; ?> </li>
				<li> nomeArquivo: <?php echo $nomeArquivo; ?> </li>
				<li> tipoGola: <?php echo $tipoGola; ?> </li>
				<li> adicionalNome: <?php echo $adicionalNome; ?> </li>
				<li> adicionalArte: <?php echo $adicionalArte; ?> </li>
				<li> adicionalPunho: <?php echo $adicionalPunho; ?> </li>
				<li> dataRetirada: <?php echo $dataRetirada; ?> </li>
				<li> horaRetirada: <?php echo $horaRetirada; ?> </li>
				<li> observacoes: <?php echo $observacoes; ?> </li>
				<li> totalPedido: <?php echo $totalPedido; ?> </li>
			</ul>
		</p>

	<?php		
		mysqli_close($connection);
	?>
	</div>


	<div class="col-100">&nbsp;</div>

	<a href="index.php">Voltar à tela inicial</a>

</html>