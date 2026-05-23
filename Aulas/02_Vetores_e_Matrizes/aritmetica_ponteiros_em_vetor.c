#include <stdio.h>

#define QTD_DADOS_VETOR 10

int main()
{
    int vetor[QTD_DADOS_VETOR] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    // for (int i = 0; i < 10; i++) {
    printf("Endereco do vetor (vetor): %p\n", vetor);
    for (int i = 0; i < sizeof(vetor) / sizeof(int); i++) {
        printf("vetor[%i]: %i (%p)\n", i, *(vetor+i), (vetor+i));
    }

    return 0;
}