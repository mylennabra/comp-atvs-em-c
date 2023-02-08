#include <stdio.h>
#include <stdlib.h>

typedef struct TLista{
	struct TLista *next;
	struct TLista *prev;
	int info;
}TLista; 

typedef TLista * Lista;

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

void insertionSort(Lista *LISTA){
    TLista *lista, *tmp1, *tmp2, *troca, *troca_prev, *troca_next;
    lista = lista->next;
    while(lista!=*LISTA){
        tmp1=lista;
        tmp2=lista->prev;
        lista=lista->next;
        while (tmp2->next != *LISTA && tmp2->info > tmp1->info){
            troca_prev = tmp2->prev;
            troca_next = tmp1->next;
            troca_prev->next = tmp1;
            tmp1->next = tmp2;
            tmp2->next = troca_next;
            troca_next->prev = tmp2;
            tmp2->prev = tmp1;
            tmp1->prev = troca_prev;
            tmp2 = tmp1;
            tmp1 = tmp2->next;
            if(tmp1==*LISTA){
                *LISTA = tmp2;
            }
            tmp2=tmp2->prev;
            tmp1 = tmp1->prev;
        }
    }
}

void listar(Lista *LISTA){
 	if(vazia(LISTA)){
  		printf("Lista vazia!\n\n");
  		return;
 	}
	TLista *tmp;
	tmp = *LISTA;
    
    do{
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
		insertionSort(LISTA);
        printf("\nDEPOIS:\t\t");
		listar(LISTA);
        printf("\n===============================================================================\n\n");
	 	return 0;
 	}
}