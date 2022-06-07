
#include "Lucas_Graziano_ListaP.h"

int main(){

	ListaP listaA = New();
	ListaP listaB = New();
	ListaP listaC = New();
	
	int tam = 0;
	int i = 0;
	int maior = 0;
	int menor = 0; 		
	int vezes = 0;
	
    listaA = append(listaA, '1');
	listaA = insert(listaA, 0, '4');
    listaA = insert(listaA, -1, '2');
    listaA = insert(listaA, -2, '3');
    listaA = insert(listaA, -3, '5');
    listaA = insert(listaA, -4, '2');
    listaA = append(listaA, '1');

	//printf("%d", tam);
	
	//listaA = insert(listaA, -1, 2);
	//tam = len(listaA);
	//printf("%d", tam);
	
	//listaA = insert(listaA, -2, 3);
	//tam = len(listaA);
	//printf("%d", tam);
	
	listaA = insert(listaA, -5, 4);
    
	//tam = len(listaA);
	//printf("%d", tam);
	
	//listaA = insert(listaA, -4, 5);
	//tam = len(listaA);
	
	//listaA = insert(listaA, -5, 6);
	//tam = len(listaA);
	
	//listaA = insert(listaA, -6, 7);
	//tam = len(listaA);

	//listaA = insert(listaA, -7, 8);
	//tam = len(listaA);	
	
	
	//i = indexLista(listaA, 21, 1);
	//printf("%d", i);	
	
	listaB = copy(listaB, listaA);
	
	//vezes = count(listaB, 5);
	//printf("%d,", vezes);
	
	maior = max(listaB);	
	menor = min(listaB);
	
	//printf("%d, %d", maior, menor);
	
	listaC = extend(listaA, listaB);
	vezes = count(listaC, 5);
	//printf("%d,", vezes);
	
	listaC = reverse(listaC);

	
	//for(i = 0; i<=listaA.tam-1; i++){
	//	printf("%c ",listaA.vetor[i]);
	//}
	
	listaC = sort(listaC);
	

	tam = len(listaC);
	//printf("\n%d", tam);
	
	//for(i = 0; i<=Max-1; i++){
	//	printf("%c ",listaC.vetor[i]);
	//}
	//printf("\n\n\n");
	
	
	listaC = pop(listaC, -1);
	listaC = pop(listaC, -5);
	
	//for(i = 0; i<=Max-1; i++){
	//	printf("%c ",listaC.vetor[i]);
	//}
	
	
	//tam = len(listaC);
	//printf("\n%d", tam);
	//printf("\n\n\n");	

	//int j = indexLista(listaC, 5);
	//printf("%d", j);	
	
	return 0;


}