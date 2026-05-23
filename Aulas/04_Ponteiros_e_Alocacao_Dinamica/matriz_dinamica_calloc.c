#include <stdio.h>
#include <stdlib.h>

#define LINHAS      3
#define COLUNAS     4


int main()
{
    int **matriz = NULL;

    // Aloca as linhas
    matriz = (int**)calloc(LINHAS, sizeof(int*));

    for (int i = 0; i < LINHAS; i++) {
        matriz[i] = (int*)calloc(COLUNAS, sizeof(int));
    }

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            scanf("%i", &matriz[i][j]);
        }
    }


    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%i (%p)\t", matriz[i][j], &matriz[i][j]);
        }
        printf("\n");

    }

    for (int k = 0; k < LINHAS; k++) {
        free(matriz[k]);
    }

    free(matriz);

    return 0;
}