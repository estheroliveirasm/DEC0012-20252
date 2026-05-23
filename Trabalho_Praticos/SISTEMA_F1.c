#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define T_STR       100

typedef char string[T_STR];

typedef struct dados_equipe {
    string nome;
    string piloto_1;
    string piloto_2;
    unsigned int qtd_titulos_pilotos;
    unsigned int qtd_titulos_equipe;
    unsigned int ano_inicio;
    struct dados_equipe *prox;
} dados_equipe_t;

int menu();
void retirar_enter(char* str);
void formatar_maiusculo(char* str);
dados_equipe_t *nova_equipe();
void inserir_equipe_lista_pelo_inicio(dados_equipe_t **lista, dados_equipe_t *nova_equipe);
void inserir_equipe_lista_pelo_fim(dados_equipe_t **lista, dados_equipe_t *nova_equipe);
void mostrar_dados_equipe(dados_equipe_t *equipe, FILE* fp);
void listar_equipes_cadastradas(dados_equipe_t *lista);
dados_equipe_t *localizar_equipe_por_nome(char* nome_equipe, dados_equipe_t *lista);
void apagar_equipe(dados_equipe_t* equipe, dados_equipe_t **lista);
dados_equipe_t* localizar_fim_lista(dados_equipe_t *lista);
dados_equipe_t* localizar_anterior(dados_equipe_t *equipe, dados_equipe_t* lista);
void exportar_dados_arquivo_texto(string nome_arq, dados_equipe_t *lista);
void salvar_dados_arq_bin(dados_equipe_t *lista, string nome_arq);
void ler_dados_arq_bin(string nome_arq, dados_equipe_t **lista);



int main()
{
    dados_equipe_t *lista_equipes = NULL, *aux = NULL;
    int opcao;
    string nome_equipe, arquivo_nome;

    ler_dados_arq_bin("equipes_f1.bin", &lista_equipes);
    
    do {
        opcao = menu();

        switch (opcao) {

            case 0: salvar_dados_arq_bin(lista_equipes, "equipes_f1.bin");
                    break;

            case 1: aux = nova_equipe();
                    inserir_equipe_lista_pelo_inicio(&lista_equipes, aux);
                    break;

            case 2: aux = nova_equipe();
                    inserir_equipe_lista_pelo_fim(&lista_equipes, aux);
                    break;

            case 3: break;

            case 4: listar_equipes_cadastradas(lista_equipes);
                    break;

            case 5: printf("Qual a equipe que voce quer apagar? ");
                    fgets(nome_equipe, T_STR, stdin);
                    retirar_enter(nome_equipe);
                    formatar_maiusculo(nome_equipe);
                    aux = localizar_equipe_por_nome(nome_equipe, lista_equipes);
                    if (aux == NULL) {
                        printf("Equipe %s nao encontrada!!\n", nome_equipe);
                    }
                    else {
                        apagar_equipe(aux, &lista_equipes);
                    }
                    break;
            
            case 6: printf("Qual o nome do arquivo a ser gerado? ");
                    fgets(arquivo_nome, T_STR, stdin);
                    retirar_enter(arquivo_nome);
                    exportar_dados_arquivo_texto(arquivo_nome, lista_equipes);
                    break;
        }



    } while (opcao != 0);

    return 0;
}

int menu()
{
    int opcao;

    printf("1.Cadastrar nova equipe (pelo inicio)\n");
    printf("2.Cadastrar nova equipe (pelo fim)\n");
    printf("3.Localizar equipe por nome\n");
    printf("4.Listar todas as equipes cadastradas\n");
    printf("5.Apagar equipe\n");
    printf("6.Exportar dados para arquivo .txt\n");
    printf("0.Sair do programa\n");
    printf("::::: ");
    scanf("%d", &opcao);
    getchar();

    return opcao;
}

void retirar_enter(char* str)
{
    *(str+strlen(str)-1) = '\0';
    // str[strlen(str)-1] = '\0;
}

void formatar_maiusculo(char* str)
{
    for (int i = 0; i < strlen(str); i++) {
        //str[i] = toupper(str[i]);
        *(str+i) = toupper(*(str+i));
    }
}

dados_equipe_t *nova_equipe()
{
    dados_equipe_t *nova = NULL;

    // Alocação dinâmica
    nova = (dados_equipe_t*)malloc(sizeof(dados_equipe_t));

    // Leitura dos dados
    printf("Qual o nome da equipe................: ");
    fgets(nova->nome, T_STR, stdin);
    retirar_enter(nova->nome);
    formatar_maiusculo(nova->nome);

    printf("Qual o nome do primeiro piloto.......: ");
    fgets(nova->piloto_1, T_STR, stdin);
    retirar_enter(nova->piloto_1);
    formatar_maiusculo(nova->piloto_1);

    printf("Qual o nome do segundo piloto........: ");
    fgets(nova->piloto_2, T_STR, stdin);
    retirar_enter(nova->piloto_2);
    formatar_maiusculo(nova->piloto_2);

    printf("Quantidade de titulos................: ");
    scanf("%i", &nova->qtd_titulos_pilotos);

    printf("Quantidade de titulos por equipe.....: ");
    scanf("%i", &nova->qtd_titulos_equipe);

    printf("Inicio de atividade na Formula 1.....: ");
    scanf("%i", &nova->ano_inicio);

    nova->prox = NULL;

    return nova;
}

