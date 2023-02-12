#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

// Inserir um elemento no início da lista
void insertStart(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

// Inserir um elemento no final da lista
void insertEnd(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node *last = *head_ref;
  new_node->data = new_data;
  new_node->next = NULL;
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  while (last->next != NULL)
    last = last->next;
  last->next = new_node;
  return;
}

// Inserir um elemento em uma posição específica
void insertAfter(struct Node** head_ref, int position, int new_data) {
  int i;
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = NULL;

  struct Node* current = *head_ref;
  for (i = 0; current != NULL && i < position - 1; i++) {
    current = current->next;
  }

  if (current != NULL) {
    new_node->next = current->next;
    current->next = new_node;
  }
}

// Imprimir a lista
void printList(struct Node *node) {
  printf("\nListando\n");
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n\n");
}

int main() {
  struct Node* head = NULL;
  int menu_ans, answer, position;
  system("cls");
  while(menu_ans!=5){
    printf("MENU\n- 1. Adicionar no inicio\n- 2. Adicionar ao fim\n- 3. Escolher onde adicionar\n- 4. Ver lista\n- 5. Sair\nResposta: ");
    scanf("%d", &menu_ans);
    switch (menu_ans){
        case 1:
            printf("Qual numero deseja adicionar? ");
            scanf("%d", &answer);
            insertStart(&head, answer);
            system("cls");
        break;
        case 2: 
            printf("Qual numero deseja adicionar? ");
            scanf("%d", &answer);
            insertEnd(&head, answer);
            system("cls");
        break;
        case 3: 
            printList(head);
            printf("Em qual posicao deseja adicionar? ");
            scanf("%d", &position);
            printf("Qual numero deseja adicionar? ");
            scanf("%d", &answer);
            insertAfter(&head, position-1, answer);
            system("cls");
        break;
        case 4: 
            system("cls");
            printList(head);
        break;
        case 5: 
        return 0;
        break;
    }
  }
  return 0;
}
