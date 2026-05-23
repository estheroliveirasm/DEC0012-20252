/*
Tendo como entrada de dados a altura e o sexo de uma pessoa, construa um
algoritmo que calcule seu peso ideal, utilizando as seguintes fórmulas:
Para homens: (72.7 * h) - 58
Para mulheres: (62.1 * h) - 44.7
Onde h representa a altura.
*/

#include <stdio.h>

int main()
{
    char sexo;
    float resposta,altura;

    printf("Digite sua altura:\n ");
    scanf("%f",&altura);

    printf("Digite seu sexo:\n");
    getchar();
    scanf("%c",&sexo);

    if(sexo == 'H' || sexo == 'h')
    {
        resposta = (72.7 * altura) - 58;
        printf("A resposta é: %f\n",resposta);
    }
    if(sexo == 'M' || sexo == 'm'){
        resposta = (62.1 * altura) - 44.7;
        printf("A resposta é: %f\n",resposta);
    }



    return 0;
}