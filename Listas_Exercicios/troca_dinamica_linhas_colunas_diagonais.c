/*
Faça um algoritmo que leia uma matriz de 5 x 5 elementos do tipo real e que
realize as seguintes trocas:
○ a linha 2 com a linha 4;
○ a coluna 1 com a coluna 3;
○ a diagonal principal com a secundária;
○ a linha 3 com a coluna 2.
*/

#include <stdio.h>

#define TAMANHO 5

int main()
{
    float matriz[TAMANHO][TAMANHO], suporte[TAMANHO][TAMANHO];
    int i, j, k;

    //coleta de dados

    for(i = 0; i < TAMANHO; i++){
        for(j = 0; j < TAMANHO; j++){
            printf("Digite o número que será armazenado na matriz.\n");
            scanf("%f", &matriz[i][j]);
        }
    }

    //apresentação da matriz inicial

    for(i = 0; i < TAMANHO; i++){   
        for(j = 0; j < TAMANHO; j++){
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }

    //troca da linha 2 com a linha 4

    for(j = 0; j < TAMANHO; j++){
        suporte[1][j] = matriz[1][j];
        matriz[1][j] = matriz[3][j];
        matriz[3][j] = suporte[1][j];
    }

    //visualização

    printf("\n");
    printf("Linha 2 pela Linha 4.\n");
    for(i = 0; i < TAMANHO; i++){   
        for(j = 0; j < TAMANHO; j++){
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }

    //troca da coluna 1 com a coluna 3

    for(i = 0; i < TAMANHO; i++){
        suporte[i][0] = matriz[i][0];
        matriz[i][0] = matriz[i][2];
        matriz[i][2] = suporte[i][0];
    }

    //visualização

    printf("\n");
    printf("Coluna 1 pela coluna 3.\n");
    for(i = 0; i < TAMANHO; i++){   
        for(j = 0; j < TAMANHO; j++){
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }

    //troca da diagonal principal com a secundária

    i = 0, j = 4;
    for(k = 0; k < TAMANHO; k++){
        suporte[i][1] = matriz[i][j];
        i++;
        j--;
    }
    i = 0, j = 0;
    for(k = 0; k < TAMANHO; k++){
        suporte[i][0] = matriz[i][j];
        matriz[i][j] = suporte[i][1];
        i++;
        j++;
    }
    i = 0, j = 4;
    for(k = 0; k < TAMANHO; k++){
        matriz[i][j] = suporte[i][0];
        i++;
        j--;
    }
    
    //visualização

    printf("\n");
    printf("Diagonal principal pela secundária.\n");
    for(i = 0; i < TAMANHO; i++){   
        for(j = 0; j < TAMANHO; j++){
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }

    //troca da linha 3 com a coluna 2

    for(i = 0; i < TAMANHO; i++){
        suporte[i][0] = matriz[2][i];
        suporte[i][1] = matriz[i][1];
    }
    for(i = 0; i < TAMANHO; i++){
        matriz[2][i] = suporte[i][1];
        matriz[i][1] = suporte[i][0];
    }

    //visualização

    printf("\n");
    printf("Linha 3 pela coluna 2.\n");
    for(i = 0; i < TAMANHO; i++){   
        for(j = 0; j < TAMANHO; j++){
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }


    


    return 0;
}