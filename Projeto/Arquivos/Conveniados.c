// Parte do programa acerca das fun��es de Conveniados

// --- BIBLIOTECAS: Colocar bibliotecas criadas caso uma parte deste preograma precise delas
#include "Conveniados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- ESTRUTURAS

// Estrutura com os valores de um conveniado
struct cConveniado {
	//Variaveis num�ricas usando INT
	int civil;
	/*
	1 - Solteiro
	2 - Casado
	3 - Vi�vo
	0 - Default
	*/
	int plano;
	/*
	1 - Basico
	2 - Plus
	3 - Platinum
	0 - Default
	*/
	int noContrato;

	//Variaveis puramente num�ricas usando CHAR
	char rg[10];
	char cpf[12];
	char telefone[12];
    char bday[9];
    char carencia[9]; //Data para uso do plano

	//Variaveis usando CHAR
	char nome[101];
	char profissao[51];
	char endereco[101];
	char cidade[31];
	char cep[9];
	char uf[3];
	char email[31];
	char observacao[201];
};

// --- FUN��ES PRINCIPAIS

//Fun��o de menu do item conveniados
int conveniadoMenu() {
    // Declara��o de vari�veis
    int opcao, posicao;

    do {
        printf("\n\n\n\n"); // Pula umas linhas para a pr�xima itera��o

        printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
        printf(  "|           Voce esta em: CONVENIADOS           |\n");
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
            cadConveniado();                // Cadastra um conveniado
            break;
        case 2:
            lConveniado();                  // Lista conveniados
            break;
        case 3:
            conConveniado(opcao);           // Consulta um conveniado. A op��o muda o menu
            break;
        case 4:
            posicao = conConveniado(opcao); // A fun��o retorna a posi��o consultada
            altConveniado(posicao);         // Altera os dados da posi��o requisitada
            break;
        case 5:
            posicao = conConveniado(opcao); // A fun��o retorna a posi��o consultada
            excConveniado(posicao);         // Exclui os dados da posi��o requisitada
            break;
        case 9:
            return 0;                       // Volta ao Main
            break;
        default:                            // Nenhuma op��o v�lida: repete o menu
            printf("\nOpcao invalida!! Digite novamente");
        }

        getchar(); // Lixo

    } while(opcao != 9); // Condi��o de sa�da

    return 0;
}

// Cadastra um novo conveniado
int cadConveniado() {

    Conveniado *novo = malloc(sizeof(Conveniado));          // � importante controlar o tamanho das estruturas para manipula��es futuras

    FILE *ConveniadoTxt = fopen("conveniado.txt", "ab");    // Forma de criar os arquivos e preservar os registro anteriores ao mesmo tempo

    // Caso n�o consiga abrir o arquivo: retorna erro
    if (ConveniadoTxt == NULL) {
        printf("\n ---- ERRO: Nao foi possivel criar ou abrir o arquivo!!! ----\n");

        return 1;
    }

    printf("\n\n\n\n"); // Pula umas linhas para a pr�xima itera��o

    printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
    printf(  "|     Voce esta em: CONVENIADOS -> CADASTRO     |\n");
    printf(  "|-----------------------------------------------|\n\n");

    /* -----------------------------------
        Inser��o de dados na estrutura
    ----------------------------------- */
    printf("Contrato no: ");
    scanf("%d", &novo->noContrato);
    printf("\n");

    getchar(); // Buffer / lixo
    printf(" Nome completo: ");
    fgets(novo->nome, 101, stdin);

    printf(" Eatado civil:\n  1. Solteiro\n  2. Casado\n  3. Viuvo\n ");
    scanf("%d", &novo->civil);
    getchar(); // Buffer / lixo

    printf(" Profissao: ");
    fgets(novo->profissao, 51, stdin);

    printf(" CEP (so numeros): ");
    fgets(novo->cep, 9, stdin);
    getchar(); // Buffer / lixo

    printf(" Endereco: ");
    fgets(novo->endereco, 101, stdin);

    printf(" Cidade: ");
    fgets(novo->cidade, 31, stdin);

    printf(" UF: ");
    fgets(novo->uf, 3, stdin);
    getchar(); // Buffer / lixo

    printf(" RG (so digitos): ");
    fgets(novo->rg, 10, stdin);
    getchar(); // Buffer / lixo

    printf(" CPF (so numeros: ");
    fgets(novo->cpf, 12, stdin);
    getchar(); // Buffer / lixo

    printf(" Data de nascimento (so numeros): ");
    fgets(novo->bday, 9, stdin);
    getchar(); // Buffer / lixo

    printf(" Carencia (so numeros): ");
    fgets(novo->carencia, 9, stdin);
    getchar(); // Buffer / lixo

    printf(" Telefone: ");
    fgets(novo->telefone, 12, stdin);
    getchar(); // Buffer / lixo

    printf(" E-mail: ");
    fgets(novo->email, 31, stdin);

    printf(" Plano:\n  1. Basico\n  2. Plus\n  3. Platinum\n ");
    scanf("%d", &novo->plano);
    getchar(); // Buffer / lixo

    printf("Observacoes: ");
    fgets(novo->observacao, 201, stdin);

    printf("\n --- Cadastro concluido com sucesso! --- \n");

    fwrite(novo, sizeof(Conveniado), 1, ConveniadoTxt); // Escreve dados no arquivo

    fclose(ConveniadoTxt);                              // Fecha o arquivo
    free(novo);                                         // Libera a vari�vel da estrutura

    return 0;
}

