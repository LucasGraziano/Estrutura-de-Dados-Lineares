/* 
Arquivo: Lucas_Graziano_Pilha.h
Autor: Lucas Costa Pessoa Graziano
Date: 29/04/22 09:57
Descrição: implementação de funções de pilha
*/

#define Max 10
#define sinal -1
#define fantasma -36
#include <stdio.h>
#include "Booleano.h"


typedef struct{
	int topo;
	unsigned char Vetor[Max];
}Pilha;




Pilha criarPilha();
bool pilhaVazia(Pilha);
bool pilhaCheia(Pilha);
Pilha pushPilha(Pilha, unsigned char);
Pilha popPilha(Pilha);
unsigned char acessarPilha(Pilha);
Pilha esvaziarPilha(Pilha);
void mostrarPilha(Pilha);



Pilha criarPilha(){
	Pilha A;
	A.topo = sinal;
	return A;
}

bool pilhaVazia(Pilha A){
	bool vazia;
	int tam;
	tam = A.topo;
	if(tam == sinal){
		vazia = TRUE;
	} else vazia = FALSE;
	return vazia;
}

bool pilhaCheia(Pilha A){
	bool cheia;
	int tam;
	tam = A.topo;
	if(tam == Max-1){
		cheia = TRUE;
	} else {
		cheia = FALSE;
	}
	return cheia;
	
}

void mostrarPilha(Pilha A){
	int tam, i;
	tam=A.topo;
	if (tam == sinal) {
		printf("\n Pilha Vazia");
	} else{
		for(i=0; i<=tam; i++){
			printf(" %c ", A.Vetor[i]);
		}
	}
	
}

unsigned char acessarPilha(Pilha A){
	int tam;
	unsigned char ch;
	tam = A.topo;
	if (tam!=sinal){
		ch = A.Vetor[tam];
	} else ch = fantasma;
	
	return ch;
}

Pilha esvaziarPilha(Pilha A){
	A.topo = sinal;
	return A;
}

Pilha pushPilha(Pilha A, unsigned char ch) {
	int tam;
	tam = A.topo;
	if(tam < Max-1){
		A.topo = A.topo + 1;
		tam = A.topo;
		A.Vetor[tam] = ch;
	}
	return A;
}

Pilha popPilha(Pilha A){
	int tam;
	tam = A.topo;
	
	if(tam > sinal){
		A.topo = A.topo - 1;
	}
	return A;
}