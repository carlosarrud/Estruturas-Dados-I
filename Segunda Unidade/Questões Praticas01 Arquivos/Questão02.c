#include <stdio.h>

int main() {
    FILE *arquivoEntrada, *arquivoSaida;
    int vetor[10];
    int i, menor, maior;
    float media = 0;

    // Abre o arquivo de entrada para leitura
    arquivoEntrada = fopen("entrada.txt", "r");
    if (arquivoEntrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    // Lê os **10** inteiros do arquivo de entrada
    for (i = 0; i < 10; i++) {
        fscanf(arquivoEntrada, "%d", &vetor[i]);
    }

    // Fecha o arquivo de entrada
    fclose(arquivoEntrada);

    // Inicializa o menor e o maior com o primeiro elemento do vetor
    menor = vetor[0];
    maior = vetor[0];

    // Encontra o menor e o maior elemento do vetor
    for (i = 1; i < 10; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
        media += vetor[i];
    }

    // Calcula a média dos elementos do vetor
    media /= 10;

    // Abre o arquivo de saída para escrita
    arquivoSaida = fopen("saida.txt", "w");
    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }

    // Escreve os dados no arquivo de saída
    fprintf(arquivoSaida, "Menor elemento: %d\n", menor);
    fprintf(arquivoSaida, "Maior elemento: %d\n", maior);
    fprintf(arquivoSaida, "Média dos elementos: %.2f\n", media);

    // Fecha o arquivo de saída
    fclose(arquivoSaida);

    printf("Dados processados com sucesso!\n");

    return 0;
}
