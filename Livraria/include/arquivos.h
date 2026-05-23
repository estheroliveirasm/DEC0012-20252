#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "types.h"

void salvar_dados_livros(struct dados_livro *inicio);
void salvar_dados_clientes(struct dados_cliente *inicio);
void carregar_dados_livros(struct base_dados_livro *livros);
void carregar_dados_clientes(struct base_dados_cliente *clientes);
void exportar_dados_clientes_txt(struct dados_cliente *clientes, char *nome_arq);
void exportar_dados_clientes_csv(struct dados_cliente *clientes, char *nome_arq);
void exportar_dados_clientes_html(struct dados_cliente *clientes, char *nome_arq);

#endif