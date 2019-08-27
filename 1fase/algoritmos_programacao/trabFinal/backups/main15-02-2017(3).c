#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CARROS 50
#define MAX_CLIENTE 100

typedef struct Carro {
	int carroExiste; //	verifica se a posição do vetor está disponível
	char placa[7];
	char modelo[35]; // var[x] == x define a quantidade maxima de caracteres na string
	int ano;
	int estado; //0 - livre, 1 - locado
	int estadoTraducao;
	int quilometragem;
	int estaLocado;
	int locadoPara;	// para que Cliente este carro está locado
} TCarro;

typedef struct Cliente {
	int clienteExiste;	// verifica se a posição do vetor está disponível
	char nome[40];
	char cpf[12];
	char senha[6];
	char endereco[100];
	int carroLocado;	// que carro está locado por esse Cliente
} TCliente;

void menu(){
	printf("\n*************************");
	printf("\n* BEM VINDO AO PROGRAMA *");
	printf("\n*************************");
	printf("\n");
	printf("\n SELECIONE UMA OPÇÃO");
	printf("\n 1- Cadastrar carro");
	printf("\n 2- Listar todos os carros ");
	printf("\n 3- Excluir carro");
	printf("\n 4- Cadastrar cliente");
	printf("\n 5- Listar todos os clientes");
	printf("\n 6- Excluir cliente");
	printf("\n 7- Locação do carro");
	printf("\n 9- Desligar o sistema");
	printf("\n");
	printf("\nSua opção: ");
}