void inserir_equipe_lista_pelo_inicio(dados_equipe_t **lista, dados_equipe_t *nova_equipe)
{
    if (*lista != NULL) {
        nova_equipe->prox = *lista;
    }
    
    *lista = nova_equipe;
}

void inserir_equipe_lista_pelo_fim(dados_equipe_t **lista, dados_equipe_t *nova_equipe)
{
    dados_equipe_t *ultimo = NULL;

    if (*lista == NULL) {
        *lista = nova_equipe;
    }
    else {
        ultimo = localizar_fim_lista(*lista);
        ultimo->prox = nova_equipe;
    }
}

void mostrar_dados_equipe(dados_equipe_t *equipe, FILE* fp)
{
    fprintf(fp, "Nome da equipe....................: %s\n", equipe->nome);
    fprintf(fp, "Nome do primeiro piloto...........: %s\n", equipe->piloto_1);
    fprintf(fp, "Nome do segundo piloto............: %s\n", equipe->piloto_2);
    fprintf(fp, "Titulos (piloto)..................: %d\n", equipe->qtd_titulos_pilotos);
    fprintf(fp, "Titulos por equipe (construtores).: %d\n", equipe->qtd_titulos_equipe);
    fprintf(fp, "Inicio de atividade na Formula 1..: %d\n", equipe->ano_inicio);
}

void listar_equipes_cadastradas(dados_equipe_t *lista)
{
    while (lista) {
        mostrar_dados_equipe(lista, stdout);
        printf("\n");
        lista = lista->prox;
    }

    /*
    for (lista; lista != NULL; lista = lista->prox) {
        mostrar_dados_equipe(lista);
        printf("\n");
    }
    */

}
dados_equipe_t *localizar_equipe_por_nome(char* nome_equipe, dados_equipe_t *lista)
{
    while (lista) {
        if (!strcmp(nome_equipe, lista->nome)) {
            return lista;
        }
        lista = lista->prox;
    }

    return NULL;
}

void apagar_equipe(dados_equipe_t* equipe, dados_equipe_t **lista)
{
    dados_equipe_t *anterior = NULL;

    // Verifica se o dado a ser apagado eh o primeiro da lista
    if (*lista == equipe) {
        *lista = equipe->prox;
        free(equipe);
    }
    else {
        // O elemento a ser excluido não eh o primeiro
        anterior = localizar_anterior(equipe, *lista);
        anterior->prox = equipe->prox;
        free(equipe);
    }
}

dados_equipe_t *localizar_fim_lista(dados_equipe_t *lista)
{
    for (lista; lista->prox != NULL; lista = lista->prox);

    return lista;
}

dados_equipe_t* localizar_anterior(dados_equipe_t *equipe, dados_equipe_t* lista)
{
    if (equipe == lista) {
        return lista;
    }
    while (lista) {
        if (lista->prox == equipe) {
            return lista;
        }
        lista = lista->prox;
    }
}

void exportar_dados_arquivo_texto(string nome_arq, dados_equipe_t *lista)
{
    FILE *fp_arquivo = NULL;

    fp_arquivo = fopen(nome_arq, "w");

    while (lista) {
        mostrar_dados_equipe(lista, fp_arquivo);
        printf("\n");
        lista = lista->prox;
    }

    fclose(fp_arquivo);

}

void salvar_dados_arq_bin(dados_equipe_t *lista, string nome_arq)
{
    FILE *fp_arquivo = NULL;

    fp_arquivo = fopen(nome_arq, "wb");

    if (fp_arquivo == NULL) {
        printf("Erro na abertura do arquivo %s\n", nome_arq);
        return;
    }

    while (lista) {
        fwrite(lista, sizeof(dados_equipe_t), 1, fp_arquivo);
        lista = lista->prox;
    }

    fclose(fp_arquivo);
}

void ler_dados_arq_bin(string nome_arq, dados_equipe_t **lista)
{
    FILE *fp_arquivo = NULL;
    dados_equipe_t *equipe = NULL;

    fp_arquivo = fopen(nome_arq, "rb");

    if (fp_arquivo == NULL) {
        printf("Erro ao tentar abrir o arquivo %s\n",nome_arq);
        return;
    }

    while (!feof(fp_arquivo)) {
        equipe = (dados_equipe_t*)malloc(sizeof(dados_equipe_t));
        fread(equipe, sizeof(dados_equipe_t), 1, fp_arquivo);
        equipe->prox = NULL;
        if (!feof(fp_arquivo)) {
            inserir_equipe_lista_pelo_fim(lista, equipe);
        }
        else {
            free(equipe);
        }
    }

    fclose(fp_arquivo);

}