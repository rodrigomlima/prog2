// Parte do programa acerca das fun��es de venda

// Bibliotecas. Colocar bibliotecas criadas caso uma parte deste preograma precise delas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Vendas.h"
#include "Conveniados.h"
#include "Estoque.h"

// --- ESTRUTURAS
struct Transacao {
    int codigo;
    int codConveniado;
    int codProduto;
    int quantia;
    int pagamento; // numero corresponde ao tipo de pagamento
    /*
    1. Dinheiro
    2. Debito
    3. Credito
    4. Cheque
    */
    float desconto;
    float valor;

    char produto[51];
    char observacao[201];

};

// --- FUN��ES PRINCIPAIS

//Fun��o de menu do item Vendas
int vendasMenu () {
    int opcao;

    do {
        printf("\n\n\n\n"); // Pula umas linhas para a pr�xima itera��o

        printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
        printf(  "|             Voce esta em:  VENDAS             |\n");
        printf(  "|   Selecione a opcao desejada no menu abaixo:  |\n");
        printf(  "|-----------------------------------------------|\n");
        printf(  "| 1. Efetuar Venda                              |\n");
        printf(  "| 2. Listar Vendas                              |\n");
        printf(  "| 2. Consultar Venda                            |\n");
        printf(  "| 9. Sair                                       |\n");
        printf(  "|-----------------------------------------------|\n");
        printf(  "  Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            efeVenda();     // Efetua uma venda
            break;
        case 2:
            lVenda();       // Lista vendas. Pode estar instável
            break;
        case 3:
            conVenda();     // Consulta vendas. Pode estar instável
            break;
        case 9:
            return 0;       // Volta ao Main
            break;
        default:            // Opção inválida
            printf("\nOpcao invalida!! Digite novamente");
        }

        getchar();          // Buffer / Lixo

    } while(opcao != 9);    // Condição de saída

    return 0;
}

// Fun��o que realiza venda. Uma venda deve corresponder ao estoque e deve decrescer os produtos do registro
int efeVenda() {
    // Declaração de variáveis
    int option, iDesconto, codigo, quantia;
    float valor;

    Venda *nova = malloc(sizeof(Venda));    // Aloca dinamicamente

    FILE *escrita;
    escrita = fopen("vendas.txt", "ab");    // Abre no final do arquivo

    // Caso não se consiga abrir o arquivo
    if (escrita == NULL) {
        printf("\n ---- ERRO: Nao foi possivel criar ou abrir o arquivo!!! ----\n");

        return 1;
    }

    do  // Menu para efeturar vendas
    {
        printf("\n\n\n\n"); // Pula umas linhas para a pr�xima itera��o

        printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
        printf(  "|       Voce esta em: VENDAS -> EFETUAR         |\n");
        printf(  "|-----------------------------------------------|\n");
        printf(  "|     Deseja se cadastrar como conveniado ?     |\n");
        printf(  "| 1. Sim                                        |\n");
        printf(  "| 2. Nao                                        |\n");
        printf(  "| 3. Ja cadastrado                              |\n");
        printf(  "| 9. Sair                                       |\n");
        printf(  "|-----------------------------------------------|\n");
        printf(  "  Opcao: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:         // Cadastrar novo conveniado
                cadConveniado();                // Cadastra conviniado
                colCadastro(&codigo);           // Busca código do cadastrado
                nova->codConveniado = codigo;   // Código 
                option = 9;
                break;
            case 2:         // Não cadastrar
                nova->codConveniado = 0;
                option = 9;
                break;
            case 3:         // Usar usuário já cadastrado
                colCadastro(&codigo);
                nova->codConveniado = codigo;
                option = 9;
                break;
            case 9:         // Volta ao menu de vendas
                return 0;
                break;
            default:        // Opção inválida
                printf("\nOpcao invalida!! Digite novamente");
        }
        getchar();          // Buffer / Lixo

    } while(option != 9);   // Condição de saída

    /* -----------------------------------
        Inser��o de dados na estrutura
    ----------------------------------- */

    printf("\n\nVenda no: ");
    scanf("%d", &nova->codigo); 
    printf("\n");

    // Coletar o codigo do produto pedido e armazenar quantia e valor. Função em Estoque.c
    colCodProduto(&codigo, &quantia, &valor);

    nova->codProduto = codigo;
    nova->quantia = quantia;
    nova->valor = valor;

    // Seleção de desconto
    printf("Desconto?\n 1. Sim\n 2. Nao");
    scanf("%d", &iDesconto);

    if (iDesconto == 1) // Caso se dê desconto
    {
        printf("Digite o valor do desconto: ");
        scanf("%f", &nova->desconto);
        if (nova->desconto < 0.0)   // Coloca em negativo o valor caso não esteja
        {
            nova->desconto = nova->desconto * (-1.0);
        }
    }
    else    // Caso não se dê desconto
    {
        nova->desconto = 0.0;
    }

    printf("Forma de pagamento:\n1. Dinheiro\n2. Debito\n3. Credito\n4. Cheque");
    scanf("%d", &nova->pagamento);
    getchar();

    // Valor da venda: valor original - desconto
    nova->valor = nova->valor - nova->desconto;

    printf("\n\n\n\n"); // Pula umas linhas para a pr�xima itera��o

    printf("\n--- Venda efetuada com sucesso! ---\n");

    fwrite(nova, sizeof(Venda), 1, escrita);    // Escreve no arquivo

    fclose(escrita);    // Fecha o arquivo
    free(nova);         // Libera a memória

    return 0;
}

