#include <stdio.h>

/*
Seleção de múltipla escolha
*/

int main()
{
    int opcao;

    printf("Qual a sua opcao? ");
    scanf("%i", &opcao);

    switch (opcao) {

        case 1: printf("Selecionou 1\n");
                break;

        case 2: printf("Selecionou 2\n");
                break;

        case 3: printf("Selecionou 3\n");
                break;

        default: printf("Qualquer outra opcao\n");

    }

    return 0;
}