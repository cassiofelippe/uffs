#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CARROS 50
#define MAX_CLIENTE 100

typedef struct Carro {
	int carroExiste;
	char placa[7];
	char modelo[35];
	int ano;
	int estado; //0 - livre, 1 - locado
	int estadoTraducao;
	int quilometragem;
	int estaLocado;
	int locadoPara;
} TCarro;

typedef struct Cliente {
	int clienteExiste;
	char nome[40];  // var[x] == x define a quantidade de caracteres na string
	char cpf[12];
	char senha[6];
	char endereco[100];
	int carroLocado;
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

	TCarro carrosLocacao[MAX_CARROS];
	for(i=0; i < MAX_CARROS; i++)
		carrosLocacao[i].carroExiste = 0;	

	carrosLocacao[0].ano = 2003;

	TCliente clienteCadastro[MAX_CLIENTE];
	for(i=0; i < MAX_CLIENTE; i++)
		clienteCadastro[i].clienteExiste = 0;

/*
	-----------------------------------------------------------------------------------
		PRÉ-DEFININDO CLIENTES E CARROS PARA TESTE DURANTE O DESENVOLVIMENTO DO SISTEMA 
	-----------------------------------------------------------------------------------
*/

	char testNome[14] = "Trevor Philips";
	char testCpf[11] = "11122233344";
	char testSenha[6] = "123456";
	char testEndereco[12] = "Sandy Shores";

	strcpy(clienteCadastro[0].nome, testNome);
	strcpy(clienteCadastro[0].cpf, testCpf);
	strcpy(clienteCadastro[0].senha, testSenha);
	strcpy(clienteCadastro[0].endereco, testEndereco);
	clienteCadastro[0].carroLocado = 0;

	testNome[16] = "Michael De Santa";
	testCpf[11] = "55566677788";
	testSenha[6] = "654321";
	testEndereco[14] = "Rockford Hills";

	strcpy(clienteCadastro[1].nome, testNome);
	strcpy(clienteCadastro[1].cpf, testCpf);
	strcpy(clienteCadastro[1].senha, testSenha);
	strcpy(clienteCadastro[1].endereco, testEndereco);
	clienteCadastro[1].carroLocado = 0;

	testNome[16] = "Franklin Clinton";
	testCpf[11] = "99900011122";
	testSenha[6] = "012345";
	testEndereco[14] = "Vinewood Hills";

	strcpy(clienteCadastro[2].nome, testNome);
	strcpy(clienteCadastro[2].cpf, testCpf);
	strcpy(clienteCadastro[2].senha, testSenha);
	strcpy(clienteCadastro[2].endereco, testEndereco);
	clienteCadastro[2].carroLocado = 0;
	
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

			//OPÇÃO: Cadastrar
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
						printf("CPF: %s ", clienteCadastro[i].cpf);
						printf("\nSenha: %c%c%c-%c%c%c", clienteCadastro[i].senha[0], clienteCadastro[i].senha[1], clienteCadastro[i].senha[2],clienteCadastro[i].senha[3],clienteCadastro[i].senha[4],clienteCadastro[i].senha[5]);
						printf("\nEndereço: %s ", clienteCadastro[i].endereco);
						printf("\n*********************************\n");
					}
				}

				break;
			}

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

			case 7: {

				int idCliente, idCarro;

				printf("\nInsira o ID do cliente: ");
				scanf("%d", &idCliente);
				if(clienteCadastro[idCliente].carroLocado == 1){
					printf("\nERRO: O cliente %s já tem um carro locado. Operação cancelada.\n", clienteCadastro[idCliente].nome);
					break;
				}
				clienteCadastro[idCliente].carroLocado = 1;
				printf("\nInsira o ID do carro: ");
				scanf("%d", &idCarro);
				if (idCarro >= 0 && idCarro < MAX_CARROS){
					if(carrosLocacao[idCarro].estaLocado == 0){
						carrosLocacao[idCarro].locadoPara = idCliente;
						carrosLocacao[idCarro].estaLocado = 1;
					}else{
						printf("\nERRO: Carro %s ID: [%d] já está locado. Operação cancelada.\n", carrosLocacao[idCarro].modelo, carrosLocacao[idCarro]);
						break;
					}
				} else {
					printf("\nERRO: ID [%d] não existe. Operação cancelada.\n", idCarro);
				}
				break;
			}

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

