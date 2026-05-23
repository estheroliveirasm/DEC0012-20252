#include "../include/menus.h"
#include <stdio.h>

int menu_principal()
{
    int opcao;

    printf("1.Cadastros\n");
    printf("2.Relatorios\n");
    printf("3.Consultas\n");
    printf("0.Sair do programa\n");
    printf(":: ");
    scanf("%i", &opcao);
    getchar();

    return opcao;
}

int sub_menu_cadastros()
{
    int opcao;

    printf("1.Cadastro de clientes\n");
    printf("2.Cadastro de livros\n");
    printf("0.Voltar ao menu principal\n");
    printf(":: ");
    scanf("%i", &opcao);
    getchar();

    return opcao;
}

int sub_menu_relatorios()
{
    int opcao;

    printf("1.Relatorio de clientes\n");
    printf("2.Relatorio de livros\n");
    printf("3.Relatorio de vendas\n");
    printf("4.Relatorio de estoque\n");
    printf("0.Voltar ao menu principal\n");
    printf(":: ");
    scanf("%i", &opcao);
    getchar();

    return opcao;
}

int sub_menu_consultas()
{
    int opcao;

    printf("1.Livro por titulo\n");
    printf("2.Cliente por nome\n");
    printf("0.Voltar ao menu principal\n");
    printf(":: ");
    scanf("%i", &opcao);
    getchar();

    return opcao;
}

int sub_menu_tipo_relatorio()
{
    int opcao;

    printf("1.Tela\n");
    printf("2.Arquivo texto sem formatacao\n");
    printf("3.Arquivo texto para Excel (csv)\n");
    printf("4.Arquivo html\n");
    printf("0.Voltar ao menu anterior\n");
    printf(":: ");
    scanf("%i", &opcao);
    getchar();

    return opcao;
}