int main(){

	int i;

	//	encontra uma posição disponível do vetor, caso haja uma
	TCarro carrosLocacao[MAX_CARROS];
	for(i=0; i < MAX_CARROS; i++)
		carrosLocacao[i].carroExiste = 0;	

	TCliente clienteCadastro[MAX_CLIENTE];
	for(i=0; i < MAX_CLIENTE; i++)
		clienteCadastro[i].clienteExiste = 0;

/*
-----------------------------------------------------------------------------------
PRÉ-DEFININDO CLIENTES E CARROS PARA TESTE DURANTE O DESENVOLVIMENTO DO SISTEMA 
-----------------------------------------------------------------------------------
*/

char testNomeT[14] = "Trevor Philips";
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

strlen(clienteCadastro[2].nome) = 16;
strcpy(clienteCadastro[2].nome, testNomeF);
strlen(clienteCadastro[2].cpf) = 11;
strcpy(clienteCadastro[2].cpf, testCpfF);
strlen(clienteCadastro[2].senha) = 6;
strcpy(clienteCadastro[2].senha, testSenhaF);
strlen(clienteCadastro[2].endereco) = 14;
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

char testPlacaC[7] = "COM2007";
int testAnoC = 2007;
char testModeloC[6] = "Commet";
int testQuilometragemC = 90000;
int testEstadoC = 0;

strcpy(carrosLocacao[1].placa, testPlacaC);
carrosLocacao[0].ano = testAnoC;
strcpy(carrosLocacao[1].modelo, testModeloC);
carrosLocacao[1].quilometragem = testQuilometragemC;
carrosLocacao[1].estado = testEstadoC;

char testPlacaO[7] = "ORA2013";
int testAnoO = 2013;
char testModeloO[6] = "Oracle";
int testQuilometragemO = 30000;
int testEstadoO = 0;

strcpy(carrosLocacao[2].placa, testPlacaO);
carrosLocacao[0].ano = testAnoO;
strcpy(carrosLocacao[2].modelo, testModeloO);
carrosLocacao[2].quilometragem = testQuilometragemO;
carrosLocacao[2].estado = testEstadoO;

/*
-----------------------------------------------------------------------------------
PRÉ-DEFINIDOS CLIENTES E CARROS PARA TESTE DURANTE O DESENVOLVIMENTO DO SISTEMA 
-----------------------------------------------------------------------------------
*/

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
				scanf("%s", carrosLocacao[idCarro].placa);
				
				printf("Insira o modelo: ");
				scanf("%s", carrosLocacao[idCarro].modelo);
				getchar();
				
				printf("Insira o ano: ");
				scanf("%d", &carrosLocacao[idCarro].ano);
				
				printf("Insira a quilometragem: ");
				scanf("%d", &carrosLocacao[idCarro].quilometragem);
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
						printf("\n\n\n**********[ VEÍCULO %d ]**********", i);
						printf("\nPlaca: %c%c%c-%c%c%c%c", carrosLocacao[i].placa[0], carrosLocacao[i].placa[1], carrosLocacao[i].placa[2],carrosLocacao[i].placa[3],carrosLocacao[i].placa[4],carrosLocacao[i].placa[5],carrosLocacao[i].placa[6]);
						printf("\nModelo: %s", carrosLocacao[i].modelo);
						carrosLocacao[i].modelo[strlen(carrosLocacao[i].modelo) - 1] = '\0';
						printf("\nAno: %d ", carrosLocacao[i].ano);
						printf("\nQuilometragem: %d ", carrosLocacao[i].quilometragem);
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
						printf("\n*********************************\n\n\n");
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
				scanf("%s", clienteCadastro[idCliente].nome);
				getchar();

				int cpfLength;

				do{
					printf("Insira o CPF (somente números): ");
					scanf("%s", clienteCadastro[idCliente].cpf);
					getchar();
					cpfLength = strlen(clienteCadastro[idCliente].cpf);
					if(cpfLength != 11){
						printf("\nEntrada inválida, insira o CPF novamente: ");
					}
				}while(cpfLength != 11);

				printf("Crie uma senha de 6 dígitos: ");
				scanf("%s", clienteCadastro[idCliente].senha);
				getchar();
				
				printf("Insira seu endereço: ");
				scanf("%s", clienteCadastro[idCliente].endereco);
				getchar();
				
				clienteCadastro[idCliente].clienteExiste = 1;

				printf("Cliente cadastrado com sucesso no banco de dados.");
				break;

			}

			//OPÇÃO: Listar todos os clientes
			case 5: {

				printf("\n LISTA DE CLIENTES: \n");

				for (i=0; i < MAX_CLIENTE; i++){
					if (clienteCadastro[i].clienteExiste == 1){ //Significa que este índice do vetor está em uso.
						printf("\n**********[ CLIENTE %d ]**********", i);
						printf("\nNome: %s", clienteCadastro[i].nome);
						printf("\nCPF: %s ", clienteCadastro[i].cpf);
						printf("\nSenha: %c%c%c-%c%c%c", clienteCadastro[i].senha[0], clienteCadastro[i].senha[1], clienteCadastro[i].senha[2],clienteCadastro[i].senha[3],clienteCadastro[i].senha[4],clienteCadastro[i].senha[5]);
						printf("\nEndereço: %s ", clienteCadastro[i].endereco);
						if(clienteCadastro[i].carroLocado != 0){
							printf("\nCarro Locado: %d", carrosLocacao[i].estaLocado);
						}
						printf("\n*********************************\n");
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

				int idCliente, idCarro;

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
						carrosLocacao[idCarro].locadoPara = idCliente;
						carrosLocacao[idCarro].estaLocado = idCarro;
					}else{
						printf("\nERRO: Carro %s ID: [%d] já está locado. Operação cancelada.\n", carrosLocacao[idCarro].modelo, carrosLocacao[idCarro]);
						break;
					}
				} else {
					printf("\nERRO: ID [%d] não existe. Operação cancelada.\n", idCarro);
				}
				break;
			}

			// OPÇÃO: Desligar o sistema
			case 9: {
				printf("\nTem certeza que deseja desligar o sistema?");
				printf("\nInsira 1 para desligar ou 0 para cancelar: ");
				int desligar;
				scanf("%d", &desligar);
				if(desligar != 1 && desligar != 0){
					printf("\nERRO: Entrada inválida. Operação cancelada.\n");
				}else{
					programaRodando = 0;
				}
				break;
			}

			default: {
				printf("\n Opção do menu não existe! Selecione outra. \n");
			}
		}
	}

	printf("\nSystem shutting down...\n");


	return 1;
}

