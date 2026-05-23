/*

Escreva um algoritmo que receba uma matriz A[12][12] e retorne a média aritmética
dos elementos abaixo da diagonal principal e da diagonal secundária.

*/

#include <stdio.h>
#define N 4

int main()  {

    int A[N][N], i, j, soma = 0, k = 0;
    float media;

    // Insere os dados na matriz
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%i", &A[i][j]);
        }
    }
    
    // Printa a matriz
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
        printf("%i\t", A[i][j]);
        }
        printf("\n");
    }

    // Seleciona os elementos abaixo das diagonais principal e secundária e soma
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
        if (i > j || i + j > N - 1) {
            soma += A[i][j];
            k++;
        }
        }
    }
    // Faz a media dos elementos
    media = (float)soma / k;

    printf("//------------------------//");
    printf("Foram encontrados %i elementos abaixo das diagonais\n", k);
    printf("A soma dos elementos abaixo das diagonais é: %i\n", soma);
    printf("A média dos elementos abaixo das diagonais é: %.2f", media);

    return 0;
}