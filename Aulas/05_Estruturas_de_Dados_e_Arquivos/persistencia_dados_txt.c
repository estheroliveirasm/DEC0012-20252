#include <stdio.h>

int main()
{
    FILE *fp_arquivo = NULL;

    // Abrir um arquivo do tipo texto
    fp_arquivo = fopen("xuxa.txt", "w");

    /*
    Formas de abertura:
     r - read
     w - write
     rw - read and write
     r+ - read com criação
     w+ - write com criação
     a  - append (adiciona dados no fim do arquivo)
    */

    if (fp_arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo\n");
        return -1;
        //exit(-1);
    }

    for (int i = 0; i < 100; i++) {
        fprintf(fp_arquivo, "%i\n", i+1);
    }

    fclose(fp_arquivo);

    return 0;
}