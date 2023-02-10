#include <stdio.h>
#include <stdlib.h>

// Ordenação Selection Sort com alocação dinâmica

typedef struct TLista{
	struct TLista *next;
	int info;
}TLista;

typedef TLista * Lista;
struct TLista *lista, *LISTA = NULL, *temp;


void enqueueFim(int leitura){
	lista = (struct TLista*)malloc(sizeof(struct TLista));
	lista->info = leitura;
	lista->next = NULL;
	if (LISTA == NULL){
		LISTA = lista;
	}else{
		temp = LISTA;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = lista;
	}
}

void display()
{
    if(LISTA == NULL){
        printf("Lista vazia!\n\n");
  		return;
    }else{
        temp = LISTA;
        while(temp != NULL){
            printf("%d \t", temp->info);
            temp = temp->next;
        }
    }
}

void selectionSort(){
    struct TLista *i, *j, *menor;
    int num;
    for(i=LISTA; i->next != NULL; i=i->next){
		menor = i;
        for(j=i->next ; j!= NULL; j=j->next){
			if (j->info < i->info){
                temp = i->info;
				i->info = j->info;
                j->info = temp;
			}
		}
    }
}

int main(){
	Lista *LISTA;
	int leitura;

	while(1){
		printf("Informe o valor: ");
		scanf("%d",&leitura);
		if (leitura == 0){
			break;
		}
		enqueueFim(leitura);
	}
	printf("\n================================================================================\n");
	printf("\nANTES:\t\t");
    display();
    selectionSort();
	printf("\nDEPOIS:\t\t");
    display();
	printf("\n\n===============================================================================\n\n");
    return 0;
}