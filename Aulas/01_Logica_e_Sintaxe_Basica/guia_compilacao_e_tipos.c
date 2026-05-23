// Este é um comentário de linha.

/*
Este é um exemplo de comentário de bloco.

Para compilar um programa em C você deve
executar o seguinte comando:

gcc nome_arq.c -o nome_executavel
*/

// Variáveis de memória

/*
Tipos de dados:

int - inteiro (4 bytes)
float - ponto flutuante (4 bytes)
char - caractere (1 byte)
double - inteiro duplo (8 bytes)
void   - sem tipo definido
*/

#include <stdio.h>

int main()
{
    int numero;

    // Atribuição de dados a variáveis
    numero = 42;

    /*
    Máscara de formatação:
    int - %d ou %i
    float - %f
    char - %c
    double %l
    */

    printf("Estou feliz. Estudo ENG. Computacao\n");

    printf("%i\n", numero);

    return 0;
}