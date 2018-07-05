<?php 
	
	$connection = mysqli_connect('localhost', 'admin', 'sys123', 'loja');

	mysqli_query($connection, "SET NAMES 'utf8'");
	mysqli_query($connection, 'SET character_set_connection=utf8');
	mysqli_query($connection, 'SET character_set_client=utf8');
	mysqli_query($connection, 'SET character_set_results=utf8');
	
	$query = "select * from pedidos where codigo = {$_GET['codigo']}";

	$pedidos = mysqli_query($connection, $query);


	if(mysqli_num_rows($pedidos) == 0){
		echo "Nenhum pedido encontrado para esse código";
	}else{
		while ($pedido = mysqli_fetch_array($pedidos)) {
			echo "
						<tr>
							<td> Código: ".$pedido['codigo']."</td><br/>
							<td> Nome do Cliente: ".$pedido['nomeCliente']."</td><br/>
							<td> Email: ".$pedido['email']."</td><br/>
							<td> Tipo do Evento: ".$pedido['tipoEvento']."</td><br/>
							<td> Nome do Evento: ".$pedido['nomeEvento']."</td><br/>
							<td> Mês e Ano: ".$pedido['mesAno']."</td><br/>
							<td> Quantidade P: ".$pedido['qtP']."</td><br/>
							<td> Quantidade M: ".$pedido['qtM']."</td><br/>
							<td> Quantidade G: ".$pedido['qtG']."</td><br/>
							<td> Quantidade GG: ".$pedido['qtGG']."</td><br/>
							<td> Cor: ".$pedido['cor']."</td><br/>
							<td> Nome do Arquivo: ".$pedido['nomeArquivo']."</td><br/>
							<td> Tipo da Gola: ".$pedido['tipoGola']."</td><br/>
							<td> Adicional Nome: ".$pedido['adicionalNome']."</td><br/>
							<td> Adicional Arte: ".$pedido['adicionalArte']."</td><br/>
							<td> Adicional Punho: ".$pedido['adicionalPunho']."</td><br/>
							<td> Data da Retirada: ".$pedido['dataRetirada']."</td><br/>
							<td> Hora da Retirada: ".$pedido['horaRetirada']."</td><br/>
							<td> Observações: ".$pedido['observacoes']."</td><br/>
							<td> Valor Total: ".$pedido['totalPedido']."</td><br/>
						</tr>
					";
 		} 
	}

	mysqli_close($connection);
?>

<div class="col-100">&nbsp;</div>

<a href="consultaPedidos.php">Voltar à consulta de pedidos</a>
