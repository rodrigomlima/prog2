// Parte do programa acerca das fun��es de estoque

// --- BIBLIOTECAS: Colocar bibliotecas criadas caso uma parte deste preograma precise delas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estoque.h"
#include "Fornecedores.h"

// --- ESTRUTURAS

// Esturuta para os valores de itens do estoque
struct sEstoque {
    char produto[51];
    char fornecedor[101];
    int quantia, codigo;
    float valor_custo;
    float valor_venda;
};

//Estrutura com os valores de um fornecedor
struct cFornecedor {
	//Variaveis num�ricas usando INT
	/* */

	//Variaveis puramente num�ricas usando CHAR
	char cnpj[15];
	char telefone[12];

	//Variaveis usando CHAR
	char nome[101];
	char site[51];
	char endereco[101];
	char cidade[31];
	char cep[9];
	char uf[3];
	char email[31];
	char observacao[201];
	char contrato[201];

	//Especificacao de fornecimento
	char produto[51];
};

// --- FUN��ES PRINCIPAIS

//Fun��o de menu do item estoque
int estoqueMenu () {
    // Declara��o de vari�veis
    int opcao, posicao;

    do {
        printf("\n\n\n\n"); // Pula umas linhas para a pr�xima itera��o

        printf("\n|------------- FUNERARIA CARONTE -------------|\n");
        printf(  "|            Voce esta em: ESTOQUE            |\n");
        printf(  "| Selecione a opcao desejada no menu abaixo:  |\n");
        printf(  "|---------------------------------------------|\n");
        printf(  "| 1. Consultar                                |\n");
        printf(  "| 2. Listar                                   |\n");
        printf(  "| 3. Alterar                                  |\n");
        printf(  "| 4. Inicializar                              |\n");
        printf(  "| 9. Sair                                     |\n");
        printf(  "|---------------------------------------------|\n");
        printf(  "  Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                conEstoque(opcao);              // Consulta estoque
                break;
            case 2:
                lEstoque();                     // Lista o estoque
                break;
            case 3:
                posicao = conEstoque(opcao);    // Consulta para pegar a posição
                altEstoque(posicao);            // Altera o estoque na posição indicada
                break;
            case 4:
                iniEstoque();                   // Inicializa o estoque
                break;
            case 9:
                return 0;                       // Volta ao Main
                break;
            default:    // Opção inválida
                printf("\nOpcao invalida!! Digite novamente");
        }

        getchar();          // Buffer / lixo

    } while(opcao != 9);    // Condição de saída

    return 0;
}

// Inicializar estoque. Pega o que foi fornecido no fornecedor
int iniEstoque() {

    Fornecedor *leitura = malloc(sizeof(Fornecedor));   // Aloca dinamicamente. Estrutura de Fornecedores
    Item *novo = malloc(sizeof(Item));                  // Aloca dinamicamente. Estrutura de Estoque
    int i = 0;                                          // Variável adicional

    FILE *busca, *lista;                                // Declara arquivos
    busca = fopen("fornecedor.txt", "rb");              // Leitura
    lista = fopen("estoque.txt", "wb");                 // Escrita (só deve se inicializar uma vez)

    // Caso dê erro de abertura nos arquivos
    if (busca == NULL) {
        printf("\n ---- ERRO: Nao foi possivel abrir o arquivo!!! ----\n");

        return 1;
    }

    if (lista == NULL) {
        printf("\n ---- ERRO: Nao foi possivel criar ou abrir o arquivo!!! ----\n");

        return 1;
    }

    do  // Consulta cada fornecedor e item
    {
        fseek(busca, (sizeof(Fornecedor) * i), SEEK_SET);   // Posiciona o cursor
        fread(leitura, sizeof(Fornecedor), 1, busca);       // Lê os dados do fornecedor

        if (feof(busca))                                // Condição de saída
            break;

        strcpy(novo->produto, leitura->produto);        // Copia
        strcpy(novo->fornecedor, leitura->nome);        // Copia
        novo->quantia = 0;                              // Inicializa com 0

        // Cadastra dados adicionais para estoque
        printf("\n Digite o codigo do produto %s ", novo->produto);
        scanf("%d", &novo->codigo);
        printf(" Digite o seu valor de custo:\n ");
        scanf("%f", &novo->valor_custo);
        printf(" Digite o seu valor de venda:\n ");
        scanf("%f", &novo->valor_venda);

        fwrite(novo, sizeof(Item), 1, lista);   // Escreve no arquivo

        i++;        // Conta os itens
    } while (1);    // Condição de saída já implementada dentro do loop

    printf("--- Estoque inicializado com sucesso! ---\n");

    // Fecha os arquivos
    fclose(busca);
    fclose(lista);
    // Libera as memórias
    free(leitura);
    free(novo);

    return 0;
}

