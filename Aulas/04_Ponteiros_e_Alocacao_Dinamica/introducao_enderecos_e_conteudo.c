/*
Fundamentos de ponteiro
*/

#include <stdio.h>

int main()
{
    int x = 10, y = 20;
    int *ptr = &x;

    printf("Endereco de x: %p e o valor eh: %d\n", &x, x);
    printf("Endereco de y: %p e o valor eh: %d\n", &y, y);
    printf("Endereco de ptr: %p\n", &ptr);
    printf("Endereco apontado por ptr: %p\n", ptr);

    *ptr = 100;
    printf("Endereco de x: %p e o valor eh: %d\n", &x, x);

    printf("Tamanho de x: %d\n", sizeof(x));
    printf("Tamanho de y: %d\n", sizeof(y));
    printf("Tamanho de ptr: %d\n", sizeof(ptr));


    return 0;
}