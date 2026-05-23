#include <stdio.h>
#include <stdlib.h>

int maior_valor(int *v, int qtd_itens);

int main()
{
    int tamanho, *vetor;

    printf("Qual o tamanho do vetor? ");
    scanf("%i", &tamanho);

    if (tamanho > 1) {
        vetor = malloc(sizeof(int) * tamanho);
        if (vetor == NULL) {
            printf("Falha ao tentar alocar dados dinamicamente\n");
            return 0;
        }
    }

    for (int i = 0; i < tamanho; i++) {
        printf("Item v[%i]: ", i);
        scanf("%i", (vetor+i));
    }

    for (int i = 0; i < tamanho; i++) {
        printf("Item vetor[%i]: %i (%p)\n", i, *(vetor+i), (vetor+i));
    }

    printf("O maior valor contido no vetor eh: %i\n", maior_valor(vetor, tamanho));
    

    return 0;
}

int maior_valor(int *v, int qtd_itens)
{
    int maior = *v; // v[0] // *(v+0)
    for (int i = 1; i < qtd_itens; i++) {
        if (*(v+i) > maior) {
            maior = *(v+i);
        }
    }

    return maior;
}