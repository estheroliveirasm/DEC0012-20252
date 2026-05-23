#include <stdio.h>

#define T 10

typedef struct produto {
    int codigo;
    float preco;
} produto;

int menu();
void cadastro_produto();

produto lista_produtos[T];
int opc, cod, qtd_produtos = 0, i;
float MediaValores = 0;


int main()
{

    do {
        opc = menu();

        switch (opc) {
            case 1: cadastro_produto();
                    break;
            case 2: for (i = 0; i < qtd_produtos; i++) {
                        printf("Codigo do produto........: %i\n", lista_produtos[i].codigo);
                        printf("Valor do produto.........: %f\n", lista_produtos[i].preco);
                    }
                    break;
            case 3: printf("Digite o codigo do produto que deseja achar: ");
                    scanf("%i", &cod);
                    for(i = 0; i < qtd_produtos; i++){
                        if(cod == lista_produtos[i].codigo){
                            printf("\n\n");
                            printf("Codigo do produto........: %i\n", lista_produtos[i].codigo);
                            printf("Valor do produto.........: %f\n", lista_produtos[i].preco);
                            printf("\n\n");
                            break;
                        }

                    }
                    if(i == qtd_produtos){
                        printf("\n\n");
                        printf("Esse produto não esta cadastrado.\n");
                        printf("\n\n");
                    }
                    break;
            case 4: MediaValores = 0;
                    for(i = 0; i < qtd_produtos; i++){
                        MediaValores += lista_produtos[i].preco;

                    }
                    MediaValores /= qtd_produtos;

                    printf("Media dos valores eh %.2f", MediaValores);
                    break;
            case 0: printf("Tchau!!!\n");
                    break;
            default: printf("Opcao invalida!\n");
        }

    } while (opc != 0);

    

    return 0;
}

int menu()
{
    int opc;

    printf("1.Cadastrar novo produto\n");
    printf("2.Listar produtos cadastrados\n");
    printf("3.Localizar produto por codigo\n");
    printf("4.Calcular media dos valores dos produtos\n");
    printf("0.Sair do programa\n");
    printf("Qual a sua opcao? ");
    scanf("%i", &opc);

    return opc;
}

void cadastro_produto()
{
    printf("Codigo do produto? ");
    scanf("%i", &lista_produtos[qtd_produtos].codigo);
    printf("Qual o valor do produto? ");
    scanf("%f", &lista_produtos[qtd_produtos].preco);
    qtd_produtos++;
}