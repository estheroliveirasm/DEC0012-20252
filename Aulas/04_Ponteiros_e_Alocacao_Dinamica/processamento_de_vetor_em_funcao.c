#include <stdio.h>


#define QTD 10

void ler_vetor(int *xavier);
void mostrar_vetor(int *arthur);

int main()
{
    int v[QTD];

    //printf("Endereco de v   : %p\n", &v[0]);
    //printf("Endereco de v[0]: %p\n", &v[5]);

    ler_vetor(v);
    mostrar_vetor(v);

    return 0;
}

void ler_vetor(int *xavier)
{
    for (int i = 0; i < QTD; i++) {
        scanf("%d", &xavier[i]);
    }
}

void mostrar_vetor(int *arthur)
{
    for (int i = 0; i < QTD; i++) {
        printf("Arthur[%d]: %d\n", i, arthur[i]);
    }
}