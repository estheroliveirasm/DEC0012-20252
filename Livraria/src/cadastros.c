#include "../include/cadastros.h"
#include "../include/utils.h"
#include <stdlib.h>
#include <stdio.h>

void inicializar_base_clientes(struct base_dados_cliente *clientes)
{
    clientes->inicio = NULL;
    clientes->fim = NULL;
    clientes->contador = 0;
}

void inicializar_base_livros(struct base_dados_livro *livros)
{
    livros->inicio = NULL;
    livros->fim = NULL;
    livros->contador = 0;
}

void inserir_cliente_base_dados(struct base_dados_cliente *clientes, struct dados_cliente *cliente, int modo)
{
    if (clientes->inicio == NULL) {
        clientes->fim = cliente;
        clientes->inicio = cliente;
        return;
    }

    if (modo == 1) { // Inicio lista
        cliente->prox = clientes->inicio;
        clientes->inicio = cliente;
    }
    else if (modo == 2) { // Fim da lista
        clientes->fim->prox = cliente;
        clientes->fim = cliente;    
    }
}

void inserir_livro_base_dados(struct base_dados_livro *livros, struct dados_livro *livro, int modo)
{
    if (livros->inicio == NULL) {
        livros->fim = livro;
        livros->inicio = livro;
        return;
    }

    if (modo == 1) { // Inicio lista
        livro->prox = livros->inicio;
        livros->inicio = livro;
    }
    else if (modo == 2) { // Fim da lista
        livros->fim->prox = livro;
        livros->fim = livro;    
    }
}

struct dados_cliente *novo_cliente(unsigned int *codigo)
{
    struct dados_cliente *novo = NULL;

    // Alocação dinâmica
    novo = (struct dados_cliente*)malloc(sizeof(struct dados_cliente));

    // Entra com os dados
    novo->id = *codigo + 1;

    printf("Identificacao.......: %i\n", novo->id);

    printf("Nome do cliente.....: ");
    fgets(novo->nome, T_STR, stdin);
    retirar_enter(novo->nome);
    formatar_maiuscula(novo->nome);

    printf("Email...............: ");
    fgets(novo->email, T_STR, stdin);
    retirar_enter(novo->email);
    formatar_maiuscula(novo->email);

    printf("Telefone de contato.: ");
    fgets(novo->telefone, T_STR, stdin);
    retirar_enter(novo->telefone);

    novo->prox = NULL;

    *codigo += 1;

    return novo;
}

struct dados_livro *novo_livro(unsigned int *codigo)
{
    struct dados_livro *novo = NULL;

    // Aloca um novo livro
    novo = (struct dados_livro*)malloc(sizeof(struct dados_livro));

    novo->prox = NULL;

    novo->id = *(codigo)+1;
    *(codigo) += 1;

    printf("Identificacao........: %i\n", novo->id);

    printf("Publicacao...........: ");
    scanf("%i", &novo->publicacao);

    printf("Valor do livro.......: ");
    scanf("%f", &novo->valor);
    getchar();

    printf("Titulo...............: ");
    fgets(novo->titulo, T_STR, stdin);
    retirar_enter(novo->titulo);
    formatar_maiuscula(novo->titulo);

    printf("Autor principal......: ");
    fgets(novo->autor_principal, T_STR, stdin);
    retirar_enter(novo->autor_principal);
    formatar_maiuscula(novo->autor_principal);

    printf("Estoque..............: ");
    scanf("%i", &novo->qtd_estoque);

    return novo;
}
