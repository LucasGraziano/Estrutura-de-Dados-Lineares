
/*
Arquivo: Lucas_Graziano_Fila.h
Autor: Lucas Costa Pessoa Graziano - RA00297851

Date: 04/05/22 18:05
Descricao: implementação de funções de fila em c

*/

#include <stdio.h>
#include "Booleano.h"
#define Max 10
#define sinal -1
#define fantasma -36


typedef struct{
	int inicio; //posição do primeiro elemento
	int fim; //posição do ultimo elemento
	unsigned char Vetor[Max]; //itens da lista
}Fila;


Fila criarFila();
bool filaVazia(Fila);
bool filaCheia(Fila);
unsigned char acessarPrimeiro(Fila);
Fila pushFila(Fila, unsigned char);
Fila popFila(Fila);
Fila esvaziarFila (Fila);
void mostrarFila (Fila);



Fila criarFila(){
	Fila A;
	A.inicio = sinal;
	A.fim = sinal;
	return A;
}

bool filaVazia(Fila A){
	bool vazio;
	if (A.inicio == sinal){
		vazio = TRUE;
	} else vazio = FALSE;
	return vazio;
}

bool filaCheia(Fila A){
	bool cheio;
	int veri = (A.fim + 1) % Max;
	if (veri == A.inicio){
		cheio = TRUE;
	}else cheio = FALSE;
	return cheio;
}

unsigned char acessarPrimeiro(Fila A){
	int p, tam;
	tam = A.inicio;
	
	if(A.inicio != sinal){
		p = A.Vetor[tam];		
	}else p = fantasma;
	
	return p;
}

Fila pushFila(Fila A, unsigned char ch) {
	int seg;
	seg = (A.fim + 1) % Max;
	if(seg != A.inicio) {
		A.Vetor[seg] = ch;		
		if( A.inicio == sinal ) {
			A.inicio = seg; 	
		}
		A.fim = seg;
	}
	return A;
}

Fila popFila(Fila A) {
	int seg;
	int inicio, fim;
	inicio = A.inicio;
	fim = A.fim;
	if(inicio != sinal ) {
		if(inicio == fim) {
			A.inicio = sinal; 
			A.fim = sinal;  
		} 
		else{ 
			seg = (A.inicio + 1) % Max;
			A.inicio = seg;
		}
	return A;
	}
}

void mostrarFila(Fila A){
	int inicio, fim;
	fim = A.fim;
	inicio = A.inicio;

	if(inicio == sinal){
		printf("Fila Vazia\n");
	} else{	
		while(inicio != fim){
			printf(" %c ", A.Vetor[inicio]);
			inicio = (inicio + 1) % Max;
		}	
		printf(" %c", A.Vetor[fim]); 
	}
}

Fila esvaziarFila(Fila A){
	A.inicio = sinal;
	A.fim = sinal;
	return A;
}





