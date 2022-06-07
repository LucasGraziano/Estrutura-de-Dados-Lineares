/*  
  Arquivo: ordenarLista.c
  Autor: Gustavo Scacchetti de Sousa, Julio Cesar, Lucas Costa Pessoa Graziano
  Date: 20/03/2022 19:00
  Descrição: Atividade 
*/
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define Max 100000
typedef struct {
      int tamanho;
      int Tabela[Max];
} Lista;
//interface
Lista criarListaAleatoria(int, int, int);
void mostrarLista(Lista);
void ordenarListaCrescenteB(Lista *);   // bubbleSort
void ordenarListaCrescenteS(Lista *);   // selectionSort
void ordenarListaCrescenteI(Lista *);   // insertionSort
int main(){
    Lista L1; //chamada da Lista 
    clock_t start1, finish1; //clock para o bubble
    clock_t start2, finish2; //clock para o insertion
    clock_t start3, finish3; //clock para o Selection
    double timeB, timeI, timeS;
    printf(" \n\n\nConstruir uma lista com inteiros na faixa 1..150000 \n\n");
    L1 = criarListaAleatoria(Max-1,1,100000);
    //mostrarLista(L1); printf(" \n\n");    
    //bubble
    printf(" executando BubbleSort ... ");
    start1 = clock(); //inicio do clock 1
    ordenarListaCrescenteB(&L1);
    finish1 = clock(); //final do clock 1
    timeB = (double)(finish1 - start1)/CLOCKS_PER_SEC;  printf("    elapsed = %f segundos \n\n",timeB);
    //Insertion
    printf(" executando InsertionSort ... ");
    start2 = clock(); //inicio do clock 2
    ordenarListaCrescenteI(&L1);
    finish2 = clock(); //final do clock 2
    timeS = (double)(finish2 - start2)/CLOCKS_PER_SEC;  printf("    elapsed = %f segundos \n\n",timeS);
    //Selection
    printf(" executando SelectionSort ... ");
    start3 = clock(); //inicio do clock 3
    ordenarListaCrescenteS(&L1);
    finish3 = clock(); //final do clock 3
    timeI = (double)(finish3 - start3)/CLOCKS_PER_SEC;  printf("    elapsed = %f segundos \n\n",timeI);
    //printf(" \n\n\n"); mostrarLista(L1);  printf(" \n\n");
    printf("\n\nfim");
    return 0;
}
// implementação
Lista criarListaAleatoria(int N, int a, int b){
    Lista L;
    int i,k,g,tam;
    double d;
    if (N>=Max) tam = Max-1; else tam = N; 
    srand((int) time(NULL));    //semente obtida pelo relógio do sistema
    L.tamanho = tam;
    for(i=1; i<=tam; i++){      
       d = (double)rand()/((double)RAND_MAX +1);
       k = (int)(d*(b-a+1));
       g = a+k;
       L.Tabela[i] = g;
    };
    return L;
}
Lista criarListaVazia(){ //criação da lista com tamanho 0
    Lista L;
    L.tamanho = 0;
    return L;
}
void mostrarLista(Lista A){//mostra a lista
     int n,i;
     n = A.tamanho;
     printf("tamanho da lista = %d \n\n",n);
     if(n==0)printf("\n lista vazia\n");
     else{
        for(i=1;i<=n;i++){ printf(" %d ",A.Tabela[i]);}
        printf("\n");
     }
}
void ordenarListaCrescenteB(Lista *ap){      /* BubbleSort: trocar pares consecutivos fora da ordem */
     int i,j,fim,n,aux;
     n = ap->tamanho;                           /* n = quantidade de elementos da lista */
     fim = n-1;
     for(i=1;i<n;i++){                          /* n-1 etapas  */
        for(j=1;j<=fim; j++){                   /* comparar/trocar do primeiro ao penultimo */
            if (ap->Tabela[j] > ap->Tabela[j+1]){
                 aux = ap->Tabela[j]; ap->Tabela[j] = ap->Tabela[j+1]; ap->Tabela[j+1] = aux;
            };
        }
        fim = fim -1;
     }
}
void ordenarListaCrescenteS(Lista *ap){      /* SelectionSort: localizar o menor e colocar no seu lugar */
     int i,j,min,n,aux;
     n = ap->tamanho;                           /* n = quantidade de elementos da lista */
     for(i=1;i<n;i++){                          /* n-1 etapas  */
         min = i;                                                                  /* min = local onde se encontra o menor */
         for(j=i+1;j<=n; j++) if (ap->Tabela[j] < ap->Tabela[min]) min = j;          /* atualização de min */
         aux = ap->Tabela[i]; ap->Tabela[i] = ap->Tabela[min]; ap->Tabela[min] = aux;   /* troca com o menor */
     }
}
void ordenarListaCrescenteI(Lista *ap){      /* InsertionSort - ordenação por inserção */
     int i,k,n,aux;
     n = ap->tamanho;                           /* n = quantidade de elementos da lista */
     for(i=2;i<=n;i++){                         /* n-1 etapas  */
         aux = ap->Tabela[i];
         k = i-1;
         while ((k>0) && (ap->Tabela[k] > aux)) {ap->Tabela[k+1] = ap->Tabela[k]; k = k - 1;}  /* desloca */
         ap->Tabela[k+1] = aux;                                                              /* insere  */
         }
     }