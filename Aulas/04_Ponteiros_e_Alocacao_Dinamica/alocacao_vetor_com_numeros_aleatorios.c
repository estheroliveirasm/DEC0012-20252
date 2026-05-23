#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int gera_nr_aleatorio(int inicio, int fim);
void guardar_nr_vetor(int *vetor, int tamanho);
void mostrar_vetor(int *vetor, int tamanho);


int main()
{
    srand(time(NULL));

    int *vetor = NULL;
    int tamanho = gera_nr_aleatorio(1, 11); // [1, 11[

        

    vetor = (int*)malloc(tamanho * sizeof(int));
    guardar_nr_vetor(vetor, tamanho);
    mostrar_vetor(vetor, tamanho);


    return 0;
}

int gera_nr_aleatorio(int inicio, int fim)
{
    return inicio + rand() % fim;
}

void guardar_nr_vetor(int *vetor, int tamanho){
    for(int i = 0; i<tamanho; i++)
        *(vetor+i) = gera_nr_aleatorio(1, 101);
        // ^^^^^^ desloca i*4 bytes rs
        // 4 bytes porque é tipo int
}

void mostrar_vetor(int *vetor, int tamanho){
    for(int i = 0; i<tamanho; i++)
        printf("Vetor[%i] = %i\n", i, *(vetor+i)); 
}