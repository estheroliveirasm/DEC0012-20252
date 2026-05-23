#include <stdio.h>
#include <string.h>

#define T_STR 20

typedef char string[T_STR];

int main()
{
    int i;

    string lapis, jurubeba;

    fgets(lapis, sizeof(string), stdin);

    printf("String lida: %s\n", lapis);

    for(i = 0; lapis[i] != '\0'; i++)
    {
        ;
    }

    printf("Tamanho da String: %i\n", i);

    printf("Tamanho da string: %i\n", strlen(lapis));

    return 0;
}