#include "../include/consultas.h"
#include <string.h>
#include <stdio.h>

struct dados_livro *localizar_livro_por_nome(char *titulo, struct dados_livro *inicio)
{
    // Definitivamente não achei
    if (inicio == NULL) return NULL;
    // Achei
    if (strcmp(inicio->titulo,titulo) == 0) return inicio;    
    // Ainda nao achei
    return localizar_livro_por_nome(titulo, inicio->prox);

}