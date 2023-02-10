#include <stdio.h>

// Ordenação Selection Sort com alocação estática

#define TAM 5

int vetor[TAM] = {9,5,2,4,8};
long trocas = 0;
long passos = 0;

void selectionSort(int v[],int tamanho){
	int i,j,temp, menor;
	for (i = 0; i < tamanho -1; i++){
		menor = i;
		for (j = i + 1; j < tamanho; j++){
			passos++;
			if (v[j] < v[menor]){
				menor = j;
			}
		}
		trocas++;
		temp = v[i];
		v[i] = v[menor];
		v[menor] = temp;
	}
}

void listar(int v[],  int tamanho){
	int i;
	for (i = 0; i < tamanho;i++){
		printf("%d ", v[i]);
	}
}

int main(){
	printf("\n\nAntes:\n");
	listar(vetor, TAM); 
	printf("\n\nDepois:\n");
	selectionSort(vetor, TAM); 
	listar(vetor, TAM); 
	printf("\n\nTrocas: %ld\nPassos: %ld\n\n",trocas,passos);
	return 0;
}
