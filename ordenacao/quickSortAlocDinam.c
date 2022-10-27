#include <stdio.h>
#include <stdlib.h>

typedef struct TLista{
	struct TLista *next;
	struct TLista *prev;
	struct TLista *fim;
	int pivo;
	int info;
}TLista; 

typedef TLista * Lista;

TLista * partition(Lista *LISTA, TLista * inicio, TLista * fim){
    TLista *lista, *pivo; 
    pivo = lista->fim;
    TLista *atual, *temp;
    TLista * menores = inicio - 1;
	for (atual = inicio; atual < fim; atual++){
		if (atual->info < pivo->info){
			menores++;
			temp->info = atual->info;
			atual->info = menores->info;
			menores->info = temp->info;
		}
	}
    TLista *meio = menores - 1;
	temp = pivo;
	pivo = meio;
	meio = temp;
	return meio;
}

void quickSort(Lista *LISTA, TLista * inicio, TLista * fim){
	if (inicio >= fim){
		return;
    }
	
	TLista * meio = partition(LISTA,inicio,fim);
	quickSort(LISTA,inicio, meio - 1);
	quickSort(LISTA, meio + 1, fim);
}


int vazia(Lista *LISTA){
	if(*LISTA == 0)
		return 1;
	else
	return 0;
}

TLista *aloca(Lista *LISTA){
	(*LISTA) = malloc(sizeof(TLista));
    return (*LISTA);
}

TLista *inicia(Lista *LISTA, int leitura){
    (*LISTA)->prev = *LISTA;
    (*LISTA)->next = *LISTA;
    (*LISTA)->info = leitura;
}

void enqueueFim(Lista *LISTA, int leitura){
 	if(vazia(LISTA)){
        aloca(LISTA);
        inicia(LISTA, leitura);
 	}else{
        TLista * tmp, *last;
		tmp = *LISTA;
	  	while(tmp->next != *LISTA){
			tmp = tmp->next;
        }
        tmp->next = malloc(sizeof(TLista));
        last = tmp->next;
        last->prev = tmp;
        last->next = *LISTA;
        last->info = leitura;
        (*LISTA)->prev = last;

	}
}

void listar(Lista *LISTA){
 	//system("clear");
 	if(vazia(LISTA)){
  		printf("Lista vazia!\n\n");
  		return;
 	}
	TLista *tmp;
	tmp = *LISTA;

	//printf("Lista:\n");
    
    do{
  		//printf("[%5d] = %d \n", tmp, tmp->info);
  		printf("%d \t", tmp->info);
        tmp = tmp->next;
 	} while(tmp != *LISTA);

 	printf("\n");
}

int main(void){
    Lista *LISTA;
    Lista p=NULL;
    LISTA = &p;
	int leitura;

 	if(!LISTA){
  		printf("Sem memoria disponivel!\n");
  		exit(1);
 	}else{
        while(1){
		    printf("Informe o valor: ");
		    scanf("%d",&leitura);
		    if (leitura == 0){
			    break;
            }
    	    enqueueFim(LISTA, leitura);
	    }
        printf("\n================================================================================\n");
        printf("\nANTES:\t\t");
		listar(LISTA);
		quickSort(LISTA, 0, (*LISTA)->fim); 
        printf("\nDEPOIS:\t\t");
		listar(LISTA);
        printf("\n===============================================================================\n\n");
	 	return 0;
 	}
}