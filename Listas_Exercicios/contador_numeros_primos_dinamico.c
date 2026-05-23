/*
Escreva um algoritmo que receba vários números inteiros e imprima a quantidade
de números primos dentre os números que foram digitados. O algoritmo acaba
quando se digita um número menor ou igual a 0.
*/

#include <stdio.h>

int main()
{
    int numero, qtd_primos = 0, i, eh_primo = 1;

    do {
        printf("Qual o numero? ");
        scanf("%i", &numero);

        if (numero <= 0) break;

        for (i = 2; i < numero; i++) {
            if (numero % i == 0) {
                eh_primo = 0;
                break;
            }
        }
        if (eh_primo == 1) {
            qtd_primos++;
        }

        eh_primo = 1;

    } while (numero > 0);

    printf("%d\n", qtd_primos);


    return 0;
}