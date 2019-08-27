#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CARROS 30

typedef struct Carro {
	int carroExiste;
	char placa[7];
	char modelo[35];
	int ano;
	int estado; //0 - normal; 1 - bom; 2 - bosta;
	int quilometragem;
} TCarro;

typedef struct Pessoa {
	char oi;
} TPessoa;



int main(){
	int i;


	TCarro carrosLocacao[MAX_CARROS];
	for (i=0; i < MAX_CARROS; i++)
		carrosLocacao[i].carroExiste = 0;	
	


	carrosLocacao[0].ano = 2003;

	int programaRodando = 1;
	while(programaRodando){
		int opcaoMenu = 0;
		printf("\nBEM VINDO AO PROGRAMA.\n SELECIONE UMA OPÇÃO");
		printf("\n 1- Cadastrar ");
		printf("\n 2- Listar todos os carros ");
		printf("\n 3- Excluir ");

		printf("\nSua opção -> ");
		scanf("%d", &opcaoMenu);
		switch (opcaoMenu){

			//OPÇÃO: Cadastrar
			case 1: {

				int vaiSerEsse = -1;
				for (i=0; i < MAX_CARROS; i++){
					if (carrosLocacao[i].carroExiste == 0){ //Significa que este índice do vetor não está em uso.
						vaiSerEsse = i;
						i = MAX_CARROS+1;
					}
				}
				if (vaiSerEsse == -1){ //Vetor está cheio
					printf("\n ERRO: O vetor está cheio. Teste remover alguns itens.\n");
					break;
				} 

				printf("\nEntre com a placa [XXX1234] -> ");
				scanf("%s", carrosLocacao[vaiSerEsse].placa);
				printf("Entre com o modelo -> ");
				fflush(stdout);
				getchar();
				fgets(carrosLocacao[vaiSerEsse].modelo, 25, stdin);
				printf("Entre com o ano -> ");
				scanf("%d", &carrosLocacao[vaiSerEsse].ano);
				printf("Entre com a estado -> ");
				scanf("%d", &carrosLocacao[vaiSerEsse].estado);
				printf("Entre com a quilometragem -> ");
				scanf("%d", &carrosLocacao[vaiSerEsse].quilometragem);
				carrosLocacao[vaiSerEsse].carroExiste = 1;
				printf("Carro cadastrado com sucesso no banco de dados.");
				break;
			}


			//OPÇÃO: Listar todos os carros
			case 2: {

				printf("\n LISTA DE VEÍCULOS: \n");

				for (i=0; i < MAX_CARROS; i++){
					if (carrosLocacao[i].carroExiste == 1){ //Significa que este índice do vetor está em uso.
						printf("\n**********[ VEÍCULO %d ]**********", i);
						printf("\nPlaca: %c%c%c-%c%c%c%c", carrosLocacao[i].placa[0], carrosLocacao[i].placa[1], carrosLocacao[i].placa[2],carrosLocacao[i].placa[3],carrosLocacao[i].placa[4],carrosLocacao[i].placa[5],carrosLocacao[i].placa[6] );
						printf("\nModelo: %s ", carrosLocacao[i].modelo);
						printf("Ano: %d ", carrosLocacao[i].ano);
						printf("\nEstado: %d ", carrosLocacao[i].estado);
						printf("\nQuilometragem: %d ", carrosLocacao[i].quilometragem);

					}
				}

				break;
			}

			case 3: {

				int idDeletar;
				printf("\n Qual o ID do carro que você quer deletar? (999 cancela) -> \n");
				scanf("%d", &idDeletar);
				if (idDeletar >= 0 && idDeletar < MAX_CARROS){
					carrosLocacao[idDeletar].carroExiste = 0;
				} else {
					printf("\nERRO: ID [%d] não existe. Operação cancelada.\n", idDeletar);
				}

				break;
			}
			
			case 9: {
				programaRodando = 0;
				break;
			}


			default: {
				printf("\n Opção do menu não existe! Selecione outra. \n");
			}
		}

	}

	printf("\n BYE BYE \n");



	return 1;
}