// Lista conveniados
int lConveniado() {

    Conveniado *leitura = malloc(sizeof(Conveniado));   // Aloca dinamicamente a estrutura
    // Vari�veis auxiliares
    int i = 0, tam, option;

    FILE *lista;
    lista = fopen("conveniado.txt", "rb");              // Apenas leitura

    // Caso n�o consiga abrir o arquivo: retorna erro
    if (lista == NULL) {
        printf("\n ---- ERRO: Nao foi possivel abrir o arquivo!!! ----\n");

        return 1;
    }

    // Armazena o tamanho
    tam = sizeof(Conveniado);

    do {

        printf("\n\n\n\n"); // Pula umas linhas para a pr�xima itera��o

        printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
        printf(  "|      Voce esta em: CONVENIADOS -> LISTAR      |\n");
        printf(  "|-----------------------------------------------|\n\n");

        fseek(lista, tam*i, SEEK_SET);                  // Posiciona cursor
        fread(leitura, sizeof(Conveniado), 1, lista);   // L� a estrutura

        // Caso j� tenha lido todo o arquivo
        if (feof(lista)) {
            printf(" Todos os resultados ja foram exibidos\n");
            break;
        }

        imprimeConveniado(leitura); // Mostra os dados

        printf("\n Deseja continuar?\n 1. Sim\n 2. Nao\n");
        scanf("%d", &option); // N�o lista tudo de uma vez

        i++; // Para percorrer a estrutura
    } while (option != 2);  // Condi��o de sa�da

    fclose(lista);          // Fecha o arquivo
    free(leitura);          // Libera o espaço da estrutura

    return 0;
}

// Consulta conveniado
int conConveniado(int key) {

    // Vari�veis para consulta
    char buscaRG[10], buscaNome[101];

    Conveniado *leitura = malloc(sizeof(Conveniado));   // Aloca dinamicamente
    // Vari�veis auxiliares
    int i = 0, tam, option, buscaNum;

    FILE *lista;
    lista = fopen("conveniado.txt", "rb");              // Modo leitura

    // Caso n�o consiga abrir o arquivo: retorna erro
    if (lista == NULL) {
        printf("\n ---- ERRO: Nao foi possivel abrir o arquivo!!! ----\n");

        return -2;
    }

    tam = sizeof(Conveniado);

    do {
        menuConsultaConveniado(key); // Imprime o menu
        printf(  "  Opcao: ");
        scanf("%d", &option);

        switch (option) {
        case 1: // Buscar por RG
            getchar();
            printf("\n Digite o RG para busca: ");
            fgets(buscaRG, 10, stdin);
            option = 9;
            break;
        case 2: // Buscar por nome
            getchar();
            printf("\n Digite o nome para busca: ");
            fgets(buscaNome, 101, stdin);
            option = 9;
            break;
        case 3: // Buscar por numero do contrato
            getchar();
            printf("\n Digite o numero do contrato para busca: ");
            scanf("%d", &buscaNum);
            option = 9;
            break;
        case 9:
            return -1; // Volta ao Menu Conveniados
            break;
        default:
            printf("\nOpcao invalida!! Digite novamente");
        }
    } while (option != 9); // Condi��o de sa�da

    do  // Busca o dado correspondente...
    {
        fseek(lista, tam*i, SEEK_SET);
        fread(leitura, sizeof(Conveniado), 1, lista);

        if (feof(lista)) // (Condi��o de sa�da)
        {
            printf("\nNenhuma busca correspondeu ao nome digitado!");
            break;
        }

        if (strcmp(buscaNome, leitura->nome) == 0)  // ...ao nome
        {
            imprimeConveniado(leitura);
            break;
        }

        if (strcmp(buscaRG, leitura->rg) == 0)  // ...ao RG
        {
            imprimeConveniado(leitura);
            break;
        }

        if (buscaNum == leitura->noContrato)  // ...ao contrato
        {
            imprimeConveniado(leitura);
            break;
        }

        i++;        // Contador auxilia a percorrer os itens contidos no arquivo
    } while (1);    // O loop tem a condição colocada dentro dele para exibir a mensagem (linha 305)

    fclose(lista);  // Fecha o arquivo
    free(leitura);  // Libera a estrutura

    return i;       // Retorna a posição da estrutura
}