// Listar Estoque
int lEstoque() {

    Item *leitura = malloc(sizeof(Item));   // Aloca dinacamente
    int i = 0, option;                 // Variáveis auxiliares

    FILE *lista;
    lista = fopen("estoque.txt", "rb");     // Apenas leitura

    if (lista == NULL) {
        printf("\n ---- ERRO: Nao foi possivel abrir o arquivo!!! ----\n");

        return 1;
    }

    printf("\n\n\n\n"); // Pula umas linhas para a pr�xima itera��o

    printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
    printf(  "|    Voce esta em: ESTOQUE -> LISTAR ESTOQUE    |\n");
    printf(  "|-----------------------------------------------|\n\n");

    do  // Percorre pelo arquivo, imprimindo os dados
    {
        fseek(lista, (sizeof(Item) * i), SEEK_SET); // Posiciona o cursor
        fread(leitura, sizeof(Item), 1, lista);     // Lê o item

        // Condição de saída
        if (feof(lista))
            break;

        imprimeEstoque(leitura);    // Chama função de impressão

        // Segunda condição de saída
        printf("\n Deseja continuar?\n 1. Sim\n 2. Nao\n");
        scanf("%d", &option);

        if (option == 2) // Segunda condição de saída
            return 0;

        i++;            // Contador para próximo item
    } while (1);

    fclose(lista);      // Fecha o arquivo
    free(leitura);      // Libera da memória

    return 0;
}

// Consultar o estoque
int conEstoque (int key) {
    // Declaração de variáveis para busca
    int buscaCodigo;
    char buscaProduto[51], buscaFornecedor[101];

    Item *leitura = malloc(sizeof(Item));   // Aloca dinamicamente
    int i = 0, option;                      // Variáveis auxiliares

    FILE *lista;
    lista = fopen("estoque.txt", "rb");     // Apenas leitura

    // Caso não se consiga abrir o arquivo
    if (lista == NULL) {
        printf("\n ---- ERRO: Nao foi possivel abrir o arquivo!!! ----\n");

        return -2;
    }

    do  // Seleciona a opção de busca desejada
    {
        menuConsultaEstoque(key);   // Imprime o menu de acordo com o tipo de chamada
        printf(  "  Opcao: ");
        scanf("%d", &option);

        switch (option) // Seleciona o tipo de busca desejada
        {
        case 1:         // Por código
            getchar();
            printf("\n Digite o codigo para busca: ");
            scanf("%d", &buscaCodigo);
            option = 9;
            break;
        case 2:         // Por produto
            getchar();
            printf("\n Digite o produto para busca: ");
            fgets(buscaProduto, 51, stdin);
            option = 9;
            break;
        case 3:         // Por fornecedor
            getchar();
            printf("\n Digite o fornecedor para busca: ");
            fgets(buscaFornecedor, 101, stdin);
            option = 9;
            break;
        case 9:         // Condição de saída
            return -1;  // Volta ao Menu Estoque
            break;
        default:
            printf("\nOpcao invalida!! Digite novamente");
        }
    } while (option != 9);

    do  // Percorre o arquivo para encontrar o item desejado...
    {
        fseek(lista, (sizeof(Item)*i), SEEK_SET);   // Posiciona o cursor
        fread(leitura, sizeof(Item), 1, lista);     // Lê o item

        if (feof(lista))    // Condição de saída
        {
            printf("\nNenhuma busca correspondeu ao nome digitado!");
            break;
        }

        if (buscaCodigo == leitura->codigo)     // ...por código
        {
            imprimeEstoque(leitura);
            break;
        }


        if (strcmp(buscaProduto, leitura->produto) == 0)    // ...por produto
        {
            imprimeEstoque(leitura);
            break;
        }

        if (strcmp(buscaFornecedor, leitura->fornecedor) == 0) // ... por fornecedor
        {
            imprimeEstoque(leitura);
            break;
        }

        i++;    // Para percorrer entre os itens
    } while (1);    // Condição de saída já implementada no loop

    fclose(lista);  // Fecha o arquivo
    free(leitura);  // Libera memória

    return i;       // Retorna posição do item consultado
}