// Listar todas as vendas
int lVenda() {

    Venda *leitura = malloc(sizeof(Venda)); // Aloca dinamicamente
    int i = 0, tam, option;                 // Variáveis auxiliares

    FILE *lista;                            
    lista = fopen("vendas.txt", "rb");      // Somente leitura

    tam = sizeof(Venda);

    do  // Imprime um valor dos itens do arquivo
    {
        printf("\n\n\n\n"); // Pula umas linhas para a pr�xima itera��o

        printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
        printf(  "|  Voce esta em: VENDAS -> CONSULTAR -> LISTAR  |\n");
        printf(  "|-----------------------------------------------|\n");

        fseek(lista, tam*i, SEEK_SET);
        fread(leitura, sizeof(Venda), 1, lista);

        if (feof(lista))    // Condição de saída
        {
            printf(" Todos os resultados ja foram exibidos\n");
            break;
        }

        imprimeVenda(leitura);  // Imprime valores da posição carregada

        // Segunda condição de saída
        printf("\n Deseja continuar?\n 1. Sim\n 2. Nao\n");
        scanf("%d", &option);

        // Segunda condião de saída
        if (option == 2)
            return 0;

        i++;    // Para percorrer entre os itens
    } while (1);    // Condição de saída implementada dentro do loop

    fclose(lista);  // Fecha o arquivo
    free(leitura);  // Libera memória

    return 0;
}

// Consulta as vendas efetuadas
int conVenda() {
    // Declaração de Variáveis
    char buscaProduto[51];
    int option, buscaCodigo, buscaCodProduto, tam, i;

    Venda *leitura = malloc(sizeof(Venda)); // Aloca dinamicamente

    FILE *lista;
    lista = fopen("vendas.txt", "rb");  // Somente leitura

    tam = sizeof(Venda);

    do {
        printf("\n\n\n\n"); // Pula umas linhas para a pr�xima itera��o

        printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
        printf(  "|       Voce esta em: VENDAS -> CONSULTAR       |\n");
        printf(  "|-----------------------------------------------|\n");
        printf(  "| 1. Por codigo                                 |\n");
        printf(  "| 2. Por nome do produto                        |\n");
        printf(  "| 3. Por codigo do produto                      |\n");
        printf(  "| 4. Listar tudo                                |\n");
        printf(  "| 9. Sair                                       |\n");
        printf(  "|-----------------------------------------------|\n");
        printf(  "  Opcao: ");
        scanf("%d", &option);

        switch (option) {
        case 1:     // Buscar correspondentes via codigo
            getchar();
            printf("\n Digite o codigo para busca: ");
            scanf("%d", &buscaCodigo);
            option = 9;
            break;
        case 2:     // Buscar correspondentes via nome do produto
            getchar();
            printf("\n Digite o nome produto para busca: ");
            fgets(buscaProduto, 51, stdin);
            option = 9;
            break;
        case 3:     // Buscar correspondentes via c�digo do produto
            getchar();
            printf("\n Digite o codigo produto para busca: ");
            scanf("%d", &buscaCodProduto);
            option = 9;
            break;
        case 4:     // Listar todas as vendas
            getchar();
            lVenda();
            option = 9;
            break;
        case 9:     // Condição de saída
            return 0;
            break;
        default:    // Opção inválida
            printf("\nOpcao invalida!! Digite novamente");
        }
    } while (option != 9);  // Condição de saída

    do  // Busca de item no arquivo via...
    {
        fseek(lista, tam*i, SEEK_SET);
        fread(leitura, sizeof(Venda), 1, lista);

        if (feof(lista))    // Condição de saída
        {
            printf("\nNenhuma busca correspondeu ao nome digitado!");
            break;
        }

        if (buscaCodigo == leitura->codigo)                 // ...código
        {
            imprimeVenda(leitura);  // Imprime item
            break;
        }

        if (strcmp(buscaProduto, leitura->produto) == 0)    // ...produto
        {
            imprimeVenda(leitura);  // Imprime item
            break;
        }

        if (buscaCodProduto == leitura->codProduto)         // ...código do produto
        {
            imprimeVenda(leitura);  // Imprime item
            break;
        }

        i++;    // Para percorrer entre itens
    } while (1);    // Condição de saída implementada dentro do loop

    fclose(lista);
    free(leitura);

    return 0;
}

// --- FUN��ES AUXILIARES

// --- Fun��o para imprimir a venda
void imprimeVenda(Venda *imprime) {

    printf(" Codigo da venda: %d\n", imprime->codigo);
    printf(" Produto: %s", imprime->produto);
    printf(" Codigo do produto: %d\n", imprime->codProduto);
    printf(" Quantidade: %d\n", imprime->quantia);
    printf(" Valor original: %f", imprime->valor + ((-1.0)*(imprime->desconto)));
    printf(" Desconto: %f", imprime->desconto);
    printf(" Valor final: %f", imprime->valor);
    printf(" Tipo de pagamento: ");
    switch(imprime->pagamento){
        case 1:
            printf("Dinheiro\n");
        case 2:
            printf("Debito\n");
        case 3:
            printf("Credito\n");
        case 4:
            printf("Cheque\n");
        default:
            printf("Outro\n");
    }

    if (imprime->codConveniado != 0) {
        printf(" Codigo do conveniado: %d\n", imprime->codConveniado);
    }
}
