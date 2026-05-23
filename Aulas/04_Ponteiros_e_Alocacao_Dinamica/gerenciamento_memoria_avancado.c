#include <stdio.h>
#include <stdlib.h>

#define FIM   0


typedef char string[100];

struct dados_carro {
    string fabricante;
    string modelo;
    float valor;
};

int menu();
struct dados_carro novo_carro();
void mostrar_carros_cadastrados(struct dados_carro *carros, int qtd);

int main()
{
    struct dados_carro *carros = NULL;
    int opcao, qtd_carros = 0;


    printf("Tamanho de um carro: %lu\n", sizeof(struct dados_carro));

    do {
        opcao = menu();

        switch (opcao) {

            case 1: if (carros == NULL) {
                        carros = (struct dados_carro*)calloc(1, sizeof(struct dados_carro));
                        *carros = novo_carro();
                        qtd_carros++;

                    }
                    else {
                        carros = (struct dados_carro*)realloc(carros, sizeof(struct dados_carro) * (qtd_carros+1));
                        *(carros+qtd_carros) = novo_carro();
                        qtd_carros++;
                    }
                    break;

            case 2: mostrar_carros_cadastrados(carros, qtd_carros);
                    break;
        }

    } while (opcao != FIM);

    free(carros);

    if (carros == NULL) printf("Free\n");

    return 0;
}

int menu()
{
    int opc;

    printf("1.Cadastrar carro\n");
    printf("2.Listar carros\n");
    printf("0.Sair\n");
    printf(":: ");
    scanf("%d", &opc);
    getchar();

    return opc;
}

struct dados_carro novo_carro()
{
    struct dados_carro carro;

    printf("Qual a marca do carro? ");
    fgets(carro.fabricante, 100, stdin);

    printf("Qual o modelo do carro? ");
    fgets(carro.modelo, 100, stdin);

    printf("Valor do carro? ");
    scanf("%f", &carro.valor);

    return carro;
}

void mostrar_carros_cadastrados(struct dados_carro *carros, int qtd)
{
    for (int i = 0; i < qtd; i++) {
        printf("Marca do carro...: %s\n", carros[i].fabricante);
        printf("Modelo do carro..: %s\n", carros[i].modelo);
        printf("Valor do carro...: %.2f\n", carros[i].valor);
    }
}