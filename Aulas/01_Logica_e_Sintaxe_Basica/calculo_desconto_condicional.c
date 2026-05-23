#include <stdio.h>

/*
If's aninhados.
*/

/*
Uma empresa precisa calcular o total de vendas por produto. Os
produtos são identificados por letras do alfabeto, por exemplo:
m - margarina; l - leite em pó; j - miojo; p - pão. Se a compra 
de um produto for maior que 100 unidades, haverá um desconto de
10% sobre o valor total (montante) de venda do produto.
*/

int main()
{
    const float PRECO_MARGARINA = 5.67;
    const float PRECO_LEITE_PO  = 15.34;
    const float PRECO_MIOJO     = 1.75;
    const float PRECO_PAO       = 15.80;

    char produto;
    int quantidade;
    float valor_total;

    printf("Qual o produto? ");
    scanf("%c", &produto);

    printf("Quantidade adquirida? ");
    scanf("%i", &quantidade);

    if (produto == 'm') {
        printf("Comprou margarina\n");
        valor_total = quantidade * PRECO_MARGARINA;
        if (quantidade > 100) {
            valor_total = valor_total * 0.9;
        }
    }

    if (produto == 'l') {
        printf("Comprou leite em pó\n");
        valor_total = quantidade * PRECO_LEITE_PO;
        if (quantidade > 100) {
            valor_total = valor_total * 0.9;
        }
    }

    if (produto == 'j') {
        printf("Comprou miojo\n");
        valor_total = quantidade * PRECO_MIOJO;
        if (quantidade > 100) {
            valor_total = valor_total * 0.9;
        }
    }

    if (produto == 'p') {
        printf("Comprou pão\n");
        valor_total = quantidade * PRECO_PAO;
        if (quantidade > 100) {
            valor_total = valor_total * 0.9;
        }
    }

    printf("Valor a ser pago %.2f\n", valor_total);


    return 0;
}