#include <stdio.h>
#include <stdlib.h>
#include "Booleano.h"

#define fantasma -1
typedef struct Celula{
    unsigned char item;
    struct Celula *next; 
} Celula;
typedef struct{
    Celula *inicio;
    Celula *fim;
} Fila;

//INTERFACE
Fila criarFilaVazia();
int acessarInicio(Fila);
bool verificarFilaVazia(Fila);
bool verificarFilaCheia(Fila);
Fila pushFila(Fila, int);
Fila popFila(Fila);
void esvaziarFila(Fila*);
void mostrarFila(Fila);

int main(){
    Fila a;
    bool vazia;
    int y;

    a = criarFilaVazia();
    a = pushFila(a, 'a');
    a = pushFila(a, 'n');
    a = pushFila(a, 'v');
    a = pushFila(a, 'c');
    a = pushFila(a, 'x');
    a = popFila(a);
    mostrarFila(a);
    
    y = acessarInicio(a);
    printf("\n%d",y);

    esvaziarFila(&a);
    y = acessarInicio(a);
    printf("\n%d",y);

    return 0;
}

Fila criarFilaVazia(){
    Fila a;
    a.fim = NULL;
    a.inicio = NULL;

    return a;
}


int acessarInicio(Fila a){
    Celula *aux;
    int y;
    
    if(a.inicio != NULL){    
        aux = a.fim;
        y = aux->item;
    }else y = fantasma;

    return y;
}

bool verificarFilaVazia(Fila a){
    bool vazio = FALSE;

    if(a.inicio == NULL){
        vazio = TRUE;
    }

    return vazio;
}

Fila pushFila(Fila A, int item) {

  Celula *novo, *cel;
  novo = malloc(sizeof(Celula));
  novo->item = item;
  novo->next = NULL;

  if (A.inicio == NULL) {
    A.fim = novo;
    A.inicio = novo;
  } else {
    cel = A.fim;
    cel->next = novo;
  }
  A.fim = novo;

  return A;
}

Fila popFila(Fila A) {
  Celula *apont;
  if (A.inicio != NULL) {
    apont = A.inicio;
    A.inicio = apont->next;

    if(A.fim == apont){
      A.fim = NULL;
    }
    free(apont);
  }
  return A;
}

void esvaziarFila(Fila *a){
    Celula *p, *aux;
    p = a->inicio;
    if(a->inicio != NULL){
        while (p->next != NULL)
        {
            aux = p;
            p = p-> next;
            free(aux);
        }
        free(p);    
        a->fim = NULL;
        a->inicio = NULL;
    }
}

void mostrarFila(Fila A) {
  Celula *apont;

  if (A.inicio == NULL) {
    printf("\n Fila vazia");
  } else {
    printf("\nFila: ");
    apont = A.inicio;
    do {
      printf("%c ", apont->item);
      apont = apont->next;
    } while (apont != NULL);
  }
}