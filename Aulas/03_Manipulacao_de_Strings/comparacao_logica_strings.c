#include <stdio.h>
#include <string.h>

typedef char str[20];

int main()
{
    str libras, letras;

    fgets(libras, sizeof(str), stdin);
    fgets(letras, sizeof(str), stdin);

    if (strcmp(libras, letras) == 0) {
        printf("Strings iguais!!!\n");
    }
    else {
        printf("Strings diferentes\n");
    }

    return 0;
}