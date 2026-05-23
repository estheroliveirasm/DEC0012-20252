/*
Exemplo de passagem de parâmetro por valor.
*/

#include <stdio.h>

void soma(int valor);

int main()
{
    int v = 10;

    printf("Valor de v antes de soma: %d\n", v);
    soma(v);
    printf("Valor de v depois de soma: %d\n", v);

    return 0;
}

void soma(int valor)
{
    valor++;
}