#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

typedef struct No { Item dados;
    struct No* proximo;
} No;


Item inventario[10];

int numItens = 0;

No* Lista = NULL;


int comparacaoSequencial = 0;
int comparacoesBinaria = 0;

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
    int escolha;
    printf("Busca\n");
    printf("1. Nome\n");
    printf("2. Tipo\n ");
    printf(" Escolha");
    scanf("%d", &escolha);

   if (escolha == 1){
    char nome [30];
    printf("O que procura? ");
    scanf("%s", nome);
    int encontrado = 0;
    for (int i = 0; i< numItens; i++) {
        if (strcmp(inventario[i].nome, nome) ==0){
            printf("Achou!!: Nome: %s, Tipo: %s, Quantidade: %d\n", inventario[i].nome, inventario[i].tipo, inventario[i].quantidade);
            encontrado = 1;
    }
   }
   if (!encontrado) {
    printf("Não tem esse loot\n");
   }
   
} else if (escolha == 2){
    char tipo [20];
    printf("Qual tipo do loot? ");
    scanf("%s", tipo);
    int encontrado = 0;
    for (int i = 0; i < numItens; i++) {
        if (strcmp(inventario[i].tipo, tipo)==0){
            printf("Item encontrado: Nome: %s, Tipo: %s, Quantidade: %d\n", inventario[i].nome, inventario[i].tipo, inventario[i].quantidade);
                encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("não tem essse Loot.\n");
    }
}else {
    printf("opção inválida.\n");
}
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

void inserirItemLista() {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    printf("Digite o nome do item: ");
    scanf("%s", novo->dados.nome);
    printf("Digite o tipo do Item (ex: armas, kits ou munições): ");
    scanf("%s", novo->dados.tipo);
    printf("Digite a quantidade: ");
    scanf("%d", &novo->dados.quantidade);
    novo->proximo = Lista;
    Lista = novo;
    printf("Coletado!\n");
}

void removerItemLista() {
    char nome[30];
    printf("O que quer tirar?: ");
    scanf("%s", nome);
    No* atual = Lista;
    No* anterior = NULL;
    while (atual != NULL) {
        if (strcmp(atual->dados.nome, nome) == 0) {
            if (anterior == NULL) {
                Lista = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            printf("Item removido com sucesso!\n");
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Item não encontrado\n");
}

void listarItensLista() {
    printf("\n--- Itens na lista ---\n");
    if (Lista == NULL) {
        printf("Lista vazia.\n");
    } else {
        No* atual = Lista;
        while (atual != NULL) {
            printf("Nome: %s, Tipo: %s, Quantidade: %d\n", atual->dados.nome, atual->dados.tipo, atual->dados.quantidade);
            atual = atual->proximo;
        }
    }
    printf("\n");
}

void buscarItemLista() {
    char nome[30];
    printf("Nome do Loot: ");
    scanf("%s", nome);
    comparacaoSequencial = 0;
    No* atual = Lista;
    while (atual != NULL) {
        comparacaoSequencial++;
        if (strcmp(atual->dados.nome, nome) == 0) {
            printf("Loot encontrado: Nome: %s, Tipo: %s, Quantidade: %d\n", atual->dados.nome, atual->dados.tipo, atual->dados.quantidade);
            printf("Comparações realizadas: %d\n", comparacaoSequencial);
            return;
        }
        atual = atual->proximo;
    }
    printf("Loot não encontrado.\n");
    printf("Comparações realizadas: %d\n", comparacaoSequencial);
}

void ordenarVetor() {
    for (int i = 0; i < numItens - 1; i++) {
        for (int j = 0; j < numItens - i - 1; j++) {
            if (strcmp(inventario[j].nome, inventario[j + 1].nome) > 0) {
                Item temp = inventario[j];
                inventario[j] = inventario[j + 1];
                inventario[j + 1] = temp;
            }
        }
    }
    printf("Inventário ordenado por nome.\n");
}

void buscarSequencialVetor() {
    char nome[30];
    printf("Digite o nome do Loot a buscar: ");
    scanf("%s", nome);
    comparacaoSequencial = 0;
    for (int i = 0; i < numItens; i++) {
        comparacaoSequencial++;
        if (strcmp(inventario[i].nome, nome) == 0) {
            printf("Loot encontrado: Nome: %s, Tipo: %s, Quantidade: %d\n", inventario[i].nome, inventario[i].tipo, inventario[i].quantidade);
            printf("Comparações realizadas: %d\n", comparacaoSequencial);
            return;
        }
    }
    printf("Loot não encontrado.\n");
    printf("Comparações realizadas: %d\n", comparacaoSequencial);
}

void buscarBinariaVetor() {
    char nome[30];
    printf("Digite o nome do Loot a buscar: ");
    scanf("%s", nome);
    comparacoesBinaria = 0;
    int esquerda = 0, direita = numItens - 1;
    while (esquerda <= direita) {
        comparacoesBinaria++;
        int meio = esquerda + (direita - esquerda) / 2;
        int cmp = strcmp(inventario[meio].nome, nome);
        if (cmp == 0) {
            printf("Loot encontrado: Nome: %s, Tipo: %s, Quantidade: %d\n", inventario[meio].nome, inventario[meio].tipo, inventario[meio].quantidade);
            printf("Comparações realizadas: %d\n", comparacoesBinaria);
            return;
        } else if (cmp < 0) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    printf("Loot não encontrado.\n");
    printf("Comparações realizadas: %d\n", comparacoesBinaria);
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
