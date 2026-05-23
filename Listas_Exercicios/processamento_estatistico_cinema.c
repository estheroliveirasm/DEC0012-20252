/*
Um cinema possui capacidade de 100 lugares e está sempre com ocupação total.
Certo dia, cada espectador respondeu a um questionário, no qual constava:
○ Sua idade
○ Sua opinião em relação ao filme, segundo as seguintes notas:
A Ótimo
B Bom
C Regular
D Ruim
E Péssimo
Elabore um algoritmo que, lendo esses dados, calcule e imprima:
○ A quantidade de respostas ótimo;
○ A diferença percentual entre respostas Bom e Regular;
○ A média de idade das pessoas que responderam Ruim;
○ A percentagem de respostas Péssimo e a maior idade que utilizou
essa opção;
○ A diferença de idade entre a maior idade que respondeu Ótimo e a
maior idade que respondeu Ruim
*/

#include <stdio.h>

#define QUANTIDADE 5

int main (){

    int cont, cont_a, cont_b, cont_c, cont_d, cont_e;
    int idades, maior_idade, idade, maior_idadeo, maior_idader, dife;
    char selec;
    float dif, rep, idadem;

    cont_a = 0; cont_b = 0; cont_c = 0;
    cont_d = 0; cont_e = 0; maior_idade = 0;
    maior_idadeo = 0; maior_idader = 0;
    
    for (cont = 1; cont<=QUANTIDADE; cont++){

        printf("Digite sua idade: ");
        scanf("%i", &idade);
        getchar();
        printf("Notas para o serviço:\n a - Ótimo\n b - Bom\n c - Regular\n d - Ruim\n e - Péssimo\n Qual a sua opnião? ");
        scanf("%c", &selec);

        switch (selec)
        {
            case 'a': cont_a++;
            if (idade>maior_idadeo){
                maior_idadeo = idade;
            }
            break;

            case 'b': cont_b++;
            break;

            case 'c': cont_c++;
            break;

            case 'd': cont_d++;
            idades =+ idade;
            if (idade>maior_idader){
                maior_idader = idade;
            }
            break;

            case 'e': cont_e++;
            if (idade>maior_idade){
                maior_idade = idade;
            }

            

        }

        dif = (float)((cont_b-cont_c)*100/cont);
        rep = (float)(cont_e*100/cont);
        idadem = (float)(idades/cont);
        dife = maior_idadeo - maior_idader;



    }

    printf("Respostas ótimas: %i\n", cont_a);
    printf("Diferença de bom e regular: %0.02f\n", dif);
    printf("Média de idade de pessoas que responderam ruim: %0.02f\n", idadem);
    printf("Percentagem de respostas péssimas: %0.02f\n",rep);
    printf("Maior idade que respondeu péssimo: %i\n", maior_idade);
    printf("Diferença de idade de ótimo e ruim: %i\n", dife);


    return 0;
}