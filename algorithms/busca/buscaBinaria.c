#include <stdio.h>
#define TAM 5

int vetor[TAM] = {1,2,3,4,5};


int buscaBinaria(int v[], int key, int tamanho){
	int inicio = 0;
	int fim = tamanho - 1;
	int meio;
	while(inicio <= fim){
		meio = (inicio + fim)/2;
		if (v[meio] == key)
			return meio;
		if (key > v[meio])
			inicio = meio + 1;
		else
			fim = meio - 1;
	}
	return -1;
}


void listar(int v[],  int tamanho){
	int i;
	printf("\n\nListando\n");
	for (i = 0; i < tamanho;i++){
		printf("%d ", v[i]);
	}
}

int main(){

	int chave;
	int posicao;

	while(1){
        printf("\nDigite o valor que seja encontrar:");
		scanf("%d",&chave);
		posicao = buscaBinaria(vetor,chave,TAM);
		if (posicao == -1)
			printf("\n\nValor nao encontrado!\n\n");
		else
			printf("\n\nValor encontrado na posicao %d ",posicao);
	}

	return 0;
}

