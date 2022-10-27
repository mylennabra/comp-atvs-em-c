#include <stdio.h>
#define TAM 5

int vetor[TAM] = {5,4,3,2,1};

void insertionSort(int v[],int tamanho){
	int i,j,temp;
	for (i = 1; i < TAM; i++){
		temp = v[i];
		j = i - 1;
		while (j >= 0 && v[j] > temp){
			v[j+1] = v[j];
			j--;
		}
		v[j + 1] = temp;
	}
}


void listar(int v[],  int tamanho){
	int i;
	printf("\n\nListando\n");
	for (i = 0; i < tamanho;i++){
		printf("%d ", v[i]);
	}
}

int main(){

	listar(vetor, TAM); 
	insertionSort(vetor, TAM); 
	listar(vetor, TAM); 
	return 0;
}