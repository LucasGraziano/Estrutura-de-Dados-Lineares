/*
Arquivo: Lucas_Graziano_Lista_LL.c

Autores: Lucas Costa Pessoa Graziano - RA00297851
		 Julio Cesar Barboza Filho   - RA00297586
		 Gustavo Scacchetti de Sousa - RA00301499

Data: 20/05/22 09:26

Descricao: implementacao de funcoes envolvendo lista duplamente ligada, em ordem decrescente e sem duplicatas
*/

#define ghost -1
#include "Booleano.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Celula{
	int valor;
	struct Celula* next;
	struct Celula* pre;
} Celula;

typedef struct {
	int tam;
	Celula* inicio;
	Celula* fim;
} Lista;

Lista criarLista(); 
int determinarTamanho(Lista); 
bool listaVazia(Lista); 
void mostrarListaED(Lista); 
void mostrarListaDE(Lista); 
Celula* buscarItem(Lista, int); 
int obterItemK(Lista, int); 
Lista buscaInsere(Lista, int); 
Lista removerItem(Lista, int);
Lista esvaziarLista(Lista); 


Lista criarLista(){
	Lista ap;
	ap.inicio= NULL; 
	ap.fim= NULL;
	ap.tam= 0;
	return ap;
} 

int determinarTamanho(Lista A){
	int tamanho;
	tamanho = A.tam; 
	return tamanho;
}


Celula* buscarItem(Lista A, int n){
    Celula* p;
    if(A.inicio != NULL){
        p = A.inicio;
        while((p->valor != n) && (p-> next != NULL)){
            p=p->next;
        }
        if(p->valor != n) p = NULL;
    }
    return p;
}

int obterItemK(Lista A, int pos){
	Celula *cel = NULL;
	int i = 0;
	int item;

	if(A.tam != 0){
		if(pos > 0 && pos <= A.tam){ 
			cel = A.inicio ; 
			for(i = 2; i <= pos; i++){ 
				cel = cel->next;
			}
		item = cel->valor;
		}else {
			item = ghost;
		}
	}	
	return item;
}

bool listaVazia(Lista A){
	bool veri;
	if(A.inicio != NULL){ 
		veri = FALSE;
	} else veri = TRUE;
	
	return veri;
}


Lista buscaInsere(Lista A, int ch){
	Celula* novo, *p, *ant;
	
	
	bool achouDuplicata = FALSE;
	bool veri = FALSE;
	
	if(A.inicio == NULL){ 
		novo = malloc(sizeof(Celula));
		novo->valor = ch; 
		A.inicio = novo; 
		A.fim = novo;	
		novo->pre = NULL;
		novo->next = NULL;
		A.tam = A.tam + 1;
	} else {
		p = A.inicio;
		
		
		while(p != NULL && p->valor >= ch && achouDuplicata == FALSE){ 
			if(p->valor == ch){
				achouDuplicata = TRUE;
			}
			p = p->next;
		} 

		
		if(p == NULL && achouDuplicata == FALSE){
			novo = malloc(sizeof(Celula));
			novo->valor = ch; 
			ant = A.fim;
			ant->next = novo;
			novo->pre = ant;
			novo->next = NULL;
			
			A.fim = novo; 
			A.tam = A.tam + 1; 
			
		
		} else if(achouDuplicata == FALSE){
			if(p != A.inicio){
				novo = malloc(sizeof(Celula));
				novo->valor = ch; 
				ant = p->pre; 
				novo->next = p;
				p->pre = novo; 
				novo->pre = ant;
				ant->next = novo;
			}else{ 
				novo = malloc(sizeof(Celula));
				novo->valor = ch; 
				p->pre = novo;
				novo->pre = NULL;
				novo->next = p;
				A.inicio = novo;
			}	
				A.tam = A.tam + 1;
		} 
		
	}
	return A;

}

void mostrarListaED(Lista A){ 
    Celula * aux = A.inicio;
    if (A.inicio == NULL) printf("Lista Vazia\n");
    else{
        while (aux != NULL){
            printf("%d ", aux->valor);
            aux = aux->next; 
        }
    }
}

void mostrarListaDE(Lista A){ 
    Celula * aux = A.fim;
    if (A.inicio == NULL) printf("Lista Vazia\n");
    else{
        while (aux != NULL){
            printf("%d ", aux->valor);
            aux = aux->pre; 
        }
    }
}


Lista removerItem(Lista A, int pos){
  Celula *cel , *celAnt, *celPos;
  int i;

  if(A.tam != 0){ 
    if(pos > 0 && pos <= A.tam){ 
      cel = A.inicio; 

      for(i = 2; i <= pos; i++){ 
        cel = cel->next;
      }
      if(cel == A.inicio){ 
        A.inicio = NULL;
        A.fim = NULL;
        free(cel);
      }else { 
        celPos = cel->next;
        celAnt = cel->pre;
        celAnt->next = celPos;
        celPos->pre = celAnt;
        free(cel);
      }
      A.tam --;	 
    } 
  }
  return A;
}


Lista esvaziarLista(Lista A){
	Celula *cel, *aux; 
	int tam = A.tam;
	int i;
	cel = A.inicio;
	while(cel != NULL){
		aux = cel;
		cel = cel -> next; 
		free(aux);
	}
	A.inicio = NULL;
	A.tam = 0;
	return A;
}
