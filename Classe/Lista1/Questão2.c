#include<stdio.h>

int main(void) {
int x, *p;
x = 100;
p = &x;
printf("Valor de p = %p\tValor de *p = %d", p, *p);
return 0;
}

//a) Esta mensagem é de erro ou advertência?
// Res.: Mensagem de Erro
//b) Por que o compilador emite tal mensagem?
// Res.: O endereço da variável que ele direciona não foi adicionado o &x
//c) Compile e execute o programa. A execução foi bem sucedida?
// Resposta: Não executou.
//d) Modifique o trecho de código acima, de modo que nenhuma mensagem seja emitida pelo compilador.
// Resposta: Realizado modificação Modificado
//e) Compile e execute novamente o programa. A execução foi bem sucedida?
// Resposta: Sim, com sucesso.
