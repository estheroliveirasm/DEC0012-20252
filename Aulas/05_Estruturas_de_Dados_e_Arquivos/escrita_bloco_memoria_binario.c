#include <stdio.h>

int main()
{
    FILE *fp_arquivo = NULL;

    int dados[] = {2, 5, 6, 7, 8, 9, 11, 12, 33, 23};


    fp_arquivo = fopen("londrina.bin", "wb");

    fwrite(dados, sizeof(int), 10, fp_arquivo);


    fclose(fp_arquivo);

    return 0;
}