/*
Arquivo: Lucas_Graziano_ListaP.h
Autores:Lucas Costa Pessoa Graziano
        Julio Cesar Barboza Filho
        Gustavo Scachetti de Souza
Date: 01/04/22 09:32
Descrição: Este arquivo contém as funções do TAD ListaP

*/

#define Max 10
#define Sinal 0
#define fantasma 36
#include "Booleano.h"

typedef struct {
	int tam;
	unsigned char vetor [Max];
}ListaP;

ListaP New();
ListaP append(ListaP , unsigned char );
int len(ListaP);
ListaP clear();
int count(ListaP , unsigned char);
int max(ListaP);
int min(ListaP);
ListaP copy(ListaP, ListaP);
ListaP extend(ListaP, ListaP);
ListaP reverse(ListaP);
ListaP insert(ListaP, int, unsigned char);
ListaP pop(ListaP, int);
ListaP removeLista(ListaP, unsigned char);
int indexLista(ListaP, unsigned char);
ListaP sort(ListaP);

//new - cria uma lista vazia
ListaP New(){
    ListaP A;
    A.tam = Sinal;

return A;
}

//append - acrescenta um novo item no fim da lista
ListaP append(ListaP A, unsigned char ch){
    int nA, local;
    nA = A.tam;
    if((A.tam >= Sinal) && (A.tam<Max)){
  
        A.vetor[A.tam] = ch;
        A.tam++;
    }
return A;
}

//len - devolve o tamanho da lista
int len(ListaP A){
    int c = 0;

    if (A.tam >= Sinal){
        c = A.tam; 
	}

return c;
}

//clear - esvazia a lista
ListaP clear(){
    ListaP A;
    A.tam = Sinal;

return A;
}

//count - devolve a quantidade de itens com o valor especificado
int count(ListaP A, unsigned char v){
    int count = 0;
    int i;
    if (A.tam > Sinal){
        for(i=0; i<=A.tam-1; i++){
	        if (A.vetor[i] == v){
		        count++;
        }
    }
}

return count;
}

//max - devolve um item de maior valor
int max(ListaP A){
    int max = fantasma;
    int i;
    if (A.tam > 0){
        max = A.vetor[0];
        for(i=0; i<=A.tam-1; i++){
            if(A.vetor[i]>max){
                max = A.vetor[i];
        }
    }
}

return max;
}

//min - devolve um item de menor valor
int min(ListaP A){
    int min = fantasma;
    int i;
    if (A.tam > Sinal){
        min = A.vetor[0];
        for(i=0; i<=A.tam-1; i++){
            if(A.vetor[i]<min){
                min = A.vetor[i];    
        }
    }
}

return min;
}

//copy - faz uma cópia da lista 
ListaP copy(ListaP B, ListaP A){
    //B = copia
    //A = a lista original

	int i;
	B.tam = A.tam;
	for(i=0; i<=B.tam-1; i++){
		B.vetor[i] = A.vetor[i];
	}
	
	return B;
}

//extend - concatena duas listas
ListaP extend(ListaP A, ListaP B){
  
    int i, aux;
    ListaP Novo;
    Novo.tam = Sinal;

    if(A.tam > Sinal && B.tam > Sinal){
    Novo = B;  
    aux = Novo.tam - 1;
    Novo.tam = A.tam + B.tam;   
    for(i=0; i <= A.tam-1; i++){
        aux = aux + 1;
        Novo.vetor[aux] = A.vetor[i];    
    }
  
    }else if(A.tam == Sinal){
        Novo = B;
        Novo.tam = B.tam;
    }else if(B.tam == Sinal){
        Novo = A;
        Novo.tam = A.tam;
    }
  
return Novo;
}

//reverse - inverte a ordem dos itens da lista
ListaP reverse(ListaP A){

    unsigned char chAux;
    int inicio, fim, aux;
 
    if(A.tam > Sinal){
    
        inicio = 0;
        fim = A.tam-1;

        while(inicio < fim){

            aux = A.vetor[fim];
            A.vetor[fim] = A.vetor[inicio];
            A.vetor[inicio] = aux;
            inicio++;
            fim--;   
        }
    }
return A;
}

//insert - acrescenta um item em uma posição específica (índice)
ListaP insert(ListaP A, int P, unsigned char ch){
	
	int i, k;
    int aux;
	
	if((A.tam < Max) && (A.tam >= Sinal)){
        	
			if(P >= Sinal){
        		aux = P%Max; 
        		for(i = aux; i < A.tam; i++){
            		A.vetor[i+1] = A.vetor[i];
        		}
				A.vetor[aux] = ch; 
        		A.tam = A.tam + 1;
    		}
    	
			if(P < Sinal){
        	
        		aux = P%A.tam; 
				aux = A.tam+aux; 
        			for(i = A.tam; i > aux; i--){ 
            			A.vetor[i] = A.vetor[i - 1];
        			}
				A.vetor[aux] = ch;	 
        		A.tam = A.tam + 1;
    		}	
	}
    return A;    
}

//pop - remove o item de uma posição específica (índice)
ListaP pop(ListaP A, int P){
    int i, k;
    int aux;
    if(A.tam >= Sinal){
        if(P >= Sinal){
        aux = P%Max; 
        for(i = aux; i < A.tam; i++){
            A.vetor[i] = A.vetor[i + 1];
        } 
        A.tam = A.tam - 1;
    	}
    	
		if(P < Sinal){
        	int nA;
        	nA = A.tam-1;
        	aux = P%Max; aux = nA+aux; 
        	for(i = aux; i < A.tam; i++){ 

            	A.vetor[i] = A.vetor[i + 1];
        	}	 
        	A.tam = A.tam - 1;
    	}
    }
    return A;
}

//remove - remove o primeiro item com o valor especificado
ListaP removeLista(ListaP A, unsigned char ch){
    int i;
    int k;
    unsigned char auxCh;
    bool veri = FALSE;
    if(A.tam > Sinal){
            i=0;
            k=0;
            for(i=0; i<=A.tam-1; i++){
            	while((k<A.tam) && (veri == FALSE)){
                	if(A.vetor[k] == ch){
                   		A.vetor[k] = A.vetor[A.tam-1];
                   		A.tam = A.tam - 1;
                   		veri = TRUE;
                	}
                k++;
            	}
        	} 
    } 
	return A;    
}

//index - devolve o índice 1ª ocorrência do item especificado
int indexLista(ListaP A, unsigned char ch){

    int posicao, i;
    int indice;
	bool veri = FALSE;
	
    if(A.tam > Sinal){
	    indice = fantasma;
	    i = 0;
	    while((i < A.tam) && (veri == FALSE)) {
	    	if(A.vetor[i] == ch){
	        	indice = i;
	            veri = TRUE;
			} 
	    i++;
	    } 
	}
  return indice;
}

//sort - coloca a lista em ordem não decrescente
ListaP sort(ListaP A){
    int i,k,n,aux;
    n = A.tam-1; 
	if (n > Sinal){                        
    	for(i=0;i<=n;i++){                        
        	aux = A.vetor[i];
        	k = i-1;
        	while ((k>-1) && (A.vetor[k] > aux)) {A.vetor[k+1] = A.vetor[k]; k = k - 1;}  
        	A.vetor[k+1] = aux;                                                             
    	}
    }

return A;
}
