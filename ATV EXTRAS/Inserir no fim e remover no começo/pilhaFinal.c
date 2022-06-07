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

Pilha pushPilha(Pilha A, int ch){ //inserir no fim 
    Celula *novo, *p;
    novo = malloc(sizeof(Celula));
    novo->item = ch; //passa o valor inserido para o novo
    p = A; //transforma a celula p na lista

    if(A != NULL){
        while(p->next != NULL) p = p->next; //faz a busca buscando o ultimo item
        p->next = novo; //o ultimo item inserido irá apontar para o novo
        novo->next = NULL;//o novo item aponta para NULL (TERRA)
    } else {
        novo->next = NULL; //o novo item aponta para NULL (TERRA)
        A = novo;//isso inicia a lista, a lista A irá apontar para o primeiro elemento. 
    }
    return A;
}

Pilha popPilha(Pilha A){
    Celula *cel, *novo;
    cel = A; //copiou a lista A
    novo = A->next; //copiou a lista A sem o primeiro elemento
    free(cel); //removeu o primeiro item
    cel = NULL; //transforma A lista como null
    A = novo; //atualiza a lista
    return A;
}

void mostrarLista(Pilha A){
    Celula* aux;

    if(A != NULL){
        if(A->next != NULL){
            aux = A;
            while(aux != NULL){
                printf("%d ", aux->item);
                aux = aux->next;
            }

        }else printf("%d\n", A->item);
        printf("\n");
    }
}