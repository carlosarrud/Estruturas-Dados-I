#include <stdio.h>
#include <stdlib.h>

int main(void){
// criando um arquivo aula01.txt
    FILE * arquivo;
    char texto_arquivo[100];
    arquivo = fopen("aula01.txt", "w");
    if(arquivo==NULL){
        printf("Can't creat file\n");
        exit(1);

    }
    else{
        printf("File created! \n");

    }
    // Escrevando arquivo
    fprintf(arquivo, "Hello word!");
    fclose(arquivo);

    // Lendo os texto do arquivo
    arquivo = fopen("aula01.txt", "r");
    fscanf(arquivo, "%s", texto_arquivo);
    printf("Texto no arquivo: %s\n", texto_arquivo);
    fclose(arquivo);
    return 0;
}
