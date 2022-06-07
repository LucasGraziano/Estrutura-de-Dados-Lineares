#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Celula
{
    int item;
    struct Celula *next;
} Celula;

typedef struct
{
    int tamanho;
    Celula *inicio;
} Lista;

Lista criarLista();
Lista inserirInicio(Lista, int);
void mostrarListaED(Lista);
Lista removerPrimeiro(Lista);
Lista inserirFim(Lista, int);
Lista RemoverFim(Lista);
Lista buscaRemove(Lista, int);
bool verificarCrescente(Lista);
bool verificarIgual(Lista, Lista);
Lista concatenarLista(Lista, Lista);
Lista Inverter(Lista);

int main()
{
    Lista A , B , Aux;
    bool veri;
    A = criarLista();
    B = criarLista();
    A = inserirInicio(A, 5);
    A = inserirInicio(A, 4);
    A = inserirInicio(A, 3);
    A = inserirInicio(A, 2);
    A = inserirInicio(A, 1);
    B = inserirInicio(B, 6);
    B = inserirInicio(B, 7);
    B = inserirInicio(B, 8);
    B = inserirInicio(B, 9);
    B = inserirInicio(B, 10);
    Aux = concatenarLista(A, B);
    mostrarListaED(Aux);
    Aux = Inverter(Aux);
    printf("\n\n\n"); 
    mostrarListaED(Aux);
    veri = verificarIgual(A, B);
    printf("\n\n%d\n\n", veri);
    // A = inserirInicio(A, 4);
    // A = inserirFim(A, 2);
    A = buscaRemove(A, 5);
    veri = verificarCrescente(A);
    printf("\n\n%d\n\n", veri);
    // A = removerPrimeiro(A);
    // A = RemoverFim(A);
    // A = RemoverFim(A);
    mostrarListaED(A);
    return 0;
}

Lista criarLista()
{ // inicializando a lista
    Lista A;
    A.tamanho = 0;
    A.inicio = NULL;
    return A;
}
Lista inserirInicio(Lista A, int ch)
{
    Celula *novo, *aux;
    
    aux = A.inicio;
    while (aux != NULL && aux->item != ch)
    {
        aux = aux->next;
    }
    if (aux == NULL)
    {
        novo = malloc(sizeof(Celula));
        novo->item = ch;
        novo->next = A.inicio;
        A.inicio = novo;
        A.tamanho++;
    }
    return A;
}

Lista removerPrimeiro(Lista A)
{
    Celula *cel, *aux;
    cel = A.inicio;
    aux = cel->next;
    free(cel);
    A.inicio = aux;
    A.tamanho--;
    return A;
}

void mostrarListaED(Lista A)
{ // mostra a lista da esquerda para a direita
    Celula *aux;
    int tam = 1;
    aux = A.inicio;

    if (A.inicio == NULL)
        printf("Lista Vazia\n");
    else
    {
        while (tam <= A.tamanho)
        {
            printf(" %d ", aux->item);
            aux = aux->next; // esta fazendo de A.inicio ate o fim
            tam++;
        }
    }
}

Lista inserirFim(Lista A, int ch)
{
    Celula *novo, *p;
    novo = malloc(sizeof(Celula));
    novo->item = ch;
    p = A.inicio;
    if (A.inicio != NULL)
    {
        while (p->next != NULL)
            p = p->next;
        p->next = novo;
        novo->next = NULL;
        A.tamanho++;
    }
    else
    {
        novo->next = NULL;
        A.inicio = novo;
        A.tamanho++;
    }
    return A;
}

Lista RemoverFim(Lista A)
{
    Celula *cel;
    cel = A.inicio;
    if (A.inicio != NULL)
    {
        while (cel->next != NULL)
            cel = cel->next;
        free(cel);
        cel = NULL;
        A.tamanho--;
    }
    return A;
}

Lista buscaRemove(Lista A, int ch)
{
    Celula *cel, *p, *prox;
    if (A.inicio != NULL)
    {
        p = A.inicio;
        if (p->item == ch)
        {
            prox = p->next;
            A.inicio = prox;
            free(p);
            A.tamanho--;
        }
        else
        {
            cel = p->next;
            while (cel != NULL && cel->item != ch)
            {
                p = p->next;
                cel = cel->next;
            }
            if (cel->item == ch)
            {
                prox = cel->next;
                p->next = prox;
                free(cel);
                A.tamanho--;
            }
        }
    }

    return A;
}

bool verificarCrescente(Lista A)
{
    Celula *cel, *prox;
    bool veri;
    cel = A.inicio;
    prox = cel->next;
    while (cel->next != NULL && cel->item < prox->item)
    {
        cel = cel->next;
        prox = prox->next;
    }
    if (cel->next == NULL)
    {
        veri = true;
    }
    return veri;
}

bool verificarIgual(Lista A, Lista B)
{
    bool veri = false;
    bool achou = true;
    Celula *cel, *p;
    cel = A.inicio;
    while(cel != NULL && achou == true){
        p = B.inicio;
        achou = false;
        while(p != NULL && achou == false){
            if(cel->item == p->item){
                achou = true;
            }
            p = p->next;
        }
        cel = cel->next;
    }
    if(achou == true){
        veri = true;
    }
    return veri;
}

Lista concatenarLista(Lista A, Lista B){
    Celula *cel;
    cel = A.inicio;
    while(cel->next != NULL) cel = cel->next;
    cel->next = B.inicio;
    A.tamanho = A.tamanho + B.tamanho;
    return A;
}

Lista inverterLista(Lista A){
    Lista aux;
    aux.tamanho = 0;
    aux.inicio = NULL;
    Celula *cel, *p, *pos;
    cel = A.inicio;
    p = aux.inicio;
    if(A.inicio != NULL){
    while (A.tamanho >0){
        
        
    } 
    }
    return aux;
}

Lista Inverter(Lista A){
    Celula *ant = NULL, *at, *prox;

    if(A.tamanho != 0){
        at = A.inicio;
        prox = at->next;
        
        if(prox != NULL){
            while(prox != NULL){
                at->next = ant;
                ant = at;
                at = prox;
                prox = prox->next;
            }
            at->next = ant;
            A.inicio = at;
        }
    }

    return A;

}