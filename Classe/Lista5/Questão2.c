#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa {
    char nome[100];
    char documento[20];
    int idade;
} Pessoa;

void limpar_buffer() {
    int i;
    for (i = 0; (i = getchar()) != '\n' && i != EOF;) {
    }
}

//Função para preencher as informações da pessoa
void preencherPessoa(Pessoa *p) {
    printf("Informe o nome: ");
    limpar_buffer();
    scanf(" %[^\n]", p->nome);

    printf("Informe o número do documento: ");
    limpar_buffer();
    scanf(" %[^\n]", p->documento);

    do {
        printf("Informe a idade: ");
        scanf("%d", &(p->idade));
        if (p->idade <= 0) {
            printf("Idade inválida. Digite uma idade maior que zero.\n");
        }
    } while (p->idade <= 0);
}

//Função para imprimir as informações da pessoa
void imprimirPessoa(const Pessoa *p) {
    printf("Nome: %s\n", p->nome);
    printf("Documento: %s\n", p->documento);
    printf("Idade: %d\n", p->idade);
}

//Função para atualizar idade
void atualizarIdade(Pessoa *p, int novaIdade, int n) {
    if (novaIdade <= 0) {
        printf("Idade inválida. Digite uma idade maior que zero.\n");
        return;
    }
    if (n < 0 || n >= n) {
        printf("ID inválido.\n");
        return;
    }
    p->idade = novaIdade;
}

//Funçao para altera a pessoa mais velha e a mais nova
void encontrarPessoaMaisVelhaEMaisNova(Pessoa *pessoas, int tamanho) {
    if (tamanho <= 0) {
        printf("Nenhuma pessoa encontrada.\n");
        return;
    }

    Pessoa *maisVelha = &pessoas[0];
    Pessoa *maisNova = &pessoas[0];

    int i;
    for (i = 1; i < tamanho; i++) {
        if (pessoas[i].idade > maisVelha->idade) {
            maisVelha = &pessoas[i];
        }
        if (pessoas[i].idade < maisNova->idade) {
            maisNova = &pessoas[i];
        }
    }

    printf("\nPessoa mais velha: %s\n", maisVelha->nome);
    printf("Pessoa mais nova: %s\n", maisNova->nome);
}

int main() {
    int n, i;
    printf("Informe o número de pessoas: ");
    scanf("%d", &n);

    Pessoa *pessoas = (Pessoa*) malloc(n * sizeof(Pessoa));
    if (pessoas == NULL) {
        printf("Erro crítico: Falha na alocação de memória. O programa será encerrado.\n");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        printf("\nPreenchendo dados da %dª pessoa:\n", i + 1);
        preencherPessoa(&pessoas[i]);
    }

    printf("\n--- Pessoas Cadastradas ---\n");
    for (i = 0; i < n; i++) {
        printf("\nPessoa %d:\n", i + 1);
        imprimirPessoa(&pessoas[i]);
    }

    int id, nova_idade;
    printf("\nInforme o ID da pessoa que deseja alterar a idade (0 a %d): ", n - 1);
    scanf("%d", &id);
    printf("Digite a nova idade: ");
    scanf("%d", &nova_idade);
    atualizarIdade(&pessoas[id], nova_idade, n);

    printf("\n--- Pessoas Atualizadas ---\n");
    for (i = 0; i < n; i++) {
        printf("\nPessoa %d:\n", i + 1);
        imprimirPessoa(&pessoas[i]);
    }

    printf("\n--- Pessoa mais velha e mais nova ---\n");
    encontrarPessoaMaisVelhaEMaisNova(pessoas, n);

    free(pessoas);

    return 0;
}
