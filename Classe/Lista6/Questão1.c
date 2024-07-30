#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef union documentos {
    char CPF[16];                  
    int titulo_eleitoral, RG, sus, passaporte;
} Documentos;

typedef struct aluno {
    char nome[21];        
    int mat;
    Documentos documentos;
} Aluno;

// Função para validar o CPF (implementação básica)
int validarCPF(char *cpf) {
    // Implementação básica de validação de CPF
    // Verifica se o CPF tem 11 dígitos
    if (strlen(cpf) != 11) {
        return 0;
    }
    // Verifica se todos os dígitos são iguais
    int i;
    for (i = 1; i < 11; i++) {
        if (cpf[i] != cpf[0]) {
            return 1;
        }
    }
    return 0;
}

// Função para imprimir os documentos de um aluno
void imprimirDocumentos(Aluno *aluno) {
    if (strlen(aluno->documentos.CPF) > 0) {
        printf("CPF: %s\n", aluno->documentos.CPF);
    } else {
        printf("CPF: Não foi informado!\n");
    }
    
    if (aluno->documentos.RG > 0) {
        printf("RG: %d\n", aluno->documentos.RG);
    } else {
        printf("RG: Não foi informado!\n");
    }
    
    if (aluno->documentos.sus > 0) {
        printf("SUS: %d\n", aluno->documentos.sus);
    } else {
        printf("SUS: Não foi informado!\n");
    }
    
    if (aluno->documentos.titulo_eleitoral > 0) {
        printf("Título Eleitoral: %d\n", aluno->documentos.titulo_eleitoral);
    } else {
        printf("Título Eleitoral: Não foi informado!\n");
    }
    
    if (aluno->documentos.passaporte > 0) {
        printf("Passaporte: %d\n", aluno->documentos.passaporte);
    } else {
        printf("Passaporte: Não foi informado!\n");
    }
}

void preencher_aluno(Aluno *alunos, int n) {
    int opcao, i;
    for (i = 0; i < n; i++) {
        printf("Informe o nome do aluno %d:\n", i + 1);
        scanf(" %[^\n]", alunos[i].nome);
        printf("Informe a matrícula do aluno %d:\n", i + 1);
        scanf("%d", &alunos[i].mat);

        do {
            printf("\nDOCUMENTOS:\n");
            printf("1 – CPF\n");
            printf("2 – RG\n");
            printf("3 – SUS\n");
            printf("4 – Título Eleitoral\n");
            printf("5 – Passaporte\n");
            printf("6 – Sair\n");
            printf("Digite sua opção: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    printf("\nInforme o CPF:\t");
                    scanf(" %[^\n]", alunos[i].documentos.CPF);
                    // Validar CPF
                    if (!validarCPF(alunos[i].documentos.CPF)) {
                        printf("CPF inválido. Por favor, digite novamente.\n");
                    }
                    break;
                case 2:
                    printf("\nInforme o RG:\t");
                    scanf("%d", &alunos[i].documentos.RG);
                    break;
                case 3:
                    printf("\nInforme o SUS:\t");
                    scanf("%d", &alunos[i].documentos.sus);
                    break;
                case 4:
                    printf("\nInforme o Título Eleitoral:\t");
                    scanf("%d", &alunos[i].documentos.titulo_eleitoral);
                    break;
                case 5:
                    printf("\nInforme o Passaporte:\t");
                    scanf("%d", &alunos[i].documentos.passaporte);
                    break;
                case 6:
                    printf("\nObrigado por usar este programa!\n");
                    break;
                default:
                    printf("\nOpção inválida.\n");
                    break;
            }
        } while (opcao != 6);
    }
}

void imprimir_aluno(Aluno *alunos, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Aluno(a): %s\nMatrícula: %d.\n", alunos[i].nome, alunos[i].mat);
        imprimirDocumentos(&alunos[i]);
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int n;
    printf("Informe o número de alunos: ");
    scanf("%d", &n);

    Aluno *alunos = (Aluno*) malloc(n * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Erro crítico: Falha na alocação de memória. O programa será encerrado.\n");
        exit(1);
    }

    preencher_aluno(alunos, n);
    imprimir_aluno(alunos, n);

    free(alunos);
    return 0;
}
