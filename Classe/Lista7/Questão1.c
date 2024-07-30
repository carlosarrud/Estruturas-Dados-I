#include <stdio.h>
#include <stdlib.h>

typedef enum genero {
    FEMININO = 1,
    MASCULINO,
    NEUTRO
} GENERO;

typedef struct pessoa {
    char nome[21];
    int idade;
    GENERO genero;
} PESSOA;

// Função para coletar os dados da pessoa
void preencher(PESSOA *fm) {
    printf("Informe o seu nome: ");
    scanf(" %[^\n]", fm->nome);
    printf("Informe a sua idade: ");
    scanf("%d", &fm->idade);

    int generoValido = 0;
    while (!generoValido) {
        printf("Informe o seu gênero: \n1 - Feminino\n2 - Masculino\n3 - Neutro\n ");
        scanf("%d", &fm->genero);

        switch (fm->genero) {
            case FEMININO:
                generoValido = 1;
                printf("Feminino\n");
                break;
            case MASCULINO:
                generoValido = 1;
                printf("Masculino\n");
                break;
            case NEUTRO:
                generoValido = 1;
                printf("Neutro\n");
                break;
            default:
                printf("Gênero inválido. Por favor, digite 1, 2 ou 3.\n");
                break;
        }
    }
}

// Função para imprimir os dados da pessoa
void imprimir(PESSOA *fm) {
    printf("NOME: %s\nIDADE: %d\n", fm->nome, fm->idade);

    switch (fm->genero) {
        case FEMININO:
            printf("GÊNERO: Feminino\n");
            break;
        case MASCULINO:
            printf("GÊNERO: Masculino\n");
            break;
        case NEUTRO:
            printf("GÊNERO: Neutro\n");
            break;
    }
}

int main() {
    PESSOA fm;

    preencher(&fm);
    imprimir(&fm);

    return 0;
}
