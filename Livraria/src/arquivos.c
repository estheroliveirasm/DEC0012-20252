#include "../include/arquivos.h"
#include "../include/cadastros.h"
#include "../include/types.h"
#include "../include/relatorios.h"
#include <stdlib.h>
#include <stdio.h>

void salvar_dados_livros(struct dados_livro *inicio)
{
    FILE *fp = NULL;

    fp = fopen("livros.bin", "wb");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo livros.bin\n");
        return;
    }

    while (inicio) {
        fwrite(inicio, sizeof(struct dados_livro), 1, fp);
        inicio = inicio->prox;
    }

    fclose(fp);
}

void salvar_dados_clientes(struct dados_cliente *inicio)
{
    FILE *fp = NULL;

    fp = fopen("clientes.bin", "wb");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo clientes.bin\n");
        return;
    }

    while (inicio) {
        fwrite(inicio, sizeof(struct dados_cliente), 1, fp);
        inicio = inicio->prox;
    }

    fclose(fp);
}

void carregar_dados_livros(struct base_dados_livro *livros)
{
    FILE *fp = NULL;
    struct dados_livro *novo = NULL;

    fp = fopen("livros.bin", "rb");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo livros.bin\n");
        return;
    }

    while (!feof(fp)) {
        novo = (struct dados_livro*)malloc(sizeof(struct dados_livro));

        fread(novo, sizeof(struct dados_livro), 1, fp);
        novo->prox = NULL;
        if (!feof(fp)) {
            inserir_livro_base_dados(livros, novo, 2);
        }
        else {
            free(novo);
        }
    }

    fclose(fp);    
}

void carregar_dados_clientes(struct base_dados_cliente *clientes)
{
    FILE *fp = NULL;
    struct dados_cliente *novo = NULL;

    fp = fopen("clientes.bin", "rb");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo clientes.bin\n");
        return;
    }

    while (!feof(fp)) {
        novo = (struct dados_cliente*)malloc(sizeof(struct dados_cliente));

        fread(novo, sizeof(struct dados_cliente), 1, fp);
        novo->prox = NULL;
        if (!feof(fp)) {
            inserir_cliente_base_dados(clientes, novo, 2);
        }
        else {
            free(novo);
        }
    }

    fclose(fp);    
}

void exportar_dados_clientes_txt(struct dados_cliente *clientes, char *nome_arq)
{
    FILE *fp = NULL;

    fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo %s\n", nome_arq);
        return;
    }

    while (clientes) {
        mostrar_dados_cliente(clientes, fp);
        fprintf(fp, "\n");
        clientes = clientes->prox;
    }

    fclose(fp);
}

void exportar_dados_clientes_csv(struct dados_cliente *clientes, char *nome_arq)
{
    FILE *fp = NULL;

    fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo %s\n", nome_arq);
        return;
    }

    fprintf(fp, "ID;NOME;EMAIL;TELEFONE\n");
    while (clientes) {
        fprintf(fp, "%i;%s;%s;%s\n", clientes->id, clientes->nome, clientes->email, clientes->telefone);
        clientes = clientes->prox;
    }

    fclose(fp);
}

void exportar_dados_clientes_html(struct dados_cliente *clientes, char *nome_arq)
{
    FILE *fp = NULL;

    fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo %s\n", nome_arq);
        return;
    }

    fprintf(fp, "<HTML> <HEAD> <TITLE> RELATORIO DE CLIENTES </TITLE> </HEAD> <BODY> \n");
    fprintf(fp, "<TABLE border = '1'> <TR> <TH> ID </TH> <TH> NOME </TH> <TH> EMAIL </TH> <TH> TELEFONE </TH> </TR>\n");
    while (clientes) {
        fprintf(fp, "<TR> <TD> %i </TD> <TD> %s </TD> <TD>%s</TD> <TD>%s</TD> </TR>\n", clientes->id, clientes->nome, clientes->email, clientes->telefone);
        clientes = clientes->prox;
    }
    fprintf(fp, "</TABLE> </BODY> </HTML>\n");

    fclose(fp);
}
