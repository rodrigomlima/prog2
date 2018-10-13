// --- BIBLIOTECAS É bom ir criando bibliotecas para cada arquivo novo do projeto
#include <stdio.h>
#include <stdlib.h>
#include "Conveniados.h"
#include "Fornecedores.h"
#include "Estoque.h"
#include "Vendas.h"

// --- FUNÇÃO MAIN: Funciona de menu principal
int main(void) {

    int opcao;

    do {
        printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
        printf(  "|                MENU  PRINCIPAL                |\n");
        printf(  "|   Selecione a opcao desejada no menu abaixo:  |\n");
        printf(  "|-----------------------------------------------|\n");
        printf(  "| 1. Conveniados                                |\n");
        printf(  "| 2. Fornecedores                               |\n");
        printf(  "| 3. Estoque                                    |\n");
        printf(  "| 4. Vendas                                     |\n");
        printf(  "| 9. Sair                                       |\n");
        printf(  "|-----------------------------------------------|\n");
        printf(  "  Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            conveniadoMenu();   // Funções em Conveniado.c. Chama menu
            break;
        case 2:
            fornecedorMenu();   // Funções em Fornecedor.c. Chama menu
            break;
        case 3:
            estoqueMenu();      // Funções em Estoque.c. Chama menu
            break;
        case 4:
            vendasMenu();       // Funções em Vendas.c. Chama menu
            break;
        case 9:
            break;              // Saída
        default:
            printf("\nOpcao invalida!! Digite novamente");
        }

        getchar();          // Buffer / lixo

        printf("\n\n\n\n"); // Pula umas linhas para a próxima iteração

    } while(opcao != 9);    // Condição de saída

    printf("\n\n\n\n");     // Pula umas linhas para a próxima iteração

    // Encerra o programa
    printf("\nTchau! Ate a proxima!\n");
    return 0;
}
