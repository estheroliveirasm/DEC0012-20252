/*
Exercício Proposto - Pequeno CAGR

Solução com alocação dinâmica de memória do vetor de dados. 
*/

// Inclusão de bibliotecas
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Definição de constantes numéricas
#define STR_SIZE            100
#define FIM                 0
#define TRUE                1
#define FALSE               0


// Definição de tipos de dados
typedef char string[STR_SIZE];

typedef enum {ATIVO = 1, TRANCADO = 2, DESISTENTE = 3} status_t;

typedef struct data {
    unsigned int dia;
    unsigned int mes;
    unsigned int ano;
} data_t;

typedef struct dados_aluno {
    unsigned long int matricula;
    string nome;
    data_t data_nascimento;
    unsigned int curso;
    float iaa;
    status_t status;
} dados_aluno_t;

typedef struct dados_curso {
    unsigned int codigo;
    string nome;
    unsigned int semestres;
    unsigned int creditos;
} dados_curso_t;

// Cabeçalho de funções auxiliares
int menu(void);
dados_aluno_t cadastrar_novo_aluno(dados_curso_t *cursos, int qtd_cursos);
dados_curso_t cadastrar_novo_curso();
void mostrar_dados_aluno(dados_aluno_t *aluno);
void mostrar_dados_curso(dados_curso_t *curso);
void listar_alunos_cadastrados(dados_aluno_t *alunos, int qtd_alunos);
void listar_cursos_cadastrados(dados_curso_t *cursos, int qtd_cursos);
int localizar_curso_por_codigo(int curso, dados_curso_t *cursos, int qtd_cursos);
void mostrar_alunos_por_curso(int codigo_curso, dados_aluno_t *alunos, int qtd_alunos);
int pesquisar_curso(string nome, dados_curso_t *cursos, int qtd_cursos);
int buscar_aluno(string nome_procurado, dados_aluno_t *alunos, int qtd_alunos);
void mostrar_status(status_t status);
int validar_curso(unsigned int curso, dados_curso_t *cursos, int qtd_cursos);
void mostrar_cursos_existentes(dados_curso_t *cursos, int qtd_cursos);
void remover_enter(string str);
void remover_enter_v2(string str2);
void remover_enter_v3(char *str);
void to_upper(char *str);
void limpar_tela();
void mostrar_msg(char *msg);



// Função principal
int main()
{
    // Variáveis locais
    dados_aluno_t *base_alunos = NULL;
    dados_curso_t *base_cursos = NULL;
    int qtd_alunos = 0, qtd_cursos = 0;
    int opc, codigo_curso, ind;
    string nome;
    int informacao;

    do {
        opc = menu();

        switch (opc) {

            case 1: if (base_cursos == NULL) {
                        base_cursos = (dados_curso_t*)malloc(sizeof(dados_curso_t));
                        *base_cursos = cadastrar_novo_curso();
                        qtd_cursos++;
                    }
                    else {                        
                        base_cursos = (dados_curso_t*)realloc(base_cursos, sizeof(dados_curso_t) * (qtd_cursos+1));
                        *(base_cursos+qtd_cursos) = cadastrar_novo_curso();
                        qtd_cursos++;
                    }
                    break;

            case 2: if (base_alunos == NULL) {
                        base_alunos = (dados_aluno_t*)malloc(sizeof(dados_aluno_t));
                        *(base_alunos) = cadastrar_novo_aluno(base_cursos, qtd_cursos);
                        qtd_alunos++;
                    }
                    else {                        
                        base_alunos = (dados_aluno_t*)realloc(base_alunos, sizeof(dados_aluno_t) * (qtd_alunos+1));
                        *(base_alunos+qtd_alunos) = cadastrar_novo_aluno(base_cursos, qtd_cursos);
                        qtd_alunos++;
                    }
                    break;

            case 3: listar_alunos_cadastrados(base_alunos, qtd_alunos);
                    break;

            case 4: listar_cursos_cadastrados(base_cursos, qtd_cursos);
                    break;

            case 5: printf("Qual o codigo do curso? ");
                    scanf("%d", &codigo_curso);
                    getchar();
                    if (localizar_curso_por_codigo(codigo_curso, base_cursos, qtd_cursos)) {
                        mostrar_alunos_por_curso(codigo_curso, base_alunos, qtd_cursos);
                    }
                    else {
                        printf("O curso %d nao esta cadastrado!\n", codigo_curso);                        
                    }
                    mostrar_msg("Pressione ENTER para continuar");
                    break;
            
            case 6: printf("Qual o nome do curso? ");
                    fgets(nome, STR_SIZE, stdin);
                    remover_enter_v2(nome);
                    to_upper(nome);
                    ind = pesquisar_curso(nome, base_cursos, qtd_cursos);
                    if (ind >= 0) {
                        mostrar_dados_curso(base_cursos+ind);
                        printf("\n");
                    }
                    else {
                        printf("Curso %s nao encontrado!!!\n", nome);
                    }
                    mostrar_msg("Pressione ENTER para continuar");
                    break;

            case 7: printf("Informe o nome do aluno a ser localizado? ");
                    fgets(nome, STR_SIZE, stdin);
                    remover_enter_v2(nome);
                    to_upper(nome);
                    informacao = buscar_aluno(nome, base_alunos, qtd_alunos);
                    if(informacao >= 0){
                        mostrar_dados_aluno(base_alunos+informacao);
                        printf("\n");
                    }
                    else{
                        printf("Aluno %s nao cadastrado!\n", nome);
                    }
                    mostrar_msg("Pressione ENTER para continuar");
                    break;


            case 0: printf("Fechando o programa..\n");

        }

    } while (opc != FIM);

    return 0;
}

