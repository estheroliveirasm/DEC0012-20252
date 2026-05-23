#ifndef RELATORIOS_H
#define RELATORIOS_H

#include <stdio.h>
#include "types.h"


void listar_clientes(struct dados_cliente *inicio_lista);
void listar_livros(struct dados_livro *inicio_lista);
void mostrar_dados_cliente(struct dados_cliente *cliente, FILE *fp);
void mostrar_dados_livro(struct dados_livro *livro, FILE *fp);

#endif
