/*
Arquivo: AtividadeListaEncadeada.c
Autor: Lucas Costa Pessoa Graziano - RA00297851

Date: 25/05/2022
Descricao: Atividade Extra de lista encadeada
*/

#include <stdlib.h>
#include<stdio.h>
#include <stdbool.h>

typedef struct Celula{
    int elemento;
    struct Celula* suc;
} Celula;

typedef struct{
    Celula *inicio;
    int tamanho;
}Lista;

void criarLista(Lista *);
void insereNoFim(Lista *, int);
void mostrarListaED(Lista *);


int main(){
    Lista A;
    criarLista(&A);
    insereNoFim(&A, 1);
    insereNoFim(&A, 2);
    insereNoFim(&A, 1);
    mostrarListaED(&A);

    return 0;
}


void criarLista(Lista *A){
    A->inicio = NULL;
    A->tamanho = 0;
}

void insereNoFim(Lista *A, int ch){
    Celula *novo, *p;
    novo = malloc(sizeof(Celula));
    novo->elemento = ch;
    if(A->inicio == NULL){
        A->inicio = novo; 
		novo->suc = NULL;
		A->tamanho = A->tamanho + 1;
    }else {
    p = A->inicio;
    while(p->suc != NULL) p = p->suc;
    p->suc = novo;
    novo->suc = NULL;
    A->tamanho = A->tamanho + 1;
    }
}

void mostrarListaED(Lista *A){
    Celula * aux = A->inicio;
    if (A->inicio == NULL) printf("Lista Vazia\n");
    else{
        while (aux != NULL){
            printf(" %d ", aux->elemento);
            aux = aux->suc;
        }
    }
}