int menu()
{
    int opc;
  
    limpar_tela();
    printf("1.Cadastrar curso\n");
    printf("2.Cadastrar aluno\n");
    printf("3.Mostrar alunos cadastrados\n");
    printf("4.Mostrar cursos cadastrados\n");
    printf("5.Listar alunos por curso\n");
    printf("6.Pesquisar curso por nome\n");
    printf("7.Buscar aluno por nome\n");
    printf("0.Sair do programa\n");
    printf("::: ");
    scanf("%i", &opc);
    getchar();

    return opc;
}

dados_aluno_t cadastrar_novo_aluno(dados_curso_t *cursos, int qtd_cursos)
{
    dados_aluno_t aluno;

    printf("Matricula do aluno...........: ");
    scanf("%lu", &aluno.matricula);
    getchar();

    printf("Nome do aluno................: ");
    fgets(aluno.nome, STR_SIZE, stdin);
    //remover_enter(aluno.nome);
    remover_enter_v2(aluno.nome);
    to_upper(aluno.nome);

    printf("Data de nascimento...........: ");
    scanf("%d/%d/%d", &aluno.data_nascimento.dia, &aluno.data_nascimento.mes, &aluno.data_nascimento.ano);

    do {
        printf("Curso matriculado............: ");
        scanf("%d", &aluno.curso);
    } while (!validar_curso(aluno.curso, cursos, qtd_cursos)); // Enquanto retornar FALSE continue solicitando o curso para o usuário

    printf("IAA..........................: 0\n");
    aluno.iaa = 0;

    printf("Status.......................: ATIVO\n");
    aluno.status = ATIVO;

    return aluno;
}

dados_curso_t cadastrar_novo_curso()
{
    dados_curso_t curso;

    printf("Codigo do curso............: ");
    scanf("%d", &curso.codigo);
    getchar();

    printf("Nome do curso..............: ");
    fgets(curso.nome, STR_SIZE, stdin);
    //remover_enter(curso.nome);
    //remover_enter_v2(curso.nome);
    remover_enter_v3(curso.nome);
    to_upper(curso.nome);

    printf("Numero de semestres........: ");
    scanf("%d", &curso.semestres);

    printf("Quantidade de creditos.....: ");
    scanf("%d", &curso.creditos);

    return curso;
}

