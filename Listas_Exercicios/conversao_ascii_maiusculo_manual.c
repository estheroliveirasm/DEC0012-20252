/*
 Escreva um programa para ler um vetor de 10 elementos do tipo caractere. Mostre os elementos do
vetor convertido para letras maiúsculas.
*/

#include <stdio.h>
int main(){
    char vetor[10];
    int i;
    for(i=0; i<10; i++){
        printf("Digite uma letra minuscula: ");
        scanf("%c", &vetor[i]);
        getchar();
        vetor[i] = vetor[i] - 32;
    }
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("Vetor = [");
    for(i=0; i<10; i++){
        if(i!=9)
            printf("%c ", vetor[i]);
        else
            printf("%c]\n", vetor[i]);
    }
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    return 0;
}