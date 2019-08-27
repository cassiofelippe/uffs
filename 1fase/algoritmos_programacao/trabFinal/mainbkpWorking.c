#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CARROS 50
#define MAX_CLIENTE 100
#define MAX_FILIAL 30

typedef struct Carro {
	int carroExiste; //	verifica se a posição do vetor está disponível
	char placa[8];
	char modelo[35]; // var[x] == x define a quantidade maxima de caracteres na string
	int ano;
	int estado; //0 - livre, 1 - locado
	int estadoTraducao;
	int quilometragem;
	int estaLocado;
	int locadoPara;	// para que Cliente este carro está locado
	int filialCarro;
} TCarro;

typedef struct Cliente {
	int clienteExiste;	// verifica se a posição do vetor está disponível
	char nome[40];
	char cpf[12];
	char senha[6];
	char endereco[100];
	int carroLocado;	// que carro está locado por esse Cliente
	int filialCliente;
} TCliente;

typedef struct Filial {
	int filialExiste;
	char nome[40];

} TFilial;

void menu(){
	printf("\n*************************");
	printf("\n* BEM VINDO AO PROGRAMA *");
	printf("\n*************************");
	printf("\n");
	printf("\n SELECIONE UMA OPÇÃO");
	printf("\n 1- Cadastro de carros");
	printf("\n 2- Listar todos os carros ");
	printf("\n 3- Exclusão de carros");
	printf("\n 4- Cadastro de clientes");
	printf("\n 5- Listar todos os clientes");
	printf("\n 6- Exclusão de clientes");
	printf("\n 7- Locação de carros");
	printf("\n 8- Cadastro de filiais");
	printf("\n 9- Listar todas as filiais");
	printf("\n 0- Desligar o sistema");
	printf("\n");
	printf("\nSua opção: ");
}

