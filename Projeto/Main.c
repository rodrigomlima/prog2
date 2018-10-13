// --- BIBLIOTECAS � bom ir criando bibliotecas para cada arquivo novo do projeto
#include <stdio.h>
#include <stdlib.h>
#include "Conveniados.h"
#include "Fornecedores.h"
#include "Estoque.h"
#include "Vendas.h"

// --- FUN��O MAIN: Funciona de menu principal
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
            conveniadoMenu();   // Fun��es em Conveniado.c. Chama menu
            break;
        case 2:
            fornecedorMenu();   // Fun��es em Fornecedor.c. Chama menu
            break;
        case 3:
            estoqueMenu();      // Fun��es em Estoque.c. Chama menu
            break;
        case 4:
            vendasMenu();       // Fun��es em Vendas.c. Chama menu
            break;
        case 9:
            break;              // Sa�da
        default:
            printf("\nOpcao invalida!! Digite novamente");
        }

        getchar();          // Buffer / lixo

        printf("\n\n\n\n"); // Pula umas linhas para a pr�xima itera��o

    } while(opcao != 9);    // Condi��o de sa�da

    printf("\n\n\n\n");     // Pula umas linhas para a pr�xima itera��o

    // Encerra o programa
    printf("\nTchau! Ate a proxima!\n");
    return 0;
}
