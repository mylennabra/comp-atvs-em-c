#include <stdio.h>
#define TAM 5

int vetor[TAM] = {1,2,3,4,5};


int buscaLinear(int v[], int key, int tamanho){
	int i = 0, fim = tamanho - 1;
	for(i=0;i <= fim;i++){
		if (v[i] == key)
			return i;
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
        printf("\nDigite o valor que seja encontrar: ");
		scanf("%d",&chave);
		posicao = buscaLinear(vetor,chave,TAM);
		if (posicao < 0)
			printf("\n\nValor nao encontrado!\n\n");
		else
			printf("\n\nValor encontrado na posicao %d \n",posicao+1);
	}

	return 0;
}

