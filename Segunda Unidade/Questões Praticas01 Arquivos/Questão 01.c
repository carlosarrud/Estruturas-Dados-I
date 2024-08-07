#include <stdio.h>
#include <stdlib.h>
#include <string.h>


  FILE * open_file(char * nome, char * modo){
 FILE * arquivo = fopen(nome, modo);
if(arquivo==NULL){
printf("Can't open the file\n");
exit(1);
}
else{
  printf("File open\n");
}
return arquivo;
  }


int main(void) {
    FILE *entrada, *saida;
    char nome[20];
    float nota1, nota2, nota3, media;

    // Abre o arquivo de entrada para leitura
    entrada = fopen("entrada_q3.txt", "r"); //Ler o arquivo de entrada
    // Abre o arquivo de saída para escrita
    saida = fopen("saída_q3.txt", "w");
    // Lê os dados do arquivo de entrada e escreve no arquivo de saída
    while (fscanf(entrada, "%s\t%f\t%f\t%f/n", nome, &nota1, &nota2, &nota3) != EOF) {//Enquando não chegar ao final do arquivo ler continuar repetindo
       
            //Calcular a media dos alunos
      media = (nota1 + nota2 + nota3) / 3;

      //Escreve no arquivo de saida
        fprintf(saida, "%s\t%.2f\t", nome, media);
        if (media >= 7.0) {
            fprintf(saida, "Aprovado\n");
        } else {
            fprintf(saida, "Reprovado\n");
        }
    }

    // Fecha os arquivos
    fclose(entrada);
    fclose(saida);

    printf("Dados processados com sucesso!\n");

    return 0;
}
