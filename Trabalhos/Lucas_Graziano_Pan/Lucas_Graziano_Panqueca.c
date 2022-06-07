/*
Arquivo: Lucas_Graziano_panqueca.h
Autores: Lucas Costa Pessoa Graziano - RA00297851
		 Julio Cesar Barboza Filho   - RA00297586
		 Guistavo Scacchetti de Souza- RA00301499
Date: 06/05/22 09:21
Descricao: implementação de funções para a panqueca em c
*/


#include "Lucas_Graziano_Fila.h"
#include "Lucas_Graziano_Pilha.h"
#include "Booleano.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Max 10
#define sinal -1
#define fantasma -36


int contarPilha(Pilha, unsigned char);
Pilha construirPilha(int);
Pilha inverter(Pilha, int);

int main(){
	Pilha A;
	A = criarPilha();
	int n, i, qtd;
	n = Max;
	A = construirPilha(Max);
	
	mostrarPilha(A);
	
	printf("\n");
	do {
		qtd = contarPilha(A, n);
		if(qtd != n){
			if(qtd != 1){
				A = inverter(A, qtd);	
			}
			A = inverter(A,n);
		}
		n--;
	}while (n != 1);
	
	mostrarPilha(A);
	
	return 0;
}

int contarPilha(Pilha A, unsigned char ch){
	int cont = 0;
	bool achou;
	unsigned char aux;
	achou = FALSE;
	Pilha B;
	B = criarPilha();
	B = A;
	if(pilhaVazia(A) == FALSE){
		while (achou == FALSE){
			aux = acessarTopo(B);
			if(ch == aux){
				achou = TRUE;
			}
			cont = cont + 1;
			B = popPilha(B);
		
		}
	}
	return cont;
}

Pilha construirPilha(int n){
	Pilha A;
	A = criarPilha();
	int aux, j, temp, i, m;
	int arr[Max];
	m = n-1;

	for(i=0;i<=m;i++){
		aux = i+1;
		arr[i] = aux;
	}
	
	srand((int)time(NULL));
	
	for(i=n-1; i>=0; i--){
		j = rand() % (i+1);
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp; 
		aux = arr[i];
		A = pushPilha(A, aux);
	}

	return A;
}


Pilha inverter(Pilha A, int num){
	unsigned char ch;
	int i = 0;
	Fila B;
	B = criarFila();
	
	if(pilhaVazia(A) == FALSE ){
	while(pilhaVazia(A) == FALSE && i < num ){
		ch = acessarTopo(A);
		B = pushFila(B, ch);
		A = popPilha(A);
		i++;
	}	
	
	while(filaVazia(B) == FALSE){
		ch = acessarPrimeiro(B);
		A = pushPilha(A, ch);
		B = popFila(B);
	}
	}
	
	return A;
}