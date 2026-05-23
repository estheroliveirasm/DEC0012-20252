#ifndef CADASTROS_H
#define CADASTROS_H

#include "types.h"

void inicializar_base_clientes(struct base_dados_cliente *clientes);
void inicializar_base_livros(struct base_dados_livro *livros);
void inserir_cliente_base_dados(struct base_dados_cliente *clientes, struct dados_cliente *cliente, int modo);
void inserir_livro_base_dados(struct base_dados_livro *livros, struct dados_livro *livro, int modo);
struct dados_cliente *novo_cliente(unsigned int *codigo);
struct dados_livro *novo_livro(unsigned int *codigo);

#endif