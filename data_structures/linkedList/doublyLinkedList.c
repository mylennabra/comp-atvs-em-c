#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;

node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insertStart(int data) {
    node *new_node = create_node(data);
    if (head == NULL) {
        head = tail = new_node;
        return;
    }
    head->prev = new_node;
    new_node->next = head;
    head = new_node;
}

void insertEnd(int data) {
    node *new_node = create_node(data);
    if (tail == NULL) {
        head = tail = new_node;
        return;
    }
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
}

void insertAfter(int data, int position) {
    if (position == 1) {
        insertStart(data);
        return;
    }
    node *new_node = create_node(data);
    node *temp = head;
    int i;
    for (i = 1; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = new_node;
        new_node->next = temp->next;
    } else {
        tail = new_node;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

void delete_at_head() {
    if (head == NULL) {
        return;
    }
    if (head == tail) {
        free(head);
        head = tail = NULL;
        return;
    }
    node *temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
}

void delete_at_tail() {
    if (tail == NULL) {
        return;
    }
    if (head == tail) {
        free(tail);
        head = tail = NULL;
        return;
    }
    node *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(temp);
}

void delete_at_position(int position) {
    if (head == NULL) {
        return;
    }
    if (position == 1) {
        delete_at_head();
        return;
    }
}

void printList() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
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
            insertStart(answer);
            system("cls");
        break;
        case 2: 
            printf("Qual numero deseja adicionar? ");
            scanf("%d", &answer);
            insertEnd(answer);
            system("cls");
        break;
        case 3: 
            printList(head);
            printf("Em qual posicao deseja adicionar? ");
            scanf("%d", &position);
            printf("Qual numero deseja adicionar? ");
            scanf("%d", &answer);
            insertAfter(answer, position);
            system("cls");
        break;
        case 4: 
            system("cls");
            printList();
        break;
        case 5: 
        return 0;
        break;
    }
  }
  return 0;
}