void mostrar_dados_aluno(dados_aluno_t *aluno)
{
    printf("Matricula do aluno...........: %lu\n", aluno->matricula);
    printf("Nome do aluno................: %s\n", aluno->nome);
    printf("Data de nascimento...........: %d/%d/%d\n", aluno->data_nascimento.dia, aluno->data_nascimento.mes, aluno->data_nascimento.ano);
    printf("Curso matriculado............: %i\n", aluno->curso);
    printf("IAA..........................: %.2f\n", aluno->iaa);
    printf("Status.......................: ");
    mostrar_status(aluno->status);
}

void mostrar_dados_curso(dados_curso_t *curso)
{
    printf("Codigo do curso............: %d\n", curso->codigo);
    printf("Nome do curso..............: %s\n", curso->nome);
    printf("Numero de semestres........: %d\n", curso->semestres);
    printf("Quantidade de creditos.....: %d\n", curso->creditos);
}

void listar_alunos_cadastrados(dados_aluno_t *alunos, int qtd_alunos)
{
    for (int i = 0; i < qtd_alunos; i++) {
        mostrar_dados_aluno(alunos+i);
        printf("\n");
    }

    mostrar_msg("Pressione ENTER para continuar");
}

void listar_cursos_cadastrados(dados_curso_t *cursos, int qtd_cursos)
{
    limpar_tela();
    for (int i = 0; i < qtd_cursos; i++) {
        mostrar_dados_curso(cursos+i);
        printf("\n");
    }

    mostrar_msg("Pressione ENTER para continuar");
}

int localizar_curso_por_codigo(int curso, dados_curso_t *cursos, int qtd_cursos)
{
    for (int i = 0; i < qtd_cursos; i++) {
        if ((cursos+i)->codigo == curso) {
            return TRUE;
        }
    }

    return FALSE;
    
}

void mostrar_alunos_por_curso(int codigo_curso, dados_aluno_t *alunos, int qtd_alunos)
{
    for (int i = 0; i < qtd_alunos; i++) {
        if ((alunos+i)->curso == codigo_curso) {
            mostrar_dados_aluno(alunos+i);
            printf("\n");
        }
    }
}

int pesquisar_curso(string nome, dados_curso_t *cursos, int qtd_cursos)
{
    for(int i = 0; i < qtd_cursos; i++){
        if(strcmp((cursos+i)->nome, nome) == 0){
            return i;            
        }
    }
    return -1;

}

int buscar_aluno(string nome_procurado, dados_aluno_t *alunos, int qtd_alunos)
{
    for(int i = 0; i < qtd_alunos; i++){
        if(strcmp((alunos+i)->nome, nome_procurado) == 0){
            return i;            
        }
    }
    
    return -1;
}

void mostrar_status(status_t status)
{
    switch (status) {

        case ATIVO: 
             printf("ATIVO \n");
             break;

        case TRANCADO:
             printf("TRANCADO \n");
             break;
        
        case DESISTENTE:
             printf("DESISTENTE \n");
             break;
    }
}

int validar_curso(unsigned int curso, dados_curso_t *cursos, int qtd_cursos)
{
    if (localizar_curso_por_codigo(curso, cursos, qtd_cursos) == FALSE) {
        printf("Curso Invalido! Os cursos existentes sao: \n\n");
        mostrar_cursos_existentes(cursos, qtd_cursos);
        return FALSE;
    }

    return TRUE;
}

void mostrar_cursos_existentes(dados_curso_t *cursos, int qtd_cursos)
{
    for (int i = 0; i < qtd_cursos; i++) {
        printf("(%i) --> %s\n", (cursos+i)->codigo, (cursos+i)->nome);
    }
}

void remover_enter(string str)
{
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == '\n'){
            str[i] = '\0';
            break;
        }
    }
}
void remover_enter_v2(string str2)
{

    str2[strlen(str2) - 1] = '\0';

}

void remover_enter_v3(char *str)
{
    *(str+strlen(str) - 1) = '\0';
}

void to_upper(char *str)
{
    for (int i = 0; i < strlen(str); i++) {
        //*(str+i) = toupper(*(str+i));
        str[i] = toupper(str[i]);
    }
}

void limpar_tela()
{
    system("clear");
}

void mostrar_msg(char *msg)
{
    printf("**************************** Programa CAGR ******************************\n");
    printf("%s\n", msg);
    printf("*************************************************************************\n");
    getchar();
}