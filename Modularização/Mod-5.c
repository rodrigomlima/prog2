/*
    Exerc�cio 5: programa para gerenciar uma lista de contas
    banc�rias

    FEITO POR: Rodrigo de Lima Martins
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 15 // Tamanho do vetor

int n_conta = 1; // Contador global de contas
/*
    A ideia de um contador global vem da possibilidade de recuperar contas apagadas
    anteriormente. Nenhuma fun��o para tal foi implmentada no c�digo
*/

// Estrutura para contas
typedef struct Contas
{
    int numero;
    char nome[80];
    float saldo;
} Contas;

// PROT�TIPOS DAS FUN��ES
void inicializar(Contas contas[TAM], int *valorados);   // Inicializa a estrutura de contas
int cadastrar(Contas contas[TAM], int *valorados);      // Cadastra novas contas
void visualizar(Contas contas[TAM]);                    // Visualiza conta de acordo com o nome digitado
int excluir(Contas contas[TAM], int *valorados);        // Exclui a conta de menor saldo

// FUN��O MAIN
int main (void)
{
    // Declara��o de vari�veis
    Contas contas[TAM];     // Estrutura das contas
    int valorados;          // Conta quantas contas est�o cadastradas
    int op;                 // Seletor de op��es
    int verifica;           // Verifica status das fun��es

    // Inicializa a estrutura
    inicializar(contas, &valorados);

    // Menu principal
    do
    {
        printf("\n\n---- GERENCIADOR DE CONTAS ----");
        printf("\nOpcoes");
        printf("\n\n1. Cadastrar contas");
        printf("\n2. Visualizar contas de um cliente");
        printf("\n3. Excluir a conta de menor saldo");
        printf("\n4. Sair");

        printf("\n Digite a opcao desejada: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1: // Cadastra contas
            verifica = cadastrar(contas, &valorados);
            if (verifica == 0)  // Caso tenha dado certo
                printf("\nOperacao realizada com sucesso!\n");
            else                // Caso tenha atingido o limite ou j� se est� nele
                printf("\nLimite de contas ja atingido!\n");
            break;

        case 2: // Visualizar conta de um cliente
            visualizar(contas);
            break;

        case 3: // Exclui a conta de menor saldo
            verifica = excluir(contas, &valorados);
            if (verifica == 0)  // Caso exista uma conta para ser exclu�da
                printf("\nOperacao realizada com sucesso!\n");
            else                // Caso n�o haja contas a serem exclu�das
                printf("\nNao ha contas registradas!\n");
            break;

        case 4: // Condi��o de sa�da
            break;

        default: // Op��o digitada inv�lida
            printf("Opcao invalidada! Digite novamente!!!");
        }
    } while (op != 4); // Condi��o de sa�da do loop

    return 0;
}

// Inicializa a estrutura de contas
void inicializar(Contas contas[TAM], int *valorados)
{
    int i;  // Contador

    for (i = 0; i < TAM; i++)
    {
        contas[i].numero = -1; // -1 � o padr�o para espa�o n�o atribu�do
    }

    *valorados = 0; // Nenhuma conta cadastrada -> 0
}

// Cadastra novas contas
int cadastrar(Contas contas[TAM], int *valorados)
{
    int i;      // Contador
    char op;    // Op��o de menu

    // Caso a lista esteja j� cheia
    if (*valorados == TAM)
    {
        return 1; // Cadastro completo
    }

    // Percorre vetor para encontrar espa�os para cadastro
    for (i = 0; i < TAM; i++)
    {
        if (contas[i].numero == -1)  // Se encontrar uma op��o "vazia" (igual a -1)
        {
            // Cadastro do numero das contas usa um contador global
            contas[i].numero = n_conta;
            n_conta++; // Novas contas nunca usar�o n�meros das antigas

            // Inserir o nome do cliente
            printf("\nDigite o nome do cliente: ");
            getchar(); // Lixo
            fgets(contas[i].nome, 80, stdin);

            // Inserir o saldo da conta
            printf("\nDigite o saldo da conta: ");
            scanf("%f", &contas[i].saldo);

            ++*valorados;   // Adiciona ao contador de valores alocados

            getchar(); // Lixo

            printf("\nConta adicionada com sucesso!!");             // Mensagem de confirma��o
            printf("\nVoce deseja inserir mais uma conta? [s/n] "); // Condi��o de sa�da
            scanf(" %c", &op);                                      // Armazena resposta

            if (op == 'n' || op == 'N') // Sai da fun��o
                return 0;
        }
    }
    // Retorna 1 caso n�o encontre onde adicionar um valor ou quando n�o tiver mais como adicionar contas
    return 1;
}

// Visualiza conta de acordo com o nome digitado
void visualizar(Contas contas[TAM])
{
    int i;          // Contador
    int ck = 0;     // Verificador
    char busca[80]; // Vetor para busca

    // Inser��o do nome para busca
    printf("\nDigite o nome do cliente desejado: ");
    getchar();
    fgets(busca, 80, stdin);

    // Percorre o vetor
    for (i = 0; i < TAM; i++)
    {
        if (strcmp(contas[i].nome, busca) == 0)     // Verifica se os nomes s�o iguais
            if (contas[i].numero != -1)             // Verifica se a conta � v�lida
            {
                // Imprime os dados da conta
                printf("Conta encontrada:\n");
                printf(" Conta no: %d\tNome: %s     Saldo: %.2f\n", contas[i].numero, contas[i].nome, contas[i].saldo);
                ck++;                       // Conta um valor
            }
    }
    if (ck == 0)    // Mensagem caso n�o se encontre contas
        printf("\nNenhuma conta encontrada!\n");
}

// Exclui a conta de menor saldo
int excluir(Contas contas[TAM], int *valorados)
{
    int i, j;        // Contador
    int pos = -1;    // Armazena posi��o, tomando -1 como valor para nenhuma posi��o

    for (i = 0; i < TAM; i++)           // Percorre o vetor, procurando uma conta v�lida
    {
        if (contas[i].numero != -1)     // Verifica se a conta � v�lida
        {
            pos = i;                    // Guarda a posi��o
            break;                      // Sai do loop
        }
    }

    for (j = i; j < TAM; j++)                           // Percorre o vetor, come�ando por i
    {
        if (contas[j].numero != -1)                     // Verifica se a conta � v�lida
            if (contas[j].saldo < contas[pos].saldo)    // Verifica saldo em rela��o a posi��o guardada
                pos = j;                                // Armazena nova posi��o se verdadeiro
    }
    if (pos == -1)                  // Caso n�o tenha achado nenhuma conta
        return 1;                   // Retorna 1
    else                            // Caso tenha achado alguma conta
    {
        contas[pos].numero = -1;    // Invalida a posi��o
        --*valorados;               // Desconta das posi��es valoradas
        return 0;                   // Retorna 1
    }
}