// Alterar valores dos itens do estoque
int altEstoque(int pos) {

    Item *update = malloc(sizeof(Item));    // Alocado dinamicamente
    int tam, option, q;                     // Variáveis auxiliares

    FILE *lista;                            
    lista = fopen("estoque.txt", "rb+");    // Leitura e atualização

    // Caso não se consiga abrir o arquivo
    if (lista == NULL) {
        printf("\n ---- ERRO: Nao foi possivel abrir o arquivo!!! ----\n");

        return 1;
    }

    tam = sizeof(Item);                     // Armazena o tamanho de um item da estrutura

    fseek(lista, pos*tam, SEEK_SET);        // Posiciona o cursor na posição a se alterar
    fread(update, sizeof(Item), 1, lista);  // Lê o item

    // Seleção de modo de alteração
    printf("\n Como deseja alterar a quantidade?");
    printf("\n 1. Adicionando");
    printf("\n 2. Subtraindo");
    printf("\n 3. Novo valor\n");
    printf("\n X. Apenas alterar preços (digite qualquer valor inteiro)\n");
    scanf("%d", &option);

    switch(option)  // Alteração via...
    {
        case 1:     // ...adição
            printf("\n Quantidade atual: %d unidades\n Adicionando: ", update->quantia);
            scanf("%d", &q);
            update->quantia += q;
            break;
        case 2:     // ...subtração
            printf("\n Quantidade atual: %d unidades\n Subtraindo: ", update->quantia);
            scanf("%d", &q);
            update->quantia -= q;
            break;
        case 3:     // ...novo valor
            printf("\n Quantidade atual: %d unidades\n Nova quantidade: ", update->quantia);
            scanf("%d", &update->quantia);
        default:    // Nenhuma alteração
            break;
    }

    // Caso a quantidade digitada seja negativa
    while (update->quantia < 0)
    {
        printf("\nQuantidade negativa! Insira um valor positivo: ");
        scanf("%d", &update->quantia);
    }

    // Alteração de valores do produto
    printf("\n Valor de custo atual: R$%.2f\n Novo valor de custo: ", update->valor_custo);
    scanf("%f", &update->valor_custo);
    printf("\n Valor de venda atual: R$%.2f\n Novo valor de venda: ", update->valor_venda);
    scanf("%f", &update->valor_venda);

    printf("\n--- Alteracoes realizadas com sucesso! ---\n");

    fseek(lista, -tam, SEEK_CUR);           // Retorna a posição inicial do item
    fwrite(update, sizeof(Item), 1, lista); // Re-escreve atualizado

    fclose(lista);      // Fecha o arquivo
    free(update);       // Libera memória

    return 0;
}

// --- FUN��ES AUXILIARES

// Imprime os dados do estoque: esta opera��o se repete diversas vezes no programa
void imprimeEstoque(Item *imprime) {

    printf(" Codigo: %d\n", imprime->codigo);
    printf(" Produto: %s", imprime->produto);
    printf(" Fornecedor: %s", imprime->fornecedor);
    printf(" Quantidade: %d unidades\n", imprime->quantia);
    printf(" Valor de custo: R$%.2f\n", imprime->valor_custo);
    printf(" Valor de venda: R$%.2f\n", imprime->valor_venda);
}

