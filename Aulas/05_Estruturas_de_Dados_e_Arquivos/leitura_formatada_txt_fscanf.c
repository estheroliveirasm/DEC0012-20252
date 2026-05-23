#include <stdio.h>

int main()
{
    int dados[100], i = 0, j;

    FILE *fp_arquivo = NULL;

    fp_arquivo = fopen("xuxa.txt", "r");

    if (fp_arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo\n");
        return -1;
    }
    
    // Ler os dados do arquivo e armazená-los no vetor dados
    while (!feof(fp_arquivo)) {
        fscanf(fp_arquivo, "%i", (dados+i));        
        i++;
    }

    for (i = 0, j = 0; i < 100; i++, j++) {
        printf("%i\t", *(dados+i));
        if (j % 10 == 0) {
            printf("\n");
            j = 0;
        }
    }

    fclose(fp_arquivo);


    return 0;
}