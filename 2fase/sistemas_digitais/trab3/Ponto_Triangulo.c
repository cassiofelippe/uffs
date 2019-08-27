/*UNIVERSIDADE FEDERAL DA FRONTEIRA SUL
 PROFESSOR: EMILIO WUERGES
 ALUNO: FELIPE AUGUSTO DA SILVA
 EMAIL: felipeaugustosilva94@gmail.com
 DESENVOLVIDO NO AMBIENTE LINUX */

/*TRABALHO 3 - VERIFICAR SE PONTO ESTÁ NO TRIÂNGULO*/


#include <stdio.h>
#include <stdlib.h>

//Declarando Funções
int tri_area(int *x1, int *y1, int *x2, int *y2, int  *x3, int *y3);
void test (int *aux);
void printa ( int x, int y, int x1, int y1, int x2, int y2, int x3, int y3 );
void sair (void);

int main () {
	  initscr();
	int x1, y1, x2, y2, x3, y3, x, y, arto, arpo = 0, aux;

	//coordenadas dos pontos e do triangulo
	FILE *coordenadas;
	//resultado
	FILE *result;

	coordenadas = fopen("coordenadas.txt","r");
	result = fopen("resultado_C.txt","w");
	if(coordenadas == NULL){
   printf("Não foi possivel abrir o arquivo\n");
   exit(1);
  }

	//printf("Lendo as coordenadas do triangulo\n");
	//LENDO AS COORDENADAS DO TRIANGULO
	fscanf(coordenadas,"%d %d %d %d %d %d \n", &x1, &y1, &x2, &y2, &x3, &y3);

	//printf("Lendo a coordenada do ponto a ser testado\n");
	//LENDO A COORDENADA DO PONTO
	fscanf(coordenadas,"%d %d", &x, &y);


	arto = tri_area(&x1, &y1, &x2, &y2, &x3, &y3);
	test(&arto);

	aux = tri_area(&x1, &y1, &x2, &y2, &x, &y);
	test(&aux);

	arpo = aux;

	aux = tri_area(&x1, &y1, &x, &y, &x3, &y3);
	test(&aux);

	arpo = arpo+aux;

	aux = tri_area(&x, &y, &x2, &y2, &x3, &y3);
	test(&aux);

	arpo = arpo+aux;

	printa ( x, y, x1, y1, x2, y2, x3, y3 );

	//COMPARA A AREA DO TRIANGULO TOTAL COM A SOMA DAS AREAS DOS TRIANGULOS RELATIVOS AO PONTO TESTADO
	if(arpo == arto){
		fprintf(result,("Ponto esta no triangulo\n"));
		move(0,0);
		printw("Ponto esta no triangulo\n");
	}else{
		fprintf(result,("Ponto não esta no triangulo\n"));
		move(0,0);
		printw("Ponto nao esta no triangulo\n");
	}

	refresh();    //Atualiza a tela
	getch();      //Fica esperando que o usuário aperte alguma tecla

	fclose(coordenadas);
  fclose(result);
	sair();    // Sai do programa
return 0;
}

//FUNÇÃO QUE CALCULA A AREA DO TRIANGULO
int tri_area(int *x1, int *y1, int *x2, int *y2, int  *x3, int *y3){
	int area;

	area = (*x1**y2+*x2**y3+*y1**x3)-(*x3**y2+*x2**y1+*y3**x1);

return area;
}

//TROCANDO O SINAL DA AREA DE UM TRIANGULO RELATIVO CASO A MESMA SEJA MENOR QUE ZERO
void test (int *aux) {

	if(*aux < 0){

		*aux = -1**aux;

	}
}

//Imprime na tela
void printa ( int x, int y, int x1, int y1, int x2, int y2, int x3, int y3 ){

	move( y1, x1);
	printw("0");

	move( y2, x2);
	printw("0");

	move( y3, x3);
	printw("0");

	move( y, x);
	printw(".");

}

//Sair do programa
void sair() {
  endwin(); /*Sempre que finalizarmos um programa com a biblioteca curses.*/
  exit(0);
}
