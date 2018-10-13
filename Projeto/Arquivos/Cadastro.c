// Parte do programa acerca das fun��es de cadastro

// Bibliotecas. Colocar bibliotecas criadas caso uma parte deste preograma precise delas
#include "Cadastro.h"
#include <stdio.h>
#include <stdlib.h>

//Struct para cadastro de conveniado
struct cConveniado {
	//Variaveis num�ricas usando INT
	//int civil = 0;
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

//Struct para cadastro de Fornecedor
struct cFornecedor {
	//Variaveis num�ricas usando INT

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

//Fun��o de menu do item cadastro
int cadastroFC() {
    int opcao;

    do {
        system("cls"); // Limpa a tela toda vez que acessado

        printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
        printf(  "|            Voce esta em:  CADASTRO            |\n");
        printf(  "|  Selecione a opcao desejada no menu abaixo:   |\n");
        printf(  "|-----------------------------------------------|\n");
        printf(  "| 1. Cadastrar Conveniado                       |\n");
        printf(  "| 2. Cadastrar Fornecedor                       |\n");
        printf(  "| 3. Listar Conveniados                         |\n");
        printf(  "| 4. Listar Fornecedores                        |\n");
        printf(  "| 5. Consultar Conveniados                      |\n");
        printf(  "| 6. Consultar Fornecedores                     |\n");
        printf(  "| 9. Sair                                       |\n");
        printf(  "|-----------------------------------------------|\n");
        printf(  "  Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            cadConveniado();
            break;
        case 2:
            cadFornecedor();
            break;
        case 3:
            lConveniado();
            break;
        case 4:
            lForncedor();
            break;
        case 5:
            conConveniado(1);
            break;
        case 9:
            return 0; // Volta ao Main
            break;
        default:
            printf("\nOpcao invalida!! Digite novamente");
        }

        getchar();

    } while(opcao != 9);

    return 0;
}

// Fun��es Auxiliares
void menuConsultaConveniado(int key) {
    switch (key) {
        case 5:

    }
}

// Cadastra um novo conveniado
int cadConveniado() {

    Conveniado *novo = malloc(sizeof(Conveniado));          // Alocação dinâmica
    char lixo;                                              // Buffer / lixo

    FILE *ConveniadoTxt = fopen("conveniado.txt", "ab");    // Abrindo conservando o conteúdo existente

    system("cls");

    printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
    printf(  "|     Voce esta em:  CADASTRO -> CONVENIADO     |\n");
    printf(  "|-----------------------------------------------|\n\n");

    printf("Contrato no: \n\n"); // int definido pelo

    scanf("%c", &lixo);
    printf(" Nome completo: ");
    fgets(novo->nome, 101, stdin);

    printf(" Eatado civil:\n  1. Solteiro\n  2. Casado\n  3. Viuvo\n ");
    scanf("%d", &novo->civil);
    scanf("%c", &lixo);

    printf(" Profissao: ");
    fgets(novo->profissao, 51, stdin);

    printf(" CEP (so numeros): ");
    fgets(novo->cep, 8, stdin);

    printf(" Endereco: ");
    fgets(novo->endereco, 101, stdin);

    printf(" Cidade: ");
    fgets(novo->cidade, 31, stdin);

    printf(" UF: ");
    fgets(novo->uf, 3, stdin);
    scanf("%c", &lixo);

    printf(" RG (so digitos): ");
    fgets(novo->rg, 10, stdin);

    printf(" CPF (so numeros: ");
    fgets(novo->cpf, 12, stdin);

    printf(" Data de nascimento (so numeros): ");
    fgets(novo->bday, 9, stdin);

    printf(" Carencia (so numeros): ");
    fgets(novo->carencia, 9, stdin);

    printf(" Telefone: ");
    fgets(novo->telefone, 12, stdin);

    printf(" E-mail: ");
    fgets(novo->email, 31, stdin);

    printf(" Plano:\n  1. Basico\n  2. Plus\n  3. Platinum\n ");
    scanf("%d", &novo->plano);
    scanf("%c", &lixo);

    printf("Observacoes: ");
    fgets(novo->observacao, 201, stdin);

    printf("\n --- Cadastro concluido com sucesso! --- \n");

    system("pause");

    fwrite(novo, sizeof(Conveniado), 1, ConveniadoTxt);

    fclose(ConveniadoTxt);
    free(novo);

    return 0;
}

// Cadastra um novo fornecedor
int cadFornecedor() {
    system("cls");

    Fornecedor *novo = malloc(sizeof(Fornecedor));
    char lixo;

    FILE *FornecedorTxt = fopen("fornecedor.txt", "ab");

    printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
    printf(  "|     Voce esta em:  CADASTRO -> FORNECEDOR     |\n");
    printf(  "|-----------------------------------------------|\n\n");

    printf(" Contrato no: \n\n"); // int

    scanf("%c", &lixo);

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
    scanf("%c", &lixo);

    printf(" CEP (so numeros): ");
    fgets(novo->cep, 9, stdin);

    printf(" CNPJ (so numeros: ");
    fgets(novo->cnpj, 15, stdin);

    printf(" Contrato: ");
    fgets(novo->contrato, 201, stdin);

    printf(" Telefone: ");
    fgets(novo->telefone, 12, stdin);

    printf(" Site: ");
    fgets(novo->site, 51, stdin);

    printf(" E-mail: ");
    fgets(novo->email, 31, stdin);

    printf(" Observacoes: ");
    fgets(novo->observacao, 201, stdin);

    system("pause");

    fwrite(novo, sizeof(Fornecedor), 1, FornecedorTxt);

    fclose(FornecedorTxt);
    free(novo);

    return 0;
}

// Lista conveniados
int lConveniado() {

    Conveniado *leitura = malloc(sizeof(Conveniado));
    int i = 0, tam, option;

    FILE *lista;
    lista = fopen("conveniado.txt", "rb");

    tam = sizeof(Conveniado);

    system("cls");

    printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
    printf(  "| Voce esta em:  CADASTRO -> LISTAR CONVENIADOS |\n");
    printf(  "|-----------------------------------------------|\n\n");

    do {
        fseek(lista, tam*i, SEEK_SET);
        fread(leitura, sizeof(Conveniado), 1, lista);

        if (feof(lista))
            break;

        printf(" Contrato no: \n\n");
        printf(" Nome: %s", leitura->nome);

        switch(leitura->plano) {
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

        printf(" Profissao: %s", leitura->profissao);
        printf(" Nascimento: %s", leitura->bday);
        printf(" Carencia: %s", leitura->carencia);
        printf(" Endereco: %s", leitura->endereco);
        printf(" CEP: %s", leitura->cep);
        printf(" Cidade: %s", leitura->cidade);
        printf(" UF: %s\n", leitura->uf);

        switch(leitura->civil) {
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

        printf(" RG: %s", leitura->rg);
        printf(" CPF: %s", leitura->cpf);
        printf(" Telefone: %s", leitura->telefone);
        printf(" E-mail: %s", leitura->email);
        printf("\n Observacoes: %s", leitura->observacao);

        printf("\n Deseja continuar?\n 1. Sim\n 2. Nao\n");
        scanf("%d", &option);

        if (option == 2)
            return 0;

        i++;
    } while (1);

    fclose(lista);
    free(leitura);

    system("pause");

    return 0;
}

// Lista fornecedores
int lForncedor() {

    Fornecedor *leitura = malloc(sizeof(Fornecedor));
    int i = 0, tam, option;

    FILE *lista;
    lista = fopen("fornecedor.txt", "rb");

    tam = sizeof(Fornecedor);

    system("cls");

    printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
    printf(  "| Voce esta em:  CADASTRO -> LISTAR CONVENIADOS |\n");
    printf(  "|-----------------------------------------------|\n\n");

    do {
        fseek(lista, tam*i, SEEK_SET);
        fread(leitura, sizeof(Fornecedor), 1, lista);

        if (feof(lista))
            break;

        printf(" Contrato no: \n\n");
        printf(" Nome: %s", leitura->nome);
        printf(" Fornece: %s", leitura->produto);
        printf(" CNPJ: %s", leitura->cnpj);
        printf(" Endereco: %s", leitura->endereco);
        printf(" CEP: %s", leitura->cep);
        printf(" Cidade: %s", leitura->cidade);
        printf(" UF: %s\n", leitura->uf);
        printf(" Telefone: %s", leitura->telefone);
        printf(" Site: %s", leitura->site);
        printf(" E-mail: %s", leitura->email);
        printf(" Contrato: %s", leitura->contrato);
        printf("\n Observacoes: %s", leitura->observacao);

        printf("\n Deseja continuar?\n 1. Sim\n 2. Nao\n");
        scanf("%d", &option);

        if (option == 2)
            return 0;

        i++;
    } while (1);

    fclose(lista);
    free(leitura);

    system("pause");

    return 0;
}

// Consulta conveniado
int conConveniado(int key) {

    char buscaRG[10], buscaNome[101];

    Conveniado *leitura = malloc(sizeof(Conveniado));
    int i = 0, tam, option;

    FILE *lista;
    lista = fopen("conveniado.txt", "rb");

    tam = sizeof(Conveniado);

    system("cls");

    if (key == 1) {
        printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
        printf(  "|  Voce esta em: CADASTRO -> EXCLUIR CONVENIADO |\n");
        printf(  "|   Selecione a opcao desejada no menu abaixo:  |\n");
        printf(  "|-----------------------------------------------|\n");
        printf(  "| 1. Buscar por nome                            |\n");
        printf(  "| 2. Buscar por RG                              |\n");
        printf(  "| 3. Buscar por numero do contrato              |\n");
        printf(  "| 9. Sair                                       |\n");
        printf(  "|-----------------------------------------------|\n");
        printf(  "  Opcao: ");
        scanf("%d", &option);

        return 0;
    }

    else {
        printf("\n|-------------- FUNERARIA CARONTE --------------|\n");
        printf(  "|Voce esta em: CADASTRO -> CONSULTAR CONVENIADO |\n");
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
        case 1:
            printf("\n Digite o RG para busca: ");
            fgets(buscaRG, 10, stdin);
            break;
        case 2:
            printf("\n Digite o nome para busca: ");
            fgets(buscaNome, 101, stdin);
            break;
        case 3:
            break;
        case 9:
            return 0; // Volta ao Cadastro
            break;
        default:
            printf("\nOpcao invalida!! Digite novamente");
        }
    }



    do {
        fseek(lista, tam*i, SEEK_SET);
        fread(leitura, sizeof(Conveniado), 1, lista);

        if (feof(lista))
            break;

        printf(" Contrato no: \n\n");
        printf(" Nome: %s", leitura->nome);

        switch(leitura->plano) {
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

        printf(" Profissao: %s", leitura->profissao);
        printf(" Nascimento: %s", leitura->bday);
        printf(" Carencia: %s", leitura->carencia);
        printf(" Endereco: %s", leitura->endereco);
        printf(" CEP: %s", leitura->cep);
        printf(" Cidade: %s", leitura->cidade);
        printf(" UF: %s\n", leitura->uf);

        switch(leitura->civil) {
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

        printf(" RG: %s", leitura->rg);
        printf(" CPF: %s", leitura->cpf);
        printf(" Telefone: %s", leitura->telefone);
        printf(" E-mail: %s", leitura->email);
        printf("\n Observacoes: %s", leitura->observacao);

        printf("\n Deseja continuar?\n 1. Sim\n 2. Nao\n");
        scanf("%d", &option);

        if (option == 2)
            return 0;

        i++;
    } while (1);

    return 0;
}
