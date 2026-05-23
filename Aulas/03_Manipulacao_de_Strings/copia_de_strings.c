#include <stdio.h>
#include <string.h>

typedef char string[20];

int main()
{

    /*
    string original;
    string copia;
    

    printf("String original: ");
    fgets(original, sizeof(original), stdin);
    
    printf("Conteudo original: %s\n", original);
    
    printf("String copia: ");
    fgets(copia, sizeof(copia), stdin);
    strcpy(original, "Gumercindo");
    
    printf("%s\n", original);*/




    string exemplo;
    strcpy(exemplo, "Copia");
    printf("%s\n", exemplo);


    return 0;
}