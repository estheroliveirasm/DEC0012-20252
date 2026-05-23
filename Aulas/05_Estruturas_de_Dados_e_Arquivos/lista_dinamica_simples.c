#include <stdio.h>
#include <stdlib.h>

struct produto {
    int id;
    float valor;
    struct produto *prox;
};

struct produto *novo(int id, float valor);
void mostrar_dados_produto(struct produto *p);
struct produto *inserir_produto_lista(struct produto *novo, struct produto *lista);
void mostrar_produtos(struct produto *lista);


int main()
{
    struct produto *ptr_lista = NULL, *aux = NULL;

    for (int i = 0; i < 10; i++) {
        // aux = novo(i+1, i*1.10);
        // ptr_lista = inserir_produto_lista(aux, ptr_lista);
        ptr_lista = inserir_produto_lista(novo(i+1, i*1.10), ptr_lista);
    }

    mostrar_produtos(ptr_lista);

    printf("Endereco apontado por ptr_lista: %p\n", ptr_lista);


    return 0;
}

struct produto *novo(int id, float valor)
{
    struct produto *novo = NULL;

    novo = (struct produto*)malloc(sizeof(struct produto));

    novo->id = id;
    novo->valor = valor;
    novo->prox = NULL;

    return novo;
}

void mostrar_dados_produto(struct produto *p)
{
    printf("Id do produto.................: %i\n", p->id);
    printf("Valor do produto..............: %.2f\n", p->valor);
    printf("Endereco na memoria...........: %p\n", p);
    printf("Endereco do proximo...........: %p\n\n", p->prox);
}

struct produto *inserir_produto_lista(struct produto *novo, struct produto *lista)
{
    // Política de inserção pelo início
    if (lista == NULL) {
        lista = novo;
    }
    else {
        novo->prox = lista;
        lista = novo;
    }

    // Retorna a nova lista
    return lista;
}

void mostrar_produtos(struct produto *lista)
{
    for (struct produto *aux = lista; aux != NULL; aux = aux->prox) {
        mostrar_dados_produto(aux);
    }

}