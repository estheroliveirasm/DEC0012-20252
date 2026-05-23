#include <stdio.h>

int main()
{
    int vetor[10];

    printf("Endereco do vetor: %p\n", vetor);
    printf("Endereco da posicao zero do vetor: %p\n", &vetor[0]);

    for (int i = 0; i < 10; i++) {
        printf("Endereco vetor[%d]: %p\n", i, &vetor[i]);
    }
    
    return 0;
}