// Menu de consultas: as fun��es de consultar, alterar e excluir usam basicamente os mesmos menus
void menuConsultaEstoque(int key) {
    switch (key) {
        case 1:     // Para consulta
            printf("\n\n\n\n"); // Pula umas linhas para a pr�xima itera��o
            printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
            printf(  "|      Voce esta em:  ESTOQUE -> CONSULTAR      |\n");
            printf(  "|   Selecione a opcao desejada no menu abaixo:  |\n");
            printf(  "|-----------------------------------------------|\n");
            printf(  "| 1. Consultar por Codigo                       |\n");
            printf(  "| 2. Consultar por Produto                      |\n");
            printf(  "| 3. Consultar por Fornecedor                   |\n");
            printf(  "| 9. Sair                                       |\n");
            printf(  "|-----------------------------------------------|\n");
            break;
        case 3:     // Para alteração
            printf("\n\n\n\n"); // Pula umas linhas para a pr�xima itera��o
            printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
            printf(  "|       Voce esta em:  ESTOQUE -> ALTERAR       |\n");
            printf(  "|   Selecione a opcao desejada no menu abaixo:  |\n");
            printf(  "|-----------------------------------------------|\n");
            printf(  "| 1. Consultar por Codigo                       |\n");
            printf(  "| 2. Consultar por Produto                      |\n");
            printf(  "| 3. Consultar por Fornecedor                   |\n");
            printf(  "| 9. Sair                                       |\n");
            printf(  "|-----------------------------------------------|\n");
            break;
        default:    // Opção inválida
            printf("Opcao invalida! Digite novamente!");
            break;
    }
}

/*
    Fun��o para coletar dados de estoque. Usado no .c de Vendas.
    Esta função deve ser removida em futuras versões
*/
int colCodProduto(int *codigo, int *quantia, float *valor) {

    int buscaCodigo;
    char buscaProduto[51], buscaFornecedor[101];

    Item *leitura = malloc(sizeof(Item));
    int i = 0, tam, option;

    FILE *lista;
    lista = fopen("estoque.txt", "rb+");

    if (lista == NULL) {
        printf("\n ---- ERRO: Nao foi possivel abrir o arquivo!!! ----\n");

        return 1;
    }

    tam = sizeof(Item);

    do {
        printf("\n\n\n\n"); // Pula umas linhas para a pr�xima itera��o
        printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
        printf(  "|        Voce esta em: VENDAS -> EFETUAR        |\n");
        printf(  "|   Selecione a opcao desejada no menu abaixo:  |\n");
        printf(  "|-----------------------------------------------|\n");
        printf(  "| 1. Consultar por Codigo                       |\n");
        printf(  "| 2. Consultar por Produto                      |\n");
        printf(  "| 3. Consultar por Fornecedor                   |\n");
        printf(  "| 9. Sair                                       |\n");
        printf(  "|-----------------------------------------------|\n");
        printf(  "  Opcao: ");
        scanf("%d", &option);

                switch (option) {
        case 1: // Buscar por Codigo
            getchar();
            printf("\n Digite o codigo para busca: ");
            scanf("%d", &buscaCodigo);
            option = 9;
            break;
        case 2: // Buscar por nome do produto
            getchar();
            printf("\n Digite o produto: ");
            fgets(buscaProduto, 51, stdin);
            option = 9;
            break;
        case 3: // Buscar por fornecedor
            getchar();
            printf("\n Digite o fornecedor para busca: ");
            fgets(buscaFornecedor, 101, stdin);
            option = 9;
            break;
        case 9:
            return -1; // Volta ao Menu Vendas
            break;
        default:
            printf("\nOpcao invalida!! Digite novamente");
        }
    } while (option != 9);

    do { // Busca o dado correspondente...
        fseek(lista, tam*i, SEEK_SET);
        fread(leitura, sizeof(Item), 1, lista);

        if (feof(lista)) {
            printf("\nNenhuma busca correspondeu ao nome digitado!");
            break;
        } // Condi��o de sa�da

        if (buscaCodigo == leitura->codigo) {
            break;
        } // ...ao codigo

        if (strcmp(buscaProduto, leitura->produto) == 0) {
            break;
        } // ...ao produto

        if (strcmp(buscaFornecedor, leitura->fornecedor) == 0) {
            break;
        } // ...ao fornecedor

        i++;
    } while (1);

    printf("\n Digite a quantidade do produto desejada: ");
    scanf("%d", &(*quantia));
    leitura->quantia = leitura->quantia - *quantia;

    *codigo = leitura->codigo;
    *valor = leitura->valor_venda;

    fclose(lista);
    free(leitura);

    return 0;
}