int main(){

	int i;

	//	seta 0 para todas as posições dos vetores, ou seja, todas livres
	TCarro carrosLocacao[MAX_CARROS];
	for(i=0; i < MAX_CARROS; i++)
		carrosLocacao[i].carroExiste = 0;	

	TCliente clienteCadastro[MAX_CLIENTE];
	for(i=0; i < MAX_CLIENTE; i++)
		clienteCadastro[i].clienteExiste = 0;

	TFilial filialCadastro[MAX_FILIAL];
	for(i=0; i < MAX_FILIAL; i++)
		filialCadastro[i].filialExiste = 0;

/*
-----------------------------------------------------------------------------------
PRÉ-DEFININDO CLIENTES E CARROS PARA TESTE DURANTE O DESENVOLVIMENTO DO SISTEMA 
-----------------------------------------------------------------------------------
*/

/*char testNomeT[14] = "Trevor Philips";
char testCpfT[11] = "11122233344";
char testSenhaT[6] = "123456";
char testEnderecoT[12] = "Sandy Shores";

strcpy(clienteCadastro[0].nome, testNomeT);
strcpy(clienteCadastro[0].cpf, testCpfT);
strcpy(clienteCadastro[0].senha, testSenhaT);
strcpy(clienteCadastro[0].endereco, testEnderecoT);
clienteCadastro[0].carroLocado = 0;
clienteCadastro[0].clienteExiste = 1;

char testNomeM[16] = "Michael De Santa";
char testCpfM[11] = "55566677788";
char testSenhaM[6] = "654321";
char testEnderecoM[14] = "Rockford Hills";

strcpy(clienteCadastro[1].nome, testNomeM);
strcpy(clienteCadastro[1].cpf, testCpfM);
strcpy(clienteCadastro[1].senha, testSenhaM);
strcpy(clienteCadastro[1].endereco, testEnderecoM);
clienteCadastro[1].carroLocado = 0;
clienteCadastro[1].clienteExiste = 1;

char testNomeF[16] = "Franklin Clinton";
char testCpfF[11] = "99900011122";
char testSenhaF[6] = "012345";
char testEnderecoF[14] = "Vinewood Hills";

// resolver problema de lixo na string
sizeof(clienteCadastro[2].nome, 16);
strcpy(clienteCadastro[2].nome, testNomeF);
sizeof(clienteCadastro[2].cpf, 11);
strcpy(clienteCadastro[2].cpf, testCpfF);
sizeof(clienteCadastro[2].senha, 6);
strcpy(clienteCadastro[2].senha, testSenhaF);
sizeof(clienteCadastro[2].endereco, 14);
strcpy(clienteCadastro[2].endereco, testEnderecoF);
clienteCadastro[2].carroLocado = 0;
clienteCadastro[2].clienteExiste = 1;

//---------------------------------------------------------------------------------

char testPlacaI[7] = "INF2008";
int testAnoI = 2008;
char testModeloI[8] = "Infernus";
int testQuilometragemI = 80000;
int testEstadoI = 0;

strcpy(carrosLocacao[0].placa, testPlacaI);
carrosLocacao[0].ano = testAnoI;
strcpy(carrosLocacao[0].modelo, testModeloI);
carrosLocacao[0].quilometragem = testQuilometragemI;
carrosLocacao[0].estado = testEstadoI;
carrosLocacao[0].carroExiste = 1;
carrosLocacao[0].filialCarro = 0;

char testPlacaC[7] = "COM2007";
int testAnoC = 2007;
char testModeloC[6] = "Commet";
int testQuilometragemC = 90000;
int testEstadoC = 0;

strcpy(carrosLocacao[1].placa, testPlacaC);
carrosLocacao[1].ano = testAnoC;
strcpy(carrosLocacao[1].modelo, testModeloC);
carrosLocacao[1].quilometragem = testQuilometragemC;
carrosLocacao[1].estado = testEstadoC;
carrosLocacao[1].carroExiste = 1;
carrosLocacao[1].filialCarro = 0;

char testPlacaO[7] = "ORA2013";
int testAnoO = 2013;
char testModeloO[6] = "Oracle";
int testQuilometragemO = 30000;
int testEstadoO = 0;

strcpy(carrosLocacao[2].placa, testPlacaO);
carrosLocacao[2].ano = testAnoO;
strcpy(carrosLocacao[2].modelo, testModeloO);
carrosLocacao[2].quilometragem = testQuilometragemO;
carrosLocacao[2].estado = testEstadoO;
carrosLocacao[2].carroExiste = 1;
carrosLocacao[2].filialCarro = 0;
*/
/*
-----------------------------------------------------------------------------------
PRÉ-DEFINIDOS CLIENTES E CARROS PARA TESTE DURANTE O DESENVOLVIMENTO DO SISTEMA 
-----------------------------------------------------------------------------------
*/
	
	// Definindo filial Matriz
	char filialMatrizNome[7] = "Matriz";
	strcpy(filialCadastro[0].nome, filialMatrizNome);
	filialCadastro[0].filialExiste = 1;

	int programaRodando = 1;
	while(programaRodando){
		int opcaoMenu = 0;

		menu();

		scanf("%d", &opcaoMenu);

		switch (opcaoMenu){

			//OPÇÃO: Cadastrar carros
			case 1: {

				int idCarro = -1;
				for (i=0; i < MAX_CARROS; i++){
					if (carrosLocacao[i].carroExiste == 0){ //Significa que este índice do vetor não está em uso.
						idCarro = i;
						i = MAX_CARROS+1;
					}
				}
				if (idCarro == -1){ //Vetor está cheio
					printf("\n ERRO: O vetor está cheio. Tente remover alguns carros.\n");
					break;
				} 

				printf("\nInsira a placa [XXX1234]: ");
				getchar();
				fgets(carrosLocacao[idCarro].placa, 8, stdin);
				getchar();

				printf("Insira o modelo: ");
				fgets(carrosLocacao[idCarro].modelo, 35, stdin);
				
				printf("Insira o ano: ");
				scanf("%d", &carrosLocacao[idCarro].ano);
				
				printf("Insira a quilometragem: ");
				scanf("%d", &carrosLocacao[idCarro].quilometragem);

				// Seleciona a filial, caso não tenha cadastrado, usar filial Matriz
				printf("Insira o id da filial (Matriz - 0): ");
				scanf("%d", &carrosLocacao[idCarro].filialCarro);


				carrosLocacao[idCarro].carroExiste = 1;

				// Define carro como livre para ser locado	
				carrosLocacao[idCarro].estado = 0;

				printf("Carro cadastrado com sucesso no 'banco de dados'.\n");
				break;
			}


			//OPÇÃO: Listar todos os carros
			case 2: {

				printf("\n LISTA DE VEÍCULOS: \n");

				for (i=0; i < MAX_CARROS; i++){
					if (carrosLocacao[i].carroExiste == 1){ //Significa que este índice do vetor está em uso.
						printf("\n**********[ VEÍCULO %d ]**********", i);
						printf("\nPlaca: %c%c%c-%c%c%c%c", carrosLocacao[i].placa[0], carrosLocacao[i].placa[1], carrosLocacao[i].placa[2],carrosLocacao[i].placa[3],carrosLocacao[i].placa[4],carrosLocacao[i].placa[5],carrosLocacao[i].placa[6]);
						printf("\nModelo: %s", carrosLocacao[i].modelo);
						printf("Ano: %d ", carrosLocacao[i].ano);
						printf("\nQuilometragem: %d ", carrosLocacao[i].quilometragem);
						printf("\nFilial: %d", carrosLocacao[i].filialCarro);
						if(carrosLocacao[i].estaLocado){
							int traducaoCliente = carrosLocacao[i].locadoPara;
							char clienteTraduzido[41];
							
							// Dizer para qual cliente esse carro está locado
							for(int j = 0; j < sizeof(clienteCadastro); j++){
								if(i == traducaoCliente){
									strcpy(clienteTraduzido, clienteCadastro[i].nome);
								}
							}
							printf("\nEstado: Locado para %s", clienteTraduzido);
						}else{
							printf("\nEstado: Livre");
						}
						printf("\n*********************************\n");
					}
				}

				break;
			}

			// OPÇÃO: Deletar carros
			case 3: {

				int idDeletarCarro;
				printf("\n Qual o ID do carro que você quer deletar? (999 cancela): \n");
				scanf("%d", &idDeletarCarro);
				if (idDeletarCarro >= 0 && idDeletarCarro < MAX_CARROS){
					carrosLocacao[idDeletarCarro].carroExiste = 0;
				} else {
					printf("\nERRO: ID [%d] não existe. Operação cancelada.\n", idDeletarCarro);
				}

				break;
			}
			
			// OPÇÃO: Cadastrar clientes
			case 4: {

				int idCliente = -1;
				for (i=0; i < MAX_CLIENTE; i++){
					if (clienteCadastro[i].clienteExiste == 0){ //Significa que este índice do vetor não está em uso.
						idCliente = i;
						i = MAX_CLIENTE + 1;
					}
				}
				if (idCliente == -1){ //Vetor está cheio
					printf("\n ERRO: O vetor está cheio. Tente remover alguns clientes.\n");
					break;
				} 

				printf("\nInsira o nome: ");
				fflush(stdout);
				getchar();
				fgets(clienteCadastro[idCliente].nome, 40, stdin);

				int cpfLength;

				do{
					printf("Insira o CPF (somente números): ");
					fflush(stdout);
					fgets(clienteCadastro[idCliente].cpf, 12, stdin);
					getchar();
					cpfLength = strlen(clienteCadastro[idCliente].cpf);
					if(cpfLength != 11){
						printf("\nERRO: Entrada inválida. Tente novamente... ");
					}
				}while(cpfLength != 11);

				printf("Crie uma senha de 6 dígitos: ");
				fgets(clienteCadastro[idCliente].senha, 6, stdin);
				getchar();
				
				printf("Insira seu endereço: ");
				getchar();
				fgets(clienteCadastro[idCliente].endereco, 100, stdin);

				clienteCadastro[idCliente].clienteExiste = 1;

				printf("Cliente cadastrado com sucesso no 'banco de dados'.\n");
				break;

			}

			//OPÇÃO: Listar todos os clientes
			case 5: {

				printf("\n LISTA DE CLIENTES: \n");

				for (i=0; i < MAX_CLIENTE; i++){
					if (clienteCadastro[i].clienteExiste == 1){ //Significa que este índice do vetor está em uso.
						printf("\n**********[ CLIENTE %d ]**********", i);
						printf("\nNome: %s", clienteCadastro[i].nome);
						printf("CPF: %s ", clienteCadastro[i].cpf);
						printf("\nEndereço: %s ", clienteCadastro[i].endereco);
						if(clienteCadastro[i].carroLocado != 0){
							printf("\nCarro Locado: %d", carrosLocacao[i].estaLocado);
						}
						printf("*********************************\n");
					}
				}

				break;
			}

			// OPÇÃO: Excluir clientes
			case 6: {

				int idDeletarCliente;
				printf("\n Qual o ID do cliente que você quer deletar? (999 cancela): \n");
				scanf("%d", &idDeletarCliente);
				if (idDeletarCliente >= 0 && idDeletarCliente < MAX_CLIENTE){
					clienteCadastro[idDeletarCliente].clienteExiste = 0;
				} else {
					printf("\nERRO: ID [%d] não existe. Operação cancelada.\n", idDeletarCliente);
				}

				break;
			}

			// OPÇÃO: Locar carro para cliente
			case 7: {

				int idCliente, idCarro, idFilial;
				char senhaUsuario[6];

				printf("\nInsira o ID da filial que você está: ");
				scanf("%d", &idFilial);
				printf("\nInsira o ID do cliente: ");
				scanf("%d", &idCliente);
				if(clienteCadastro[idCliente].carroLocado == 1){
					printf("\nERRO: O cliente %s já tem um carro locado. Operação cancelada.\n", clienteCadastro[idCliente].nome);
					break;
				}

				printf("\nInsira o ID do carro: ");
				scanf("%d", &idCarro);
				if (idCarro >= 0 && idCarro < MAX_CARROS){
					if(carrosLocacao[idCarro].estaLocado == 0){
						if(carrosLocacao[idCarro].filialCarro != idFilial){
							printf("\nERRO: Carro não está disponível nessa filial. Operação cancelada.");
							break;
						}

						printf("\nInsira a senha do usuário: ");
						getchar();
						fgets(senhaUsuario, 6, stdin);
						if(strcmp(senhaUsuario, clienteCadastro[idCliente].senha) == 0){
							carrosLocacao[idCarro].locadoPara = idCliente;
							carrosLocacao[idCarro].estaLocado = 1;
							printf("\nCarro %d - %s alugado com sucesso pelo Cliente %d - %s.", carrosLocacao[idCarro], carrosLocacao[idCarro].modelo, clienteCadastro[idCliente], clienteCadastro[idCliente].nome);
						}else{
							printf("\nERRO: Senha incorreta. Operação cancelada.");
							break;
						}
					}else{
						printf("\nERRO: Carro %d - %s já está locado. Operação cancelada.\n", carrosLocacao[idCarro], carrosLocacao[idCarro].modelo);
						break;
					}
				} else {
					printf("\nERRO: ID [%d] não existe. Operação cancelada.\n", idCarro);
				}

				break;
			}

			// OPÇÃO: Cadastro de filiais
			case 8: {
				int idFilial;

				for (i=0; i < MAX_FILIAL; i++){
					if (filialCadastro[i].filialExiste == 0){ //Significa que este índice do vetor não está em uso.
						idFilial = i;
						i = MAX_FILIAL + 1;
					}
				}
				if (idFilial == -1){ //Vetor está cheio
					printf("\n ERRO: O vetor está cheio. Tente remover alguns clientes.\n");
					break;
				} 

				printf("\nInsira o nome da filial: ");
				getchar();
				fgets(filialCadastro[idFilial].nome, 40, stdin);

				filialCadastro[idFilial].filialExiste = 1;

				printf("Filial cadastrada com sucesso no 'banco de dados'.\n");

				break;
			}

			// OPÇÃO: Listar filiais
			case 9: {
				printf("\n LISTA DE FILIAIS: \n");

				for (i=0; i < MAX_FILIAL; i++){
					if (filialCadastro[i].filialExiste == 1){ //Significa que este índice do vetor está em uso.
						printf("\n**********[ FILIAL %d ]**********", i);
						printf("\nNome: %s", filialCadastro[i].nome);
						printf("\n*********************************\n");
					}
				}
				break;
			}

			// OPÇÃO: Desligar o sistema
			case 0: {
				printf("\nTem certeza que deseja desligar o sistema?");
				printf("\nInsira 1 para desligar ou 0 para cancelar: ");
				int desligar;
				scanf("%d", &desligar);
				if(desligar != 1 && desligar != 0){
					printf("\nERRO: Entrada inválida. Operação cancelada.\n");
				}else{
					if(desligar == 1){
						programaRodando = 0;
					}else{
						break;
					}
				}
				break;
			}

			default: {
				printf("\n Opção do menu não existe! Selecione outra. \n");
				break;
			}
		}
	}

	printf("\nSystem shutting down...\n");


	return 1;
}

