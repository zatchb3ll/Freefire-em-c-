#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade;
} Componente;

Componente componentes[20];
int numComponentes = 0;

int comparacoesBubble = 0;
int comparacoesInsertion = 0;
int comparacoesSelection = 0;
int comparacoesBinaria = 0;

void mostrarComponentes() {
    printf("\n--- Componentes da Torre ---\n");
    if (numComponentes == 0) {
        printf("Nenhum componente cadastrado.\n");
    } else {
        for (int i = 0; i < numComponentes; i++) {
            printf("Nome: %s, Tipo: %s, Prioridade: %d\n", componentes[i].nome, componentes[i].tipo, componentes[i].prioridade);
        }
    }
    printf("\n");
}
void bubbleSortNome() {
    comparacoesBubble = 0;
    for (int i = 0; i < numComponentes - 1; i++) {
        for (int j = 0; j < numComponentes - i - 1; j++) {
            comparacoesBubble++;
            if (strcmp(componentes[j].nome, componentes[j + 1].nome) > 0) {
                Componente temp = componentes[j];
                componentes[j] = componentes[j + 1];
                componentes[j + 1] = temp;
            }
        }
    }
    printf("Ordenação por nome concluída. Comparações: %d\n", comparacoesBubble);
}
void insertionSortTipo() {
    comparacoesInsertion = 0;
    for (int i = 1; i < numComponentes; i++) {
        Componente chave = componentes[i];
        int j = i - 1;
        while (j >= 0) {
            comparacoesInsertion++;
            if (strcmp(componentes[j].tipo, chave.tipo) > 0) {
                componentes[j + 1] = componentes[j];
                j--;
            } else {
                break;
            }
        }
        componentes[j + 1] = chave;
    }
    printf("Ordenação por tipo concluída. Comparações: %d\n", comparacoesInsertion);
}
void selectionSortPrioridade() {
    comparacoesSelection = 0;
    for (int i = 0; i < numComponentes - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < numComponentes; j++) {
            comparacoesSelection++;
            if (componentes[j].prioridade < componentes[minIdx].prioridade) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            Componente temp = componentes[i];
            componentes[i] = componentes[minIdx];
            componentes[minIdx] = temp;
        }
    }
    printf("Ordenação por prioridade concluída. Comparações: %d\n", comparacoesSelection);
}
void buscaBinariaPorNome(char nomeBusca[]) {
    comparacoesBinaria = 0;
    int esquerda = 0, direita = numComponentes - 1;
    while (esquerda <= direita) {
        comparacoesBinaria++;
        int meio = esquerda + (direita - esquerda) / 2;
        int cmp = strcmp(componentes[meio].nome, nomeBusca);
        if (cmp == 0) {
            printf("Loot encontrado: Nome: %s, Tipo: %s, Prioridade: %d\n", componentes[meio].nome, componentes[meio].tipo, componentes[meio].prioridade);
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
void medirTempo(void (*algoritmo)()) {
    clock_t inicio = clock();
    algoritmo();
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.6f segundos\n", tempo);
}
void cadastrarComponente() {
    if (numComponentes >= 20) {
        printf("Limite de componentes atingido!\n");
        return;
    }
    printf("Digite o nome do Loot: ");
    scanf("%s", componentes[numComponentes].nome);
    printf("Digite o tipo do componente (ex: controle, suporte, propulsao): ");
    scanf("%s", componentes[numComponentes].tipo);
    printf("Digite a prioridade (1-10): ");
    scanf("%d", &componentes[numComponentes].prioridade);
    numComponentes++;
    printf("Componente cadastrado!\n");
    mostrarComponentes();
}

int main() {
    int opcao;
    do {
        printf("\n------- Sistema de Torre -------\n");
        printf("1. Cadastrar Loot\n");
        printf("2. Mostrar Loot\n");
        printf("3. Ordenar por nome \n");
        printf("4. Ordenar por tipo \n");
        printf("5. Ordenar por prioridade \n");
        printf("6. Buscar componente-chave \n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrarComponente();
                break;
            case 2:
                mostrarComponentes();
                break;
            case 3:
                medirTempo(bubbleSortNome);
                mostrarComponentes();
                break;
            case 4:
                medirTempo(insertionSortTipo);
                mostrarComponentes();
                break;
            case 5:
                medirTempo(selectionSortPrioridade);
                mostrarComponentes();
                break;
            case 6: {
                char nome[30];
                printf("Digite o nome do componente-chave: ");
                scanf("%s", nome);
                buscaBinariaPorNome(nome);
                break;
            }
            case 7:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 7);
    return 0;
}
