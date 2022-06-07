#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define ghost -1

typedef struct Celula
{
    int item;
    struct Celula *next;
} Celula;

typedef Celula *Fila; 

Fila criarFila();
Fila pushFila(Fila, int);
void mostrarLista(Fila);
Fila popFila(Fila);
int AcessarTopo(Fila);
Fila esvaziarFila(Fila);

int main()
{
    Fila A;
    int el;
    A = criarFila();
    A = pushFila(A, 4);
    A = pushFila(A, 3);
    A = pushFila(A, 2);
    A = pushFila(A, 1);
    
    A = popFila(A);
    el = AcessarTopo(A);
    printf("%d\n", el);
    mostrarLista(A);

    return 0;
}

Fila criarFila()
{
    Fila A;
    A = NULL;
    return A;
}

Fila pushFila(Fila A, int ch)
{
    Celula *novo, *p;
    novo = malloc(sizeof(Celula));
    novo->item = ch;
    p = A;
    if (p != NULL)
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = novo;
        novo->next = NULL;
    } else {
        novo->next = NULL;
        A = novo;
    }
    return A;
}

Fila popFila(Fila A){
    Celula *cel, *p;
    cel = A;
    if (cel != NULL){
    p = cel->next;
    free(cel);
    A = p;
    }
    return A;
}

void mostrarLista(Fila A){
    Celula *cel, *p;
    cel = A;
    if (cel != NULL){
        printf("\n\n");
        while(cel != NULL){
            printf("%d ", cel->item);
            cel = cel->next;
        }
    } else {
        printf("Lista Vazia");
    }
}

int AcessarTopo(Fila A){
    Celula *novo;
    int el;
    novo = A; 
    if(novo != NULL){
        el = novo->item;
    } else {
        el = ghost;
    }
    
    return el;
}

Fila esvaziarFila(Fila A){
    Celula *cel, *p;
    cel = A;
    while(cel != NULL){
        p = cel->next;
        free(cel);
        cel = p;
    }
    A = NULL;
    return A;
}