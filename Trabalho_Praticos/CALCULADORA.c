#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    float operando_1, operando_2;

    if (argc < 4) {
        printf("Erro: uso -> ./calculadora operacao op1 op2\n");
        printf("Operacoes: \n adicao\n subtracao\n multiplicacao\n divisao\n");
        exit(0);
    }

    operando_1 = atof(argv[2]);
    operando_2 = atof(argv[3]);

    if (strcmp(argv[1],"adicao") == 0) {
        printf("Adicao de %.2f e %.2f eh: %.2f\n", operando_1, operando_2, operando_1 + operando_2);
    }
    else if (strcmp(argv[1],"subtracao") == 0) {
        printf("Subtracao de %.2f e %.2f eh: %.2f\n", operando_1, operando_2, operando_1 - operando_2);
    }
    else if (strcmp(argv[1],"multiplicacao") == 0) {
        printf("Multiplicacao de %.2f e %.2f eh: %.2f\n", operando_1, operando_2, operando_1 * operando_2);
    }
    else if (strcmp(argv[1],"divisao") == 0) {
        printf("Divisao de %.2f e %.2f eh: %.2f\n", operando_1, operando_2, operando_1 / operando_2);
    }

    return 0;
}