#include "./include/menus.h"
#include "./include/cadastros.h"
#include "./include/relatorios.h"
#include "./include/arquivos.h"
#include "./include/utils.h"
#include "./include/consultas.h"
#include <string.h>
#include <stdio.h>


#define FIM     0

int main()
{
    int opcao_menu_principal;
    int opcao_sub_menu, opcao_sub_sub_menu;
    string nome_arq, titulo;

    // Bases de dados (clientes e livros)
    struct base_dados_cliente clientes;
    struct base_dados_livro livros;

    // Inicializar as bases de dados
    inicializar_base_clientes(&clientes);
    inicializar_base_livros(&livros);

    carregar_dados_clientes(&clientes);
    carregar_dados_livros(&livros);

    do {
        opcao_menu_principal = menu_principal();

        switch (opcao_menu_principal) {
            
            case 1: do {
                        opcao_sub_menu = sub_menu_cadastros();
                        switch (opcao_sub_menu) {

                            case 1: inserir_cliente_base_dados(&clientes, novo_cliente(&clientes.contador), 1);
                                    break;

                            case 2: inserir_livro_base_dados(&livros, novo_livro(&livros.contador), 2);
                                    break;                            
                        }
                    } while (opcao_sub_menu != FIM);

                    break;
            
            case 2: do {
                        opcao_sub_menu = sub_menu_relatorios();
                        switch (opcao_sub_menu) {
                            
                            case 1: do {
                                        opcao_sub_sub_menu = sub_menu_tipo_relatorio();

                                        switch (opcao_sub_sub_menu) {

                                            case 1: // Tela
                                                    listar_clientes(clientes.inicio);
                                                    break;

                                            case 2: // Txt sem formatação
                                                    printf("Nome do arquivo? ");
                                                    fgets(nome_arq, T_STR, stdin);
                                                    retirar_enter(nome_arq);
                                                    strcat(nome_arq, ".txt");
                                                    exportar_dados_clientes_txt(clientes.inicio, nome_arq);
                                                    break;
                                            
                                            case 3: // CSV
                                                    printf("Nome do arquivo? ");
                                                    fgets(nome_arq, T_STR, stdin);
                                                    retirar_enter(nome_arq);
                                                    strcat(nome_arq, ".csv");
                                                    exportar_dados_clientes_csv(clientes.inicio, nome_arq);
                                                    break;

                                            case 4: // HTML
                                                    printf("Nome do arquivo? ");
                                                    fgets(nome_arq, T_STR, stdin);
                                                    retirar_enter(nome_arq);
                                                    strcat(nome_arq, ".html");
                                                    exportar_dados_clientes_html(clientes.inicio, nome_arq);
                                                    break;
                                        }


                                    } while (opcao_sub_sub_menu != FIM);
                                    
                                    break;
                            
                            case 2: listar_livros(livros.inicio);
                                    break;

                            case 3: break;

                            case 4: break;          
                        }
                    } while (opcao_sub_menu != FIM);

                    break;
            
            case 3: do {
                        opcao_sub_menu = sub_menu_consultas();

                        switch (opcao_sub_menu) {
                                case 1: printf("Qual o titulo do livro? ");
                                        fgets(titulo, T_STR, stdin);
                                        retirar_enter(titulo);
                                        formatar_maiuscula(titulo);
                                        struct dados_livro *aux = localizar_livro_por_nome(titulo, livros.inicio);
                                        if (aux) {
                                                mostrar_dados_livro(aux, stdout);
                                        }
                                        else {
                                                printf("Livro %s nao encontrado!\n", titulo);
                                        }
                                        break;
                                case 2: break;                                
                        }
                } while (opcao_sub_menu != FIM);
                    
                    break;

            case 0: printf("Tchau!!!\n");
                    salvar_dados_livros(livros.inicio);
                    salvar_dados_clientes(clientes.inicio);
                    break;
        }

    } while (opcao_menu_principal != FIM);

   
    return 0;
}