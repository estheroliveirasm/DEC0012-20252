#include <stdio.h>

int main()
{
    int contador = 1, valor, quantia;
    float media = 0;

    printf("Quantos valores? ");
    scanf("%i", &quantia);

    // Laço de repetição com teste no fim
    do {
        printf("Valor %i: ", contador);
        scanf("%i", &valor);

        media += valor;
        contador++;

    } while (contador <= quantia);

    media /= quantia;

    printf("Media = %.2f\n", media);

    return 0;
}