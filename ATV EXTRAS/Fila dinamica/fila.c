#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MaxFila 8
#define ghost -1
#define sinal 0

typedef struct
{
    int inicio;
    int fim;
    int item[MaxFila];
} t_Fila;
typedef t_Fila *Fila;

Fila criarFilaVazia();
int acessarInicio(Fila);
bool verificarFilaVazia(Fila);
bool verificarFilaCheia(Fila);
void pushFila(Fila, int);
void popFila(Fila);
void esvaziarFila(Fila);
void mostrarFila(Fila);

int main()
{
    Fila A;
    int el;
    A = criarFilaVazia();
    pushFila(A, 1);
    pushFila(A, 2);
    pushFila(A, 4);
    el = acessarInicio(A);
    printf("%d\n\n", el);

    popFila(A);
    esvaziarFila(A);
    mostrarFila(A);

    return 0;
}
Fila criarFilaVazia()
{
    Fila A;
    A = malloc(sizeof(t_Fila)); // cria o heap
    A->inicio = sinal;          // Atualiza os valores
    A->fim = sinal;
    return A;
}

void pushFila(Fila A, int ch)
{
    int seg;
    seg = (A->fim + 1) % MaxFila; // formula padrão. só muda dentro do parênteses
    if (seg != A->inicio)
    {
        A->item[seg] = ch;
        if (A->inicio == sinal)
        {
            A->inicio = seg; // no caso do primeiro item, o valor do inicio vai para 1 e o fim vai continuar
        }
        A->fim = seg;
    }
}

void popFila(Fila A)
{
    int seg;
    int inicio, fim;
    inicio = A->inicio;
    fim = A->fim;
    if (A->inicio != sinal)
    {
        if (inicio == fim) // se a lista tiver apenas 1 elemento
        {
            A->inicio = sinal;
            A->fim = sinal;
        }
        else
        { // se tiver mais de um

            seg = (A->inicio + 1) % MaxFila; // encontra o valor 1 a mais que o inicio
            A->inicio = seg;                 // Atualiza o inicio
            // se o A.inicio = 1 - seg = 2 e assim vai
        }
    }
}

void mostrarFila(Fila A)
{
    int inicio, fim;
    fim = A->fim;
    inicio = A->inicio;

    if (inicio == sinal)
    { // lista vazia
        printf("Fila Vazia\n");
    }
    else
    {
        while (inicio != fim)
        { // enquanto o inicio e fim forem diferentes, ele vai printar
            printf(" %d ", A->item[inicio]);
            inicio = (inicio + 1) % MaxFila; // inicio + 1 baseando com o MAX
        }
        printf(" %d", A->item[fim]); // coloca o ultimo item
    }
}

bool verificarFilaVazia(Fila A)
{
    bool veri;
    int inicio;
    inicio = A->inicio;
    if (inicio == sinal)
    { // lista vazia
        veri = true;
    }
    else
    {
        veri = false;
    }
    return veri;
}

bool verificarFilaCheia(Fila A)
{
    bool cheio;
    int veri = (A->fim + 1) % MaxFila;
    if (veri == A->inicio)
    {
        cheio = true;
    }
    else
        cheio = false;
    return cheio;
}

void esvaziarFila(Fila A)
{ // apenas zera o A->inicio e A->fim
    A->inicio = sinal;
    A->fim = sinal;
}

int acessarInicio(Fila A)
{
    int inicio, fim, ch;
    inicio = A->inicio;
    fim = A->fim;
    if (inicio != sinal)
    {
        ch = A->item[fim];
    }
    else
    {
        ch = ghost;
    }
    return ch;
}