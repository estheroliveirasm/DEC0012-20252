/*
Revisão de ponteiros:

    -> ponteiro para variáveis escalores;
    -> ponteiro para vetor;
    -> ponteiro para struct;
    -> ponteiro para função.
*/

#include <stdio.h>

#define EXEMPLO_1 0
#define EXEMPLO_2 0
#define EXEMPLO_3 0
#define EXEMPLO_4 1

int soma(int a, int b);

int main()
{
    #if EXEMPLO_1 == 1
    // Exemplo 1: ponteiro para variável escalar
    int x = 10, *p_x;

    printf("Conteudo de x: %d endereco de x: %p\n", x, &x);

    p_x = &x;

    printf("Conteudo de p_x: %p endereco de p_x: %p\n", p_x, &p_x);

    *p_x = 10000;

    printf("Conteudo de x: %d endereco de x: %p\n", x, &x);

    printf("Conteudo apontado por p_x eh: %i\n", *p_x);
    
    #elif EXEMPLO_2 == 1

    // Exemplo 2: ponteiro para vetor
    float valores[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

    printf("Tamanho em bytes de valores: %lu | Endereco de valores: (%p) (%p)\n", sizeof(valores), &valores[0], valores);

    for (int i = 0; i < 5; i++) {
        printf("(%p) --> %.2f\n", &valores[i], valores[i]);    
    }

    printf("\n\n");

    float *p_valores;

    p_valores = valores;

    for (int i = 0; i < 5; i++) {
        printf("(%p) --> %.2f (%p)\n", &p_valores[i], p_valores[i], &p_valores);    
    }

    #elif EXEMPLO_3 == 1
    // Exemplo 3: ponteiro para struct
    struct coordenada {
        int x;
        int y;
    };

    struct coordenada c, *p_c;

    c.x = 5;
    c.y = 2;

    printf("X: %i Y: %i (%p)\n", c.x, c.y, &c);

    p_c = &c;

    printf("X: %i Y: %i (%p) (%p)\n", p_c->x, p_c->y, p_c, &p_c);

    #elif EXEMPLO_4 == 1
    // Exemplo 4: ponteiro para funcao

    printf("(%p) --> %i\n", soma, soma(3, 5));

    int (*p_soma)(int, int);

    p_soma = soma;

    printf("(%p) (%p) --> %i\n", p_soma, &p_soma, p_soma(3, 5));



    #endif

    return 0;
}

int soma(int a, int b)
{
    return a + b;
}