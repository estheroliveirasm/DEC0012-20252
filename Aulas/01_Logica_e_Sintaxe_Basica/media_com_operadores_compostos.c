#include <stdio.h>

int main()
{
    int v, contador = 1, x;
    float media = 0;

    printf("Digite o número de entradas\n");
    scanf("%i", &x);

    // Laço de repetição com teste no início
    while (contador <= x) {
        printf("Valor: ");
        scanf("%d", &v);

        /*
        Operadores compostos:
        v++ -   > v = v + 1
        v--     -> v = v - 1
        v += x  -> v = v + x
        v -= x  -> v = v - x
        v *= x  -> v = v * x
        v /= x  -> v = v / x
        */

        //media = media + v;
        media += v;
        
        //contador = contador + 1;
        contador++;
        //contador += 1;
    }

    media = media / x;

    printf("A media eh: %.2f\n", media);


    return 0;
}