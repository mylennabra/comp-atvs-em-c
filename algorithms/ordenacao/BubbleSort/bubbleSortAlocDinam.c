#include <stdio.h>
#include <stdlib.h>

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

void sort(){
    struct TLista *i, *j;
    int num;
    for(i= LISTA; i->next != NULL; i=i->next){
        for(j=i->next ; j!= NULL; j=j->next){
            if(i->info > j->info){
                num = j->info;
                j->info = i->info;
                i->info = num;
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
    sort();
	printf("\nDEPOIS:\t\t");
    display();
	printf("\n\n===============================================================================\n\n");
    return 0;
}