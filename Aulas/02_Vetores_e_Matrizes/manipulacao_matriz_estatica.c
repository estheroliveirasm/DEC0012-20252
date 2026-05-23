#include <stdio.h>

int main()
{
    int numeros[3][4], i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%i", &numeros[i][j]);
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("%i\t", numeros[i][j]);
        }
        printf("\n");
    }


    return 0;
}