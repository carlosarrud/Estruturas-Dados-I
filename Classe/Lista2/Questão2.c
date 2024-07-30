#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUNOS 10

int obter_questoes() {
    int questoes;
    printf("Informe quantas questões há na prova: ");
    scanf("%d", &questoes);
    return questoes;
}

char* obter_gabarito(int questoes) {
    char *gabarito = (char *)malloc((questoes + 1) * sizeof(char));
    printf("Digite o gabarito da prova: ");
    scanf("%s", gabarito);
    return gabarito;
}

void ler_respostas(char respostas[MAX_ALUNOS][100], int questoes) {
    int i;
    for (i = 0; i < MAX_ALUNOS; i++) {
        printf("Digite as respostas do aluno %d: ", i + 1);
        scanf("%s", respostas[i]);
    }
}

void calcular_notas(float notas[MAX_ALUNOS], char respostas[MAX_ALUNOS][100], char *gabarito, int questoes, int *aprovados) {
    int i, j;
    for (i = 0; i < MAX_ALUNOS; i++) {
        int acertos = 0;
        for (j = 0; j < questoes; j++) {
            if (respostas[i][j] == gabarito[j]) {
                acertos++;
            }
        }
        notas[i] = (10.0 / questoes) * acertos;
        if (notas[i] >= 6.0) {
            (*aprovados)++;
        }
    }
}

void exibir_notas(float notas[MAX_ALUNOS]) {
    int i;
    printf("\nA nota dos alunos são: \n");
    for (i = 0; i < MAX_ALUNOS; i++) {
        printf("Nota do aluno %d: %.2f\n", i + 1, notas[i]);
    }
}

void exibir_aprovacao(int aprovados) {
    float porcentagem = (aprovados / (float)MAX_ALUNOS) * 100;
    printf("Porcentagem de aprovação: %.2f%%\n", porcentagem);
}

int main() {
    int questoes = obter_questoes();
    char *gabarito = obter_gabarito(questoes);
    char respostas[MAX_ALUNOS][100];
    float notas[MAX_ALUNOS];
    int aprovados = 0;

    //ler as respostas dos alunos
    ler_respostas(respostas, questoes);

    //calcular as notas dos alunos
    calcular_notas(notas, respostas, gabarito, questoes, &aprovados);

    //exibir as notas dos alunos
    exibir_notas(notas);

    //exibir a porcentagem de aprovação
    exibir_aprovacao(aprovados);

    free(gabarito);
    return 0;
}
