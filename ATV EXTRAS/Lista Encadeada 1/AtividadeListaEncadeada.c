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
    struct Celula* pre;
    struct Celula* suc;
} Celula;

typedef struct{
    Celula *inicio;
    Celula *fim;
    int tamanho;
}Lista;

Lista criarLista();
Lista inserir(Lista, int);
void mostrarListaED(Lista);
Lista Esvaziar(Lista);

int main(){
    Lista A;
    A = criarLista();
    A = inserir(A, 1);
    A = inserir(A, 3);
    A = inserir(A, 3);
    A = inserir(A, 6);
    A = Esvaziar(A);
    mostrarListaED(A);
    A = inserir(A, 1);
    A = inserir(A, 3);
    A = inserir(A, 3);
    mostrarListaED(A);
    return 0;
}

Lista criarLista(){
    Lista A;
    A.inicio = NULL;
    A.fim = NULL;
    A.tamanho = 0;
    return A;
}

Lista inserir(Lista A, int ch){
    Celula *novo, *prox;
    novo = malloc(sizeof(Celula));
    novo->elemento = ch;
    if(A.inicio == NULL){
        A.inicio = novo;
        A.fim = novo;
        novo->pre = NULL;
        novo->suc = NULL; 
        A.tamanho = A.tamanho + 1;
    } else {
        prox = A.inicio;
        prox->pre = novo;
        novo->pre = NULL;
        novo->suc = prox;
         A.inicio = novo;
        A.tamanho = A.tamanho + 1;
    }
    return A;
}

void mostrarListaED(Lista A){
    Celula * aux = A.inicio;
    if (A.inicio == NULL) printf("Lista Vazia\n");
    else{
        while (aux != NULL){
            printf(" %d ", aux->elemento);
            aux = aux->suc;
        }
    }
}

Lista Esvaziar(Lista A){
    Celula *cel, *prox;
    cel = A.inicio;
    prox = cel->suc;
    if(A.inicio != NULL){
        if(A.inicio == A.fim){
            free(cel);
            A.tamanho = A.tamanho - 1;
        } else{
            while (prox != NULL){
                prox = cel->suc;
                free(cel);
                A.tamanho = A.tamanho - 1;
                cel = prox;
                
            }
        }
        A.inicio = NULL;
        A.fim = NULL;

    }
    return A;
}