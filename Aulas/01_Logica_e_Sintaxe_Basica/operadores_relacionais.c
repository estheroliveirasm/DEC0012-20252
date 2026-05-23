#include <stdio.h>

int main()
{
    int y = 5;
    int w = 17;
    int resultado;

    /*
    Operadores relacionais:
    > maior que
    < menor que
    >= maior ou igual a
    <= menor ou igual a
    == igual
    != diferente
    */

    /*
    Operadores lógicos:
    && and (e)
    || or (out)
    ! not (não)
    */

    resultado = !!!!(w <= y && w != 17);

    printf("%i\n", resultado);

    return 0;
}