#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS  4
#define COLUNAS 5

int numero(int i, int f);

const char LETRAS[] = {'A', 'B', 'C', 'D', 'E', 'I', 'O', 'J', 'H', 'K'};

int main()
{
    char **matriz_c = NULL;

    srand(time(NULL));

    // Aloca as linhas
    matriz_c = (char**)malloc(sizeof(char*) * LINHAS);

    // Aloca colunas
    for (int i = 0; i < LINHAS; i++)
    {
        *(matriz_c+i) = malloc(sizeof(char) * COLUNAS);
    }

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            *(*(matriz_c+i)+j) = LETRAS[numero(0, 10)];
        }
    }

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%c\t", *(*(matriz_c+i)+j));
        }
        printf("\n");
    }


    return 0;
}

int numero(int i, int f)
{
    return i + random() % f;
}