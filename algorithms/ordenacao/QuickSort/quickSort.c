#include <stdio.h>
#define TAM 5

int vetor[TAM] = {5,4,3,2,1};

int partition(int v[],int inicio, int fim){
	int pivo = v[fim];
	int atual,temp;
	int menores = inicio - 1;
	for (atual = inicio; atual < fim; atual++){
		if (v[atual] < pivo){
			menores++;
			temp = v[atual];
			v[atual] = v[menores];
			v[menores] = temp;
		}
	}
	int meio = menores + 1;
	temp = v[fim];
	v[fim] = v[meio];
	v[meio] = temp;
	return meio;
}

void quickSort(int v[],int inicio, int fim){
	if (inicio >= fim)
		return;
	
	int meio = partition(v,inicio,fim);
	quickSort(v,inicio, meio - 1);
	quickSort(v, meio + 1, fim);
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
	quickSort(vetor, 0, TAM - 1); 
	listar(vetor, TAM); 
	return 0;
}
