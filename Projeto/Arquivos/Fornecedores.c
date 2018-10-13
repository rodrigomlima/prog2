// Parte do programa acerca das fun��es de Fornecedores

// Bibliotecas. Colocar bibliotecas criadas caso uma parte deste preograma precise delas
#include "Fornecedores.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura com os valores de um fornecedor
struct cFornecedor {
	//Variaveis num�ricas usando INT
	int noContrato;

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

//Fun��o de menu do item fornecedores
int fornecedorMenu() {
    int opcao, posicao;

    do {
        printf("\n\n\n\n"); // Pula umas linhas para a pr�xima itera��o

        printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
        printf(  "|          Voce esta em:  FORNECEDORES          |\n");
        printf(  "|  Selecione a opcao desejada no menu abaixo:   |\n");
        printf(  "|-----------------------------------------------|\n");
        printf(  "| 1. Cadastrar                                  |\n");
        printf(  "| 2. Listar                                     |\n");
        printf(  "| 3. Consultar                                  |\n");
        printf(  "| 4. Alterar                                    |\n");
        printf(  "| 5. Excluir                                    |\n");
        printf(  "| 9. Sair                                       |\n");
        printf(  "|-----------------------------------------------|\n");
        printf(  "  Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            cadFornecedor();                // Cadastra fornecedor
            break;
        case 2:
            lForncedor();                   // Lista fornecedor
            break;
        case 3:
            conFornecedor(opcao);           // Consulta um fornecedor
            break;
        case 4:
            posicao = conFornecedor(opcao); // Pega a posição
            altFornecedor(posicao);         // Altera a posição indicada
            break;
        case 5:
            posicao = conFornecedor(opcao); // Pega a posição
            excFornecedor(posicao);         // Exclui a posição indicada
            break;
        case 9:
            return 0;                       // Volta ao Main
            break;
        default:                            // Opção inválida
            printf("\nOpcao invalida!! Digite novamente");
        }

        getchar();          // Buffer / lixo

    } while(opcao != 9);    // Condição de saída

    return 0;               // Volta ao Main
}

// Cadastra um novo fornecedor
int cadFornecedor() {
    printf("\n\n\n\n"); // Pula umas linhas para a pr�xima itera��o

    Fornecedor *novo = malloc(sizeof(Fornecedor));  // Aloca dinamicamente
    char lixo;                                      // Buffer / lixo

    FILE *FornecedorTxt = fopen("fornecedor.txt", "ab");    // Abre no final do arquivo

    // Caso não consiga abrir o arquivo
    if (FornecedorTxt == NULL) {
        printf("\n ---- ERRO: Nao foi possivel criar ou abrir o arquivo!!! ----\n");

        return 1;
    }

    printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
    printf(  "|     Voce esta em:  CADASTRO -> FORNECEDOR     |\n");
    printf(  "|-----------------------------------------------|\n\n");

    /* -----------------------------------
        Inser��o de dados na estrutura
    ----------------------------------- */

    printf(" Contrato no: ");
    scanf("%d", &novo->noContrato);
    printf("\n");

    scanf("%c", &lixo); // Buffer / lixo

    printf(" Fornecimento de: ");
    fgets(novo->produto, 51, stdin);

    printf(" Nome: ");
    fgets(novo->nome, 101, stdin);

    printf(" Endereco: ");
    fgets(novo->endereco, 101, stdin);

    printf(" Cidade: ");
    fgets(novo->cidade, 31, stdin);

    printf(" UF: ");
    fgets(novo->uf, 3, stdin);
    scanf("%c", &lixo); // Buffer / lixo

    printf(" CEP (so numeros): ");
    fgets(novo->cep, 9, stdin);
    getchar();          // Buffer / lixo

    printf(" CNPJ (so numeros: ");
    fgets(novo->cnpj, 15, stdin);
    getchar();          // Buffer / lixo

    printf(" Contrato: ");
    fgets(novo->contrato, 201, stdin);

    printf(" Telefone: ");
    fgets(novo->telefone, 12, stdin);
    getchar();          // Buffer / lixo

    printf(" Site: ");
    fgets(novo->site, 51, stdin);

    printf(" E-mail: ");
    fgets(novo->email, 31, stdin);

    printf(" Observacoes: ");
    fgets(novo->observacao, 201, stdin);

    fwrite(novo, sizeof(Fornecedor), 1, FornecedorTxt); // Escreve no arquivo

    fclose(FornecedorTxt);  // Fecha o arquivo
    free(novo);             // Libera a memória

    return 0;
}

// Lista fornecedores
int lForncedor() {

    Fornecedor *leitura = malloc(sizeof(Fornecedor));   // Aloca dinamicamente
    int i = 0, tam, option;                             // Variáveis auxiliares

    FILE *lista;
    lista = fopen("fornecedor.txt", "rb");              // Somente leitura

    // Caso não se consiga abrir o arquivo
    if (lista == NULL) {
        printf("\n ---- ERRO: Nao foi possivel abrir o arquivo!!! ----\n");

        return 1;
    }

    do  // Para cada item do arquivo
    {
        printf("\n\n\n\n"); // Pula umas linhas para a pr�xima itera��o

        printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
        printf(  "| Voce esta em: CADASTRO -> LISTAR FORNECEDORES |\n");
        printf(  "|-----------------------------------------------|\n\n");

        fseek(lista, (sizeof(Fornecedor) * i), SEEK_SET);   // Posiciona o cursor
        fread(leitura, sizeof(Fornecedor), 1, lista);       // Lê o item

        // Condição de saída
        if (feof(lista)) {
            printf(" Todos os resultados ja foram exibidos\n");
            break;
        }

        // Imprime item indicado da lista
        imprimeFornecedor(leitura);

        // Segunda condição de saída
        printf("\n Deseja continuar?\n 1. Sim\n 2. Nao\n");
        scanf("%d", &option);

        // Segunda condição de saída
        if (option == 2)
            return 0;

        i++;    // Para navegar entre itens
    } while (1);

    fclose(lista);  // Fecha o arquivo
    free(leitura);  // Libera a memória

    return 0;
}

// Consulta fornecedor. Retorna posição consultada
int conFornecedor(int key) {

    char buscaCNPJ[15], buscaNome[101];     // Variáveis para busca

    Fornecedor *leitura = malloc(sizeof(Fornecedor));   // Aloca dinamicamente
    int i = 0, option, buscaNum;                        // Variáveis auxiliares

    FILE *lista;
    lista = fopen("fornecedor.txt", "rb");  // Somente leitura

    // Caso não se consiga abrir o arquivo
    if (lista == NULL) {
        printf("\n ---- ERRO: Nao foi possivel abrir o arquivo!!! ----\n");

        return -2;
    }

    do  // Seleciona o tipo de busca
    {
        menuConsultaFornecedor(key); // Imprime o menu de acordo com o valor passado
        printf(  "  Opcao: ");
        scanf("%d", &option);

        switch (option) // Busca via...
        {
        case 1:         // ...CNPJ
            getchar();
            printf("\n Digite o CNPJ para busca: ");
            fgets(buscaCNPJ, 15, stdin);
            option = 9;
            break;
        case 2:         // ...nome
            getchar();
            printf("\n Digite o nome para busca: ");
            fgets(buscaNome, 101, stdin);
            option = 9;
            break;
        case 3:         // ...número do contrato
            getchar();
            printf("\n Digite o numero do contrato para busca: ");
            scanf("%d", &buscaNum);
            option = 9;
            break;
        case 9:         // Volta ao Menu Fornecedores
            return -1;
            break;
        default:        // Opção inválida
            printf("\nOpcao invalida!! Digite novamente");
        }
    } while (option != 9);  // Condição de saída

    do      // Busca cada item
    {
        fseek(lista, (sizeof(Fornecedor) * i), SEEK_SET);
        fread(leitura, sizeof(Fornecedor), 1, lista);

        if (feof(lista))    // Condição de saída: final do arquivo
        {
            printf("\nNenhuma busca correspondeu ao nome digitado!");
            break;
        }

        if (strcmp(buscaNome, leitura->nome) == 0)  // Busca por nome
        {
            imprimeFornecedor(leitura);
            break;
        }

        if (strcmp(buscaCNPJ, leitura->cnpj) == 0)  // Busca por CNPJ
        {
            imprimeFornecedor(leitura);
            break;
        }

        if (buscaNum == leitura->noContrato)        // Busca pro nº de contrato
        {
            imprimeFornecedor(leitura);
        }

        i++;    // Para navegar entre itens
    } while (1);    // Condição de saída já implementada dentro do loop

    fclose(lista);  // Fecha o arquivo
    free(leitura);  // Libera memória

    return i;       // Retorna posição
}

// Altera fornecedor
int altFornecedor(int pos) {

    Fornecedor *update = malloc(sizeof(Fornecedor));    // Alocado dinamicamente
    int tam;

    FILE *lista;
    lista = fopen("fornecedor.txt", "rb+");     // Leitura e atualização

    if (lista == NULL) {
        printf("\n ---- ERRO: Nao foi possivel abrir o arquivo!!! ----\n");

        return 1;
    }

    tam = sizeof(Fornecedor);   // Armazena tamanho da estrutura

    /* -----------------------------------
        O programa pede para alterar todos os dados da estrutura.
        Esta funcionalidade deve ser alterada futuramente.
    ----------------------------------- */

    fseek(lista, pos*tam, SEEK_SET);
    fread(update, sizeof(Fornecedor), 1, lista);

    printf(" Contrato no: %d\n", update->noContrato);

    printf(" Fornecimento de: ");
    fgets(update->produto, 51, stdin);

    printf(" Nome: ");
    fgets(update->nome, 101, stdin);

    printf(" Endereco: ");
    fgets(update->endereco, 101, stdin);

    printf(" Cidade: ");
    fgets(update->cidade, 31, stdin);

    printf(" UF: ");
    fgets(update->uf, 3, stdin);
    getchar();

    printf(" CEP (so numeros): ");
    fgets(update->cep, 9, stdin);

    printf(" CNPJ (so numeros: ");
    fgets(update->cnpj, 15, stdin);

    printf(" Contrato: ");
    fgets(update->contrato, 201, stdin);

    printf(" Telefone: ");
    fgets(update->telefone, 12, stdin);

    printf(" Site: ");
    fgets(update->site, 51, stdin);

    printf(" E-mail: ");
    fgets(update->email, 31, stdin);

    printf(" Observacoes: ");
    fgets(update->observacao, 201, stdin);

    printf("\n --- Alteracoes concluidas com sucesso! --- \n");

    fseek(lista, -tam, SEEK_CUR);                   // Volta no início do item
    fwrite(update, sizeof(Fornecedor), 1, lista);   // Re-escreve atualizado

    fclose(lista);      // Fecha o arquivo
    free(update);       // Libera memória

    return 0;
}

// Excluir fornecedor
int excFornecedor(int pos) {

    Fornecedor *leitura = malloc(sizeof(Fornecedor));   // Aloca dinamicamente
    int tam, option, i = 0;                             // Variáveis auxiliares

    FILE *antiga, *atual;
    antiga = fopen("fornecedor.txt", "rb"); // Arquivo original
    atual = fopen("nova-lista.c", "wb");    // Cópia do arquivo original

    // Caso algum dos arquivos não seja criado
    if (antiga == NULL) {
        printf("\n ---- ERRO: Nao foi possivel abrir o arquivo!!! ----\n");

        return 1;
    }

    if (atual == NULL) {
        printf("\n ---- ERRO: Nao foi possivel abrir o arquivo!!! ----\n");

        return 1;
    }

    tam = sizeof(Fornecedor);

    printf(" Voce deseja mesmo excluir este fornecedor?\n 1. Sim\n 2. Nao\n Opcao: ");
    scanf("%d", &option); // Confirma��o de exclus�o

    if (option == 1)    // Caso se deseje excluir
    {
        do              // Re-escreve todos os dados no arquivo novo
        {
            fseek(antiga, tam*i, SEEK_SET);
            fread(leitura, sizeof(Fornecedor), 1, antiga);

            if (feof(antiga))           // Condi��o de sa�da
                break;

            if ((tam*i) != (tam*pos))   // Copia apenas os dados diferentes aos pedidos
            {
                fwrite(leitura, sizeof(Fornecedor), 1, atual);
            }
            i++;        // Para navegar entre os itens
        } while (1);    // Condição de saída definida dentro do loop
    }
    printf("--- Exclusao concluida com sucesso! ---");

    // Fecha os arquivos
    fclose(antiga);
    fclose(atual);
    remove("fornecedor.txt");                   // Exclui o arquivo antigo
    rename("nova-lista.c", "fornecedor.txt");   // Renomeia o novo com o nome do antigo

    free(leitura);                              // Libera a memória da estrutura

    return 0;
}

// --- FUN��ES AUXILIARES

// Menu de consultas: as fun��es de consultar, alterar e excluir usam basicamente os mesmos menus
void menuConsultaFornecedor(int key) {
    switch (key) {
        case 3:
            printf("\n\n\n\n"); // Pula umas linhas para a pr�xima itera��o
            printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
            printf(  "|     Voce esta em: FORNECEDOR -> CONSULTAR     |\n");
            printf(  "|   Selecione a opcao desejada no menu abaixo:  |\n");
            printf(  "|-----------------------------------------------|\n");
            printf(  "| 1. Consultar por CNPJ                         |\n");
            printf(  "| 2. Consultar por Nome                         |\n");
            printf(  "| 3. Consultar por numero do contrato           |\n");
            printf(  "| 9. Sair                                       |\n");
            printf(  "|-----------------------------------------------|\n");
            break;
        case 4:
            printf("\n\n\n\n"); // Pula umas linhas para a pr�xima itera��o
            printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
            printf(  "|      Voce esta em: FORNECEDOR -> ALTERAR      |\n");
            printf(  "|   Selecione a opcao desejada no menu abaixo:  |\n");
            printf(  "|-----------------------------------------------|\n");
            printf(  "| 1. Consultar por CNPJ                         |\n");
            printf(  "| 2. Consultar por Nome                         |\n");
            printf(  "| 3. Consultar por numero do contrato           |\n");
            printf(  "| 9. Sair                                       |\n");
            printf(  "|-----------------------------------------------|\n");
            break;
        case 5:
            printf("\n\n\n\n"); // Pula umas linhas para a pr�xima itera��o
            printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
            printf(  "|      Voce esta em: FORNECEDOR -> EXCLUIR      |\n");
            printf(  "|   Selecione a opcao desejada no menu abaixo:  |\n");
            printf(  "|-----------------------------------------------|\n");
            printf(  "| 1. Consultar por CNPJ                         |\n");
            printf(  "| 2. Consultar por Nome                         |\n");
            printf(  "| 3. Consultar por numero do contrato           |\n");
            printf(  "| 9. Sair                                       |\n");
            printf(  "|-----------------------------------------------|\n");
            break;
        default:
            printf("Opcao invalida! Digite novamente!");
            break;
    }
}

// Imprime os dados do fornecedor: esta opera��o se repete diversas vezes no programa
void imprimeFornecedor(Fornecedor *imprime) {

        printf(" Contrato no: %d\n", imprime->noContrato);
        printf(" Nome: %s", imprime->nome);
        printf(" Fornece: %s", imprime->produto);
        printf(" CNPJ: %s\n", imprime->cnpj);
        printf(" Endereco: %s", imprime->endereco);
        printf(" CEP: %s\n", imprime->cep);
        printf(" Cidade: %s", imprime->cidade);
        printf(" UF: %s\n", imprime->uf);
        printf(" Telefone: %s", imprime->telefone);
        printf(" Site: %s", imprime->site);
        printf(" E-mail: %s", imprime->email);
        printf(" Contrato: %s", imprime->contrato);
        printf("\n Observacoes: %s", imprime->observacao);
}
