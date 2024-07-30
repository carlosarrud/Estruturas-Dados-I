#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAXIMO_NOME 100

int i;

void alocar_memoria(int np, char ***nomes, int **idades) {
    *nomes = (char **)malloc(np * sizeof(char *));
    for (i = 0; i < np; i++) {
        (*nomes)[i] = (char *)malloc(TAMANHO_MAXIMO_NOME * sizeof(char));
    }
    *idades = (int *)malloc(np * sizeof(int));
}

void ler_dados(int np, char **nomes, int *idades) {
    for (i = 0; i < np; i++) {
        printf("Digite o nome completo da %dº pessoa: ", i + 1);
        scanf(" %[^\n]", nomes[i]);
        printf("Digite a idade da %dº pessoa: ", i + 1);
        scanf("%d", &idades[i]);
    }
}

void exibir_dados(int np, char **nomes, int *idades) {
    printf("\nNomes e idades informados:\n");
    for (i = 0; i < np; i++) {
        printf("%dº Pessoa:\n Nome: %s, Idade: %d\n", i + 1, nomes[i], idades[i]);
    }
}

int main() {
    int np;
    char **nomes;
    int *idades;

    // Solicitar o número de pessoas
    printf("Digite o número de pessoas: ");
    scanf("%d", &np);

    // Alocar memória para nomes e idades
    alocar_memoria(np, &nomes, &idades);

    // Ler os dados das pessoas
    ler_dados(np, nomes, idades);

    // Exibir os dados das pessoas
    exibir_dados(np, nomes, idades);

    // Liberar a memória alocada
    for (i = 0; i < np; i++) {
        free(nomes[i]);
    }
    free(nomes);
    free(idades);

    return 0;
}
