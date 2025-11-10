#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

Item inventario[10];

int numItens = 0;

void listarItens() {
    printf("\n--- Itens no inventário ---\n");
    if (numItens == 0) {
        printf("Inventário vazio.\n");
    } else {
        for (int i = 0; i < numItens; i++) {
            printf("Nome: %s, Tipo: %s, Quantidade: %d\n", inventario[i].nome, inventario[i].tipo, inventario[i].quantidade);
        }
    }
    printf("\n");
}

void buscarItem() {
    char nome[30];
    printf("Digite o nome do item a buscar: ");
    scanf("%s", nome);
    for (int i = 0; i < numItens; i++) {
        if (strcmp(inventario[i].nome, nome) == 0) {
            printf("Item encontrado: Nome: %s, Tipo: %s, Quantidade: %d\n", inventario[i].nome, inventario[i].tipo, inventario[i].quantidade);
            return;
        }
    }
    printf("Item não encontrado no inventário.\n");
}

void inserirItem() {
    if (numItens >= 10) {
        printf("Inventario Cheio! Não é possivel adicionar mais itens.\n");
        return;
    }
    printf("digite o nome do item: ");
    scanf("%s", inventario[numItens].nome);
    printf("Digite o tipo do Item (ex: armas, kits ou munições): ");
    scanf("%s", inventario[numItens].tipo);
    printf("digite a quantidade: ");
    scanf("%d", &inventario[numItens].quantidade);
    numItens++;
    printf("Coletado!\n");
    listarItens();
}

void removerItem(){
    char nome[30];
    printf("O que quer tirar?: ");
    scanf("%s", nome);
    for (int i = 0; i < numItens; i++) {
        if (strcmp(inventario[i].nome, nome) == 0){
            for (int j = i; j < numItens - 1; j++) {
                inventario[j] = inventario[j + 1];
            }
            numItens--;
            printf("item removido com sucesso!\n");
            listarItens();
            return;
        }
    }
    printf("item não encontrado\n");
}

int main(){
    int opcao;
    do{
        printf("\n-------Mochila-------\n");
        printf("1. pegar Loot\n");
        printf("2. Remover item\n");
        printf("3. ver o loot\n");
        printf("4. Buscar Looot\n");
        printf("5. sair\n");
        printf("Escolha uma opção: \n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                inserirItem();
                break;
            case 2:
                removerItem();
                break; 
            case 3:
                listarItens();
                break;
            case 4:
                buscarItem();
                break;
            case 5:
                printf("Saindo do jogo...\n");
                break;
            default: 
                printf("Nem dá. Tenta mais uma vez\n");
        }
    }while (opcao != 5);
    return 0;
}