// Altera conveniado
int altConveniado(int pos) {

    Conveniado *update = malloc(sizeof(Conveniado));    // Alocado dinamicamente

    FILE *lista;
    lista = fopen("conveniado.txt", "rb+"); // Leitura e atualização

    if (lista == NULL) {
        printf("\n ---- ERRO: Nao foi possivel abrir o arquivo!!! ----\n");

        return 1;
    }

    fseek(lista, (pos * sizeof(Conveniado)), SEEK_SET); // Posi��o passada por refer�ncia
    fread(update, sizeof(Conveniado), 1, lista);        // Lê a estrutura

    printf("Contrato no: %d \n\n", update->noContrato);

    /*
        O programa pede para alterar todos os dados da estrutura.
        Esta funcionalidade deve ser alterada futuramente.
    */

    printf(" Nome completo: ");
    fgets(update->nome, 101, stdin);

    printf(" Eatado civil:\n  1. Solteiro\n  2. Casado\n  3. Viuvo\n ");
    scanf("%d", &update->civil);
    getchar(); // Buffer / lixo

    printf(" Profissao: ");
    fgets(update->profissao, 51, stdin);

    printf(" CEP (so numeros): ");
    fgets(update->cep, 8, stdin);

    printf(" Endereco: ");
    fgets(update->endereco, 101, stdin);

    printf(" Cidade: ");
    fgets(update->cidade, 31, stdin);

    printf(" UF: ");
    fgets(update->uf, 3, stdin);
    getchar(); // Buffer / lixo

    printf(" RG (so digitos): ");
    fgets(update->rg, 10, stdin);

    printf(" CPF (so numeros: ");
    fgets(update->cpf, 12, stdin);

    printf(" Data de nascimento (so numeros): ");
    fgets(update->bday, 9, stdin);

    printf(" Carencia (so numeros): ");
    fgets(update->carencia, 9, stdin);

    printf(" Telefone: ");
    fgets(update->telefone, 12, stdin);

    printf(" E-mail: ");
    fgets(update->email, 31, stdin);

    printf(" Plano:\n  1. Basico\n  2. Plus\n  3. Platinum\n ");
    scanf("%d", &update->plano);
    getchar(); // Buffer / lixo

    printf("Observacoes: ");
    fgets(update->observacao, 201, stdin);

    printf("\n --- Alteracoes concluidas com sucesso! --- \n");

    fseek(lista, -tam, SEEK_CUR); // Voltar ao in�cio da estrutura para regravar
    fwrite(update, sizeof(Conveniado), 1, lista);

    fclose(lista);
    free(update);

    return 0;
}

