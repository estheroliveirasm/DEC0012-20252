#include <stdio.h>

void soma(int *valor);

int main()
{
    int patati_patata = 10;


    printf("Antes de soma: %d\n", patati_patata);

    soma(&patati_patata);

    printf("Depois de soma: %d\n", patati_patata);

    return 0;
}

void soma(int *valor)
{
    *valor += 1;
}