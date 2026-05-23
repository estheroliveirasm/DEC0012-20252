/*
Escreva um programa na linguagem de programa��o C que receba como
entrada de dados um valor inteiro positivo n. O programa dever� gerar a
sequ�ncia (s�rie) de Fibonacci at� o en�zimo termo (valor de n).
Os dois primeiros termos da s�rie de Fibonacci s�o 0 e 1 e
os pr�ximos s�o calculados somando o valor atual ao anterior,
por exemplo: 0, 1, 1, 2, 3, 5, 8, 11 ... Para cada termo da s�rie
verifique se este � par, �mpar ou primo. Utilize contadores para
contar a quantidade de n�meros pares, n�meros �mpares e n�meros
primos na s�rie gerada. Ao final o programa dever� apresentar um
resumo para o usu�rio contendo a quantidade de pares, de �mpares e
primos contidos na s�rie gerada.
*/

#include <stdio.h>

int main()
{
    int n, anterior, atual, proximo, i, k, qtd_impares = 1, qtd_pares = 1, qtd_primos = 0;

    anterior    = 0;  // Considerado par, por isso a vari�vel qtd_pares est� inicializada em 1
    atual       = 1;


    printf("Informe o termo da s�rie de Fibonacci: ");
    scanf("%i", &n);

    printf("S�rie de Fibonacci\n\n");
    printf("%d, %d, ", anterior, atual);

    for (i = 3; i <= n; i++) {
        proximo     = anterior + atual;
        printf("%d, ", proximo);

        // Verifica se eh par
        if (proximo % 2 == 0) {
            qtd_pares++;
        }
        // Eh �mpar
        else {
            qtd_impares++;
        }
        // Verifica se eh primo
        for (k = 2; k < proximo; k++) {
            if (proximo % k == 0) {
                break;
            }
        }
        if (k == proximo) {
            qtd_primos++;
        }

        anterior    = atual;
        atual       = proximo;

    }

    printf("\n\n");
    printf("Quantidade de pares......: %d\n", qtd_pares);
    printf("Quantidade de impares....: %d\n", qtd_impares);
    printf("Quantidade de primos.....: %d\n", qtd_primos);

    return 0;
}