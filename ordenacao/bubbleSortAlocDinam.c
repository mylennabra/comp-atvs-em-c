#include<stdio.h>
#include<stdlib.h>

// Ordenação de números com alocação dinâmica

int main() {
   	int *p;
   	int qt, n, i, j, aux;

	printf("Quantos numeros deseja ordenar? ");
	scanf("%d", &n);
	p = (int*)calloc(n, sizeof(int));

	for (i = 0; i < n; i++) {
		printf("%dº - ", i+1);
		scanf("%d", (p+i));
	}

	for (i = 0; i < n-1; i++) {
		for (j = i+1; j < n; j++) {
			if (p[i] > p[j]) {
			   aux = p[i];
			   p[i] = p[j];
			   p[j] = aux;
			}
		} 
	} 

	for (i = 0; i < n; i++) {
		printf("%d ", p[i]);
	}   	
}