#include <stdio.h>
#include <string.h>

int main()  {
    
    int i;
    char destino[50];
    char origem[50];

    printf("Digite a primeira string: ");
    fgets(destino, sizeof(destino), stdin);
    printf("Digite a segunda string: ");
    fgets(origem, sizeof(origem), stdin);

    /*

    for(i = 0; i < sizeof(destino); i++) {
        if (destino[i] == '\n') {
            destino[i] = '\0';
            }
        if (origem[i] == '\n')  {
            origem[i] = '\0';
            }
    }
    */

   printf("A primeira string é: %s\n", destino);
   printf("A segunda string é: %s\n", origem);

   strcat(destino, origem);
   printf("A string concatenada é: %s\n", destino);
    return 0;
}