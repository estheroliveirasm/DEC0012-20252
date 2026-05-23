#ifndef TYPES_H
#define TYPES_H

#define T_STR   100

typedef char string[T_STR];

struct dados_cliente {
    unsigned int id;
    string nome;
    string email;
    string telefone;
    struct dados_cliente *prox;
};

struct dados_livro {
    unsigned int id;
    unsigned int publicacao;
    float valor;
    string titulo;
    string autor_principal;
    unsigned int qtd_estoque;
    struct dados_livro *prox;
};

struct base_dados_cliente {
    unsigned int contador;
    struct dados_cliente *inicio;
    struct dados_cliente *fim;
};

struct base_dados_livro {
    unsigned int contador;
    struct dados_livro *inicio;
    struct dados_livro *fim;
};

#endif