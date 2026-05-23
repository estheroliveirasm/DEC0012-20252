/*
Considere a seguinte sequência: H = 1 + 1/2 + 1/3 + 1/4 + .. + 1/n. Faça um
algoritmo para calcular o valor de H. O valor de n deverá ser informado pelo
usuário.
*/

#include <stdio.h>

int main()
{
    int contagem, valor_n;
    float valor_h = 0;

    printf("Defina o valor de n:");
    scanf("%d", &valor_n);

    for (contagem = 1; contagem <= valor_n; contagem++)
    {
        valor_h = valor_h + (1 / (float)contagem);
        // valor_h += (1 / (float)contagem);
    }

    printf("O resultado é: %f\n", valor_h);

    return 0;
}