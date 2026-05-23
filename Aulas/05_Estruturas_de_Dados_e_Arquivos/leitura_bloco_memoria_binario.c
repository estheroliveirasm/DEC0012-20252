#include <stdio.h>

int main()
{
    FILE *fp_arquivo = NULL;

    int dados[10];


    fp_arquivo = fopen("londrina.bin", "rb");

    fread(dados, sizeof(int), 10, fp_arquivo);

    for (int i = 0; i < 10; i++) {
        printf("%d ", *(dados+i));
    }
    printf("\n");

    fclose(fp_arquivo);

    return 0;
}