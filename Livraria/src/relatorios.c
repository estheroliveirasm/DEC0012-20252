#include <stdio.h>
#include "../include/relatorios.h"

void listar_clientes(struct dados_cliente *inicio_lista)
{
    while (inicio_lista) {

        mostrar_dados_cliente(inicio_lista, stdout);
        printf("\n");
        inicio_lista = inicio_lista->prox;
    }
}

void listar_livros(struct dados_livro *inicio_lista)
{
    while (inicio_lista) {
        mostrar_dados_livro(inicio_lista, stdout);
        printf("\n");
        inicio_lista = inicio_lista->prox;
    }
}

void mostrar_dados_cliente(struct dados_cliente *cliente, FILE *fp)
{
    fprintf(fp, "Codigo................: %i\n", cliente->id);
    fprintf(fp, "Nome do cliente.......: %s\n", cliente->nome);
    fprintf(fp, "Email.................: %s\n", cliente->email);
    fprintf(fp, "Telefone de contato...: %s\n", cliente->telefone);
}

void mostrar_dados_livro(struct dados_livro *livro, FILE *fp)
{
    fprintf(fp, "Identificacao......: %i\n", livro->id);
    fprintf(fp, "Publicacao.........: %i\n", livro->publicacao);
    fprintf(fp, "Valor do livro.....: %.2f\n", livro->valor);
    fprintf(fp, "Titulo.............: %s\n", livro->titulo);
    fprintf(fp, "Autor principal....: %s\n", livro->autor_principal);
    fprintf(fp, "Estoque............: %i\n", livro->qtd_estoque);
}