// Exclui conveniado
int excConveniado(int pos) {

    Conveniado *leitura = malloc(sizeof(Conveniado));   // Aloca dinamicamente
    int tam, option, i = 0;                             // Variáveis auxiliares

    FILE *antiga, *atual;
    antiga = fopen("conveniado.txt", "rb"); // Arquivo original
    atual = fopen("nova-lista.c", "wb");    // C�pia do arquivo original

    // Caso algum dos arquivos não seja criado
    if (antiga == NULL) {
        printf("\n ---- ERRO: Nao foi possivel abrir o arquivo!!! ----\n");

        return 1;
    }

    if (atual == NULL) {
        printf("\n ---- ERRO: Nao foi possivel abrir o arquivo!!! ----\n");

        return 1;
    }

    tam = sizeof(Conveniado);

    printf(" Voce deseja mesmo excluir este conveniado?\n 1. Sim\n 2. Nao\n Opcao: ");
    scanf("%d", &option); // Confirma��o de exclus�o

    if (option == 1)    // Caso se deseje excluir
    {
        do              // Re-escreve todos os dados no arquivo novo
        {
            fseek(antiga, tam*i, SEEK_SET);
            fread(leitura, sizeof(Conveniado), 1, antiga);

            if (feof(antiga)) // Condi��o de sa�da
                break;

            if ((tam*i) != (tam*pos)) // Copia apenas os dados diferentes aos pedidos
            {
                fwrite(leitura, sizeof(Conveniado), 1, atual);
            }
            i++;        // Para navegar entre os itens
        } while (1);    // Condição de saída definida dentro do loop
    }
    printf("--- Exclusao concluida com sucesso! ---");

    // Fecha os arquivos
    fclose(antiga);
    fclose(atual);
    remove("conveniado.txt");                   // Exclui o arquivo antigo
    rename("nova-lista.c", "conveniado.txt");   // Renomeia o novo com o nome do antigo

    free(leitura);                              // Libera a memória da estrutura

    return 0;
}

// --- FUN��ES AUXILIARES

// Menu de consultas: as fun��es de consultar, alterar e excluir usam basicamente os mesmos menus. Apenas imprime op��es do menu
void menuConsultaConveniado(int key) {
    switch (key) {
        case 3:                 // Menu de consulta
            printf("\n\n\n\n"); // Pula umas linhas para a pr�xima itera��o

            printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
            printf(  "|     Voce esta em: CONVENIADO -> CONSULTAR     |\n");
            printf(  "|   Selecione a opcao desejada no menu abaixo:  |\n");
            printf(  "|-----------------------------------------------|\n");
            printf(  "| 1. Consultar por RG                           |\n");
            printf(  "| 2. Consultar por Nome                         |\n");
            printf(  "| 3. Consultar por numero do contrato           |\n");
            printf(  "| 9. Sair                                       |\n");
            printf(  "|-----------------------------------------------|\n");
            break;
        case 4:                 // Menu de alteração
            printf("\n\n\n\n"); // Pula umas linhas para a pr�xima itera��o

            printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
            printf(  "|      Voce esta em: CONVENIADO -> ALTERAR      |\n");
            printf(  "|   Selecione a opcao desejada no menu abaixo:  |\n");
            printf(  "|-----------------------------------------------|\n");
            printf(  "| 1. Consultar por RG                           |\n");
            printf(  "| 2. Consultar por Nome                         |\n");
            printf(  "| 3. Consultar por numero do contrato           |\n");
            printf(  "| 9. Sair                                       |\n");
            printf(  "|-----------------------------------------------|\n");
            break;
        case 5:                 // Menu de consulta
            printf("\n\n\n\n"); // Pula umas linhas para a pr�xima itera��o


            printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
            printf(  "|      Voce esta em: CONVENIADO -> EXCLUIR      |\n");
            printf(  "|   Selecione a opcao desejada no menu abaixo:  |\n");
            printf(  "|-----------------------------------------------|\n");
            printf(  "| 1. Consultar por RG                           |\n");
            printf(  "| 2. Consultar por Nome                         |\n");
            printf(  "| 3. Consultar por numero do contrato           |\n");
            printf(  "| 9. Sair                                       |\n");
            printf(  "|-----------------------------------------------|\n");
            break;
        default:                // Opção inválida
            printf("Opcao invalida! Digite novamente!");
            break;
    }
}

