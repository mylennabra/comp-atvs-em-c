#include<stdio.h>
#include<stdlib.h>

// Ordenação de números com alocação estática

#include <stdio.h>
#define TAM 5

int vetor[TAM] = {4,2,5,1,3};


void bubbleSort(int v[],int tamanho){
	int i,j,temp;
	for (j = 0; j < tamanho; j++){
		for (i = 0; i < tamanho - 1; i++){
			if (v[i] > v[i + 1]){
				temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
			}
		}
	}
}

void listar(int v[],  int tamanho){
	int i;
	for (i = 0; i < tamanho;i++){
		printf("%d ", v[i]);
	}
	printf("\n\n");
}

int main(){
    printf("\nAntes: ");
	listar(vetor, TAM); 
    bubbleSort(vetor,TAM);
    printf("Depois: ");
	listar(vetor, TAM); 
	return 0;
}
