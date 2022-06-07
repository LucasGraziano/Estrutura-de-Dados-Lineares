#include <stdlib.h>
#include<stdio.h>
#include <stdbool.h>

typedef struct Celula{
    int item;
    struct Celula* next;
}Celula;

typedef Celula* Pilha;

Pilha criarPilha();
Pilha pushPilha(Pilha, int);
void mostrarLista(Pilha);
Pilha popPilha(Pilha);

int main(){
    Pilha A;
    A = criarPilha();
    A = pushPilha(A, 4);
    A = pushPilha(A, 3);
    A = pushPilha(A, 2);
    A = pushPilha(A, 4);
    A = pushPilha(A, 5);
    mostrarLista(A);
    A = pushPilha(A, 3);
    A = popPilha(A);
    A = pushPilha(A, 1);
    mostrarLista(A);

}
Pilha criarPilha(){
    Pilha A;
    A = NULL;
    return A;
}

Pilha pushPilha(Pilha A, int ch){//inserir no inicio 
    Celula *novo;
    novo = malloc(sizeof(Celula));
    novo->item = ch; //passa o valor inserido para o novo

    if(A != NULL){ //se a lista for diferente de vazia
        novo->next = A; //coloca a lista depois do novo valor
    } else {
        novo->next = NULL; //se a lista tiver vazia, ele irá adicionar o item e apontar para NULL
    }
    A = novo; //atualiza a lista

    return A;
}

Pilha popPilha(Pilha A){
    Celula *cel, *novo;
    cel = A;
    novo = A->next;
    free(cel);
    cel= NULL;
    A = novo;
    return A;
}

void mostrarLista(Pilha A){
    Celula* aux;

    if(A != NULL){
        if(A->next != A){
            printf("%d ", A->item);
            aux = A->next;
            while(aux != NULL){
                printf("%d ", aux->item);
                aux = aux->next;
            }

        }else printf("%d\n", A->item);
        printf("\n");
    }
}