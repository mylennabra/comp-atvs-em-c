#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int pilha[SIZE]; 

void push(int p[], int info, int tamanho){
    int i;
    for (i = 0; i < tamanho; i++){
        if (p[i] == 0){
            p[i] = info;
            return;
        }
    }
    return;
}

void printList(int p[], int tamanho){
    int i;
    printf("\n\nListando\n");
    for (i = tamanho -1; i >= 0; i--){
        if (p[i] != 0)
            printf("%d ",p[i]);
    }
    printf("\n\n");
}

int buscar(int p[], int tamanho, int chave){
    int i;
    for (i = tamanho - 1; i >= 0; i--){
        if (p[i] == chave)
           return i;
    }
    return -1;
}

void pop(int p[], int tamanho){
    int i;
    for (i = tamanho - 1;i >= 0;i--){
        if (p[i] != 0){
            p[i] = 0;
            return;
        }   
    }
}


int main(int argc, char** argv) {

    int i,leitura,key, menu_ans;
    system("cls");


    while(menu_ans!=5){
        printf("MENU\n- 1. Preencher pilha\n- 2. Excluir\n- 3. Buscar na pilha\n- 4. Ver lista\n- 5. Sair\nResposta: ");
        scanf("%d", &menu_ans);
        switch (menu_ans){
            case 1:
                for(i=0;i<SIZE;i++){
                    printf("Informe %d valores: ", SIZE);
                    scanf("%d",&leitura);
                    if (leitura == 0){
                        break;
                    }
                    push(pilha,leitura,SIZE);
                }
                system("cls");
                printList(pilha, SIZE);
            break;
            case 2: 
                pop(pilha, SIZE);
                system("cls");
                printList(pilha, SIZE);
            break;
            case 3: 
                system("cls");
                printf("\nQual numero deseja buscar? ");
                scanf("%d",&key);
                int posicao = buscar(pilha, SIZE,key);
                if (posicao == -1){
                    printf("Chave da busca não encontrada na pilha\n\n");
                } else {
                    printf("Chave encontrada na posicao: %d\n\n", posicao);
                }
            break;
            case 4: 
                system("cls");
                printList(pilha,SIZE);
            break;
            case 5: 
                return 0;
            break;
        }
    }

    return (EXIT_SUCCESS);
}