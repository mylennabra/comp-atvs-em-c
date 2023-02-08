#include <stdio.h>
#include <stdlib.h>

struct LISTA{
    int info;
    struct LISTA *next;
    struct LISTA *prev;
};

void swap (int *a, int *b ){
	int t = *a; 
    *a = *b; 
    *b = t;
}

struct LISTA *lastLISTA(struct LISTA *last){
    while (last && last->next)
    last = last->next;
    return last;
}
 
struct LISTA* partition(struct LISTA *l, struct LISTA *h){
    int x = h->info;
    struct LISTA *i = l->prev;
    struct LISTA *j;
    for (j = l; j != h; j = j->next){
        if (j->info <= x){
            i = (i == NULL) ? l : i->next;
            swap(&(i->info), &(j->info));
        }
    }
    i = (i == NULL) ? l : i->next; 
    swap(&(i->info), &(h->info));
    return i;
}
 
void quickSort(struct LISTA *head, struct LISTA *list){
    if (list != NULL && head != list && head != list->next){
        struct LISTA *p = partition(head, list);
        quickSort(head, p->prev);
        quickSort(p->next, list);
    }
}
 
void printList(struct LISTA *head){
    while (head){
        printf("%d ", head->info);
        head = head->next;
    }
    printf("\n");
}

void push(struct LISTA** head_ref, int new_info){
    struct LISTA* new_LISTA = (struct LISTA*)
    malloc(sizeof(struct LISTA));
    new_LISTA->info = new_info;
    new_LISTA->prev = NULL;
    new_LISTA->next = (*head_ref);
    if ((*head_ref) != NULL) (*head_ref)->prev = new_LISTA ;
    (*head_ref) = new_LISTA;
}

int main(void){
    struct LISTA *a = NULL;
	int info;
	
	while(1){
		printf("Informe o valor: ");
		scanf("%d", &info);
		if (info == 0){
			break;
		}
		push(&a, info);
	}

	printf("\n=======================================================\n");
	printf("\nANTES:\t\t");
	printList(a);
    struct LISTA *h = lastLISTA(a);
	quickSort(a, h); 
	printf("\nDEPOIS:\t\t");
	printList(a);
	printf("\n======================================================\n\n");
    return 0;
}