// Imprime os dados do conveniado: esta opera��o se repete diversas vezes no programa. Apenas imprime as informa��es do conveniado
void imprimeConveniado (Conveniado *imprime) {

    printf(" Contrato no: %d\n", imprime->noContrato);
    printf(" Nome: %s", imprime->nome);

    switch(imprime->plano) {
        case 1:
            printf(" Plano: Basico\n");
            break;
        case 2:
            printf(" Plano: Plus\n");
            break;
        case 3:
            printf(" Plano: Platinum\n");
            break;
        default:
            printf(" Plano: Customizado\n");
    }

    printf(" Profissao: %s", imprime->profissao);
    printf(" Nascimento: %s\n", imprime->bday);
    printf(" Carencia: %s\n", imprime->carencia);
    printf(" Endereco: %s", imprime->endereco);
    printf(" CEP: %s\n", imprime->cep);
    printf(" Cidade: %s", imprime->cidade);
    printf(" UF: %s\n", imprime->uf);

    switch(imprime->civil) {
        case 1:
            printf(" Estado Civil: Solteiro(a)\n");
            break;
        case 2:
            printf(" Estado Civil: Casado(a)\n");
            break;
        case 3:
            printf(" Estado Civil: Viuvo(a)\n");
            break;
        default:
            printf(" Estado Civil: nao indentificado\n");
    }

    printf(" RG: %s\n", imprime->rg);
    printf(" CPF: %s\n", imprime->cpf);
    printf(" Telefone: %s\n", imprime->telefone);
    printf(" E-mail: %s", imprime->email);
    printf("\n Observacoes: %s", imprime->observacao);
}

/*
    Fun��o para coletar dados de cadastro. Usado no .c de Vendas.
    Esta função deve ser removida em futuras versões
*/
int colCadastro(int *codigo) {

    char buscaRG[10], buscaNome[101];

    Conveniado *leitura = malloc(sizeof(Conveniado));
    int i = 0, tam, option, buscaNum;

    FILE *lista;
    lista = fopen("conveniado.txt", "rb");

    if (lista == NULL) {
        printf("\n ---- ERRO: Nao foi possivel abrir o arquivo!!! ----\n");

        return 1;
    }

    tam = sizeof(Conveniado);

    do {
        printf("\n\n\n\n"); // Pula umas linhas para a pr�xima itera��o

        printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
        printf(  "|        Voce esta em: VENDAS -> EFETUAR        |\n");
        printf(  "|   Selecione a opcao desejada no menu abaixo:  |\n");
        printf(  "|-----------------------------------------------|\n");
        printf(  "| 1. Consultar por RG                           |\n");
        printf(  "| 2. Consultar por Nome                         |\n");
        printf(  "| 3. Consultar por numero do contrato           |\n");
        printf(  "| 9. Sair                                       |\n");
        printf(  "|-----------------------------------------------|\n");
        printf(  "  Opcao: ");
        scanf("%d", &option);

                switch (option) {
        case 1: // Buscar por RG
            getchar();
            printf("\n Digite o RG para busca: ");
            fgets(buscaRG, 10, stdin);
            option = 9;
            break;
        case 2: // Buscar por nome
            getchar();
            printf("\n Digite o nome para busca: ");
            fgets(buscaNome, 101, stdin);
            option = 9;
            break;
        case 3: // Buscar por numero do contrato
            getchar();
            printf("\n Digite o numero do contrato para busca: ");
            scanf("%d", &buscaNum);
            option = 9;
            break;
        case 9:
            return -1; // Volta ao Menu Vendas
            break;
        default:
            printf("\nOpcao invalida!! Digite novamente");
        }
    } while (option != 9);

    do // Busca o dado correspondente...
    {
        fseek(lista, tam*i, SEEK_SET);
        fread(leitura, sizeof(Conveniado), 1, lista);

        if (feof(lista)) {
            printf("\nNenhuma busca correspondeu ao nome digitado!");
            break;
        } // Condi��o de sa�da

        // ...ao nome
        if (strcmp(buscaNome, leitura->nome) == 0)
        {
            break;
        }

        // ...ao RG
        if (strcmp(buscaRG, leitura->rg) == 0)
        {
            break;
        }

        // ...ao contrato
        if (buscaNum == leitura->noContrato)
        {
            break;
        }

        i++;
    } while (1);

    *codigo = leitura->noContrato;

    fclose(lista);
    free(leitura);

    return 0;
}
