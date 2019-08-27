#include <stdio.h>
#include <stdlib.h>

typedef struct _lista {
	int info;
	struct _lista * prox;
}TpLista;

TpLista* inseriIni(TpLista* l, int i);
TpLista* inicializa();
TpLista *exclui(TpLista * l, int e);
void imprime(TpLista* l);

TpLista *inicializa(){
	return NULL;
}

TpLista *inseriIni(TpLista *l, int n){
	TpLista *novo = (TpLista *) malloc(sizeof(TpLista));
	if (novo == NULL)
		return NULL;
	novo->info = n;
	novo->prox = l;
	return novo;
}

void imprime(TpLista* l){
	TpLista* p;
	for(p = l; p != NULL; p = p->prox){
		printf("Informação = %d\n", p->info);
	}
}

int evazia(TpLista* l){
	if(l == NULL){
		return 1;
	}else{
		return 0;
	}
}


TpLista* busca(TpLista* l, int e){
	TpLista* p;
	for(p = l; p != NULL; p=p->prox){
		if(p->info == e){
			return p;
		}
	}
	return NULL; //O elemento não está na lista
}

TpLista *exclui(TpLista * l, int e){
	TpLista * anterior = NULL; // ponteiro para o elemento anterior
	TpLista * p = l; // ponteiro para percorrer a lista
	
	/* procura elemento na lista e guarda o anterior */
	while(p != NULL && p->info != e){
		anterior = p;
		p = p->prox;
	}
	
	/* verifica se achou elemento */
	if(p == NULL){
		return l; // não achou o elemento, retorna a lista original
	}
	/* retira elemento */
	if(anterior == NULL){ // então retirar o primeiro elemento
		l = p->prox;
	}else{ // retira elemento do meio da lista
		anterior->prox = p->prox; 
	}
	free(p);
	return l;
}


TpLista *insereOrdenado(TpLista * l, int e){
	TpLista * anterior = NULL, *novo; // ponteiro para o elemento anterior
	TpLista * p = l; // ponteiro para percorrer a lista
	novo = (TpLista *)malloc(sizeof(TpLista));
	if (novo == NULL) return l;
	novo->info = e;
	/* procura elemento na lista e guarda o anterior */
	while(p != NULL && p->info < e){
		anterior = p;
		p = p->prox;
	}
	
	//Seja o último elemento
	if(p == NULL){
		anterior->prox = novo;
		novo->prox = NULL;
		return l;
	}
	
	//Primeiro elemento
	if(anterior == NULL){
		novo->prox = p;
		l = novo;
	}else{ //insere no meio
		novo->prox = p;
		anterior->prox = novo; 
	}
	return l;
} 

int main(){
	TpLista* l;	/* declara uma lista não inicializada */
	// l = inicializa(); /* inicializa lista como vazia */ 
	// l = inseriIni(l, 10); /* insere o elemento 10 */
	// l = insereOrdenado(l,12);
	// l = insereOrdenado(l,11);
	// l = insereOrdenado(l,11);
	// l = insereOrdenado(l,15);
	// l = insereOrdenado(l,1);
	// l = insereOrdenado(l,14);

	int num;

	printf("\nInsert int: ");
	scanf("%d", &num);

	l = inicializa();
	l = inseriIni(l, num);

	while(1){
		printf("\nInsert int: ");
		scanf("%d", &num);

		if(num != 0){
			l = insereOrdenado(l, num);
		}else{
			break;
		}
	}

	imprime(l);
	return 0;
}

