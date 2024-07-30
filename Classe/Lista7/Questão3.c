#include <stdio.h>

typedef enum mes {
    Janeiro = 1,
    Fevereiro,
    Marco,
    Abril,
    Maio,
    Junho,
    Julho,
    Agosto,
    Setembro,
    Outubro,
    Novembro,
    Dezembro
} Mes;

typedef struct data {
    int dia;
    int ano;
    Mes mes;
} Data;

// Função para validar o dia de acordo com o mês
int validarDia(int dia, Mes mes) {
    switch (mes) {
        case Fevereiro:
            return (dia >= 1 && dia <= 29);
        case Abril:
        case Junho:
        case Setembro:
        case Novembro:
            return (dia >= 1 && dia <= 30);
        default:
            return (dia >= 1 && dia <= 31);
    }
}

// Função para preencher os dados da data
void preencher(Data *d) {
    int mes, diaValido = 0;
    printf("Informe o ano: ");
    scanf("%d", &d->ano);

    while (!diaValido) {
        printf("Informe o dia: ");
        scanf("%d", &d->dia);

        printf("Informe o mês do ano (1 - 12): ");
        scanf("%d", &mes);

        d->mes = (Mes)mes;

        diaValido = validarDia(d->dia, d->mes);
        if (!diaValido) {
            printf("Dia inválido para o mês. Por favor, digite novamente.\n");
        }
    }
}

// Função para imprimir os dados da data
void imprima(Data *data) {
    printf("--- CALENDÁRIO ---\n");

    switch (data->mes) {
        case Janeiro:
            printf("%d de Janeiro de %d\n", data->dia, data->ano);
            break;
        case Fevereiro:
            printf("%d de Fevereiro de %d\n", data->dia, data->ano);
            break;
        case Marco:
            printf("%d de Março de %d\n", data->dia, data->ano);
            break;
        case Abril:
            printf("%d de Abril de %d\n", data->dia, data->ano);
            break;
        case Maio:
            printf("%d de Maio de %d\n", data->dia, data->ano);
            break;
        case Junho:
            printf("%d de Junho de %d\n", data->dia, data->ano);
            break;
        case Julho:
            printf("%d de Julho de %d\n", data->dia, data->ano);
            break;
        case Agosto:
            printf("%d de Agosto de %d\n", data->dia, data->ano);
            break;
        case Setembro:
            printf("%d de Setembro de %d\n", data->dia, data->ano);
            break;
        case Outubro:
            printf("%d de Outubro de %d\n", data->dia, data->ano);
            break;
        case Novembro:
            printf("%d de Novembro de %d\n", data->dia, data->ano);
            break;
        case Dezembro:
            printf("%d de Dezembro de %d\n", data->dia, data->ano);
            break;
    }
}

int main() {
    Data data;
    preencher(&data);
    imprima(&data);
    return 0;
}
