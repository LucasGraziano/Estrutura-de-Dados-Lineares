#include <stdlib.h>
#include<stdio.h>
#include <stdbool.h>
#define ghost -1
typedef struct Celula{
    int item;
    struct Celula* next;
}Celula;

typedef Celula* Lista;

Lista newLista();
bool listaVazia(Lista);
int obterTamanho(Lista);
Lista inserirLista(Lista, int);
void mostrarLista(Lista);
int obterElemento(Lista, int);
Lista removerPrimeiro(Lista);
Lista removerUltimo(Lista);
Celula* buscarItem(Lista, int);
Lista esvaziarLista(Lista);
Lista inserirFim(Lista, int);


int main(){
    Lista A;
    Celula *cel;
    int tam, el;
    bool veri;
    A = newLista();
    veri = listaVazia(A);
    printf("%d", veri);
    printf("\n\n");
    A = inserirLista(A, 1);
    A = removerUltimo(A);
    mostrarLista(A);
    A = inserirLista(A, 2);
    A = inserirLista(A, 5);
    A = inserirFim(A, 3);
    A = inserirLista(A, 5);
    cel = buscarItem(A, 2);
    //A = esvaziarLista(A);
    printf("%d", veri);
    printf("\n\n");
    //A = removerPrimeiro(A);
    A = removerUltimo(A);
    el = obterElemento(A, 2);
    printf("%d", el);
    printf("\n\n");
    veri = listaVazia(A);
    tam = obterTamanho(A);
    mostrarLista(A);
    printf("\n\n");
    printf("%d", tam);
    printf("\n\n");
    printf("%d", veri);
    return 0;
}

Lista newLista(){
Lista A;
A = NULL;
return A;
}

bool listaVazia(Lista A){
    bool veri;
    if(A == NULL) veri = true; // se a lista estiver vazia, veri = true
    else veri = false;

return veri;
}

int obterTamanho(Lista A){
    Celula *cel;
    int tamanho = 0;
    
    cel = A; //copia a lista para a Célula
    while(cel != NULL) { //enquanto a celula for diferente de NULL, ele ira continuar
        tamanho++;
        cel = cel->next;
    }

    return tamanho;
}

Lista inserirLista(Lista A, int ch){
    Celula *novo;
    novo = malloc(sizeof(Celula));
    novo->item = ch;
    novo->next = A;
    A = novo;
    return A;
}

Lista inserirFim(Lista A, int ch){
    Celula *novo, *p;
    novo = malloc(sizeof(Celula));
    novo->item = ch;
    p = A;
    if (p!= NULL){
    while(p->next != NULL) p = p->next;
    p->next = novo;
    novo->next = NULL;
    //A = p;
    } else {
    A = novo;
    }
    return A;
}

void mostrarLista(Lista A){
    Celula *cel;
    cel = A;
    if(A != NULL){
    while(cel != NULL){
        printf("%d ", cel->item);
    	cel = cel->next;
    }
    } else printf("Lista Vazia");
}

int obterElemento(Lista A, int ch){
    Celula *cel;
    int el = ghost, controle = 0;
    cel = A;
    if(A!=NULL){
        while(cel != NULL && controle <ch){
            el = cel->item;
            controle++;
            cel = cel->next;
    }
    if(controle<ch) el = ghost;
    }
    return el;
}

Lista removerPrimeiro(Lista A){
    Celula *cel, *p;
    cel = A;
    if(A != NULL){
    p = cel->next;
    free(cel);
    A = p;
    }
    return A;
}

Lista removerUltimo(Lista A){
    Celula *cel, *p;
    p = A;
    if(A != NULL){
    cel = NULL;
    while(p->next != NULL) {
        cel = p; 
        p = p->next;
    }
    if(cel == NULL){
        A = NULL;
    } else{
    free(p);
    cel->next = NULL;
    }
    }
    return A;
}

Celula* buscarItem(Lista A, int ch){
    Celula *cel;
    bool veri = false;
    cel = A;

    if(A!= NULL){
        if(cel->item == ch){
            veri = true;
        }
        while(cel != NULL && veri == false){
            cel = cel->next;
            if(cel->item == ch){
                veri = true;
            }
            
        }
    }
    return cel;
}

Lista esvaziarLista(Lista A){
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
