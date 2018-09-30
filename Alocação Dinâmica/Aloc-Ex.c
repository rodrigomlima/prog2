/*
    Programa para controle de estoque, com o estoque com aloca��o din�mica

    FEITO POR: Rodrigo de Lima Martins
    O programa n�o implementa nenhum controle de c�digos iguais
*/

#include<stdio.h>
#include<stdlib.h>

// Estrutura para estoque
typedef struct Estoque
{
    int codigo;
    int quantidade;
} Estoque;

// PROT�TIPO DAS FUN��ES
int adicionar_estoque(Estoque estoque[], int tamanho);              // Adiciona itens ao estoque
int pedido_cliente(Estoque estoque[], int tamanho);                 // Analisa pedidos dos clientes
void listar_estoque(Estoque estoque[], int tamanho);                // Lista o estoque atual
// Fun��es auxiliares
int busca_item(Estoque estoque[], int busca, int tamanho);          // Busca se item existe no estoque
int busca_quantidade(Estoque estoque[], int busca, int codigo);     // Busca se a quantidade � atend�vel no estoque

// FUN��O MAIN
int main(void)
{
    // Declara��o de vari�veis
    Estoque *estoque;   // Apontador para estrutura de estoque
    int n;              // Indicador do tamanho do estoque
    int verifica;       // Verifica se as fun��es funcionaram corretamente

    // Define quantidade de itens no estoque
    printf("Digite a quantidade o numero de mercadorias em estoque: ");
    scanf("%d", &n);

    estoque = malloc (sizeof (Estoque[n])); // Aloca dinamicamente o tamanho do estoque

    // Adiciona itens ao estoque
    verifica = adicionar_estoque(estoque, n);
    // Verifica se foi poss�vel adicionar os itens ao estoque
    if (verifica == 0)
    {
        printf("\nItens adicionados com sucesso!"); // Caso sim, mostra mensagem
    }
    else
    {
        printf("\nImpossivel adiconar ao estoque!"); // Caso n�o, mostra mensagem e encerra o programa
        return 1;
    }

    pedido_cliente(estoque, n); // Analise os pedidos dos cliente

    listar_estoque(estoque, n); // Lista os items antes de encerrar

    free(estoque); // Libera a mem�ria alocada

    return 0;
}

// Adiciona itens ao estoque
int adicionar_estoque(Estoque estoque[], int tamanho)
{
    int i; // Contador

    // Verifica se tamanho � poss�vel de ser usado
    if (tamanho < 1)
    {
        return 1;
    }

    // Insere os itens ao estoque at� o tamanho criado
    for (i = 0; i < tamanho; i++)
    {
        printf("Digite o codigo para a %da mercadoria: ", i+1);     // C�digo
        scanf("%d", &estoque[i].codigo);

        printf("Digite a quantidade para a %da mercadoria: ", i+1); // Quantidade
        scanf("%d", &estoque[i].quantidade);
    }
    return 0;
}

// Analisa pedidos dos clientes
int pedido_cliente(Estoque estoque[], int tamanho)
{
    int item;           // Armazena o item para busca
    int up_quantidade;  // Armazena quantidade de estoque requisitada
    int posicao;        // Armazena posi��o do item na estrutura
    int verifica;       // Verifica se compra � poss�vel
    char op;            // Para op��o de continuidade

    // La�o de transa��es
    do
    {
        // Coleta o c�digo para busca
        printf("\n\nDigite o codigo do item para busca: ");
        scanf("%d", &item);

        // Chama a fun��o de busca e armazena em posi��o
        posicao = busca_item(estoque, item, tamanho);

        // Caso n�o encontre o item
        if (posicao == -1)
        {
            printf("\nMERCADORIA NAO CADASTRADA\n"); // Exibe mensagem e vai ao final do loop
        }
        // Caso sim, continua
        else
        {
            // Coleta quantidade para busca
            printf("Digite a quantidade do item requisitada: ");
            scanf("%d", &up_quantidade);

            // V� se � poss�vel a transa��o e armazena possibilidade em busca
            verifica = busca_quantidade(estoque, up_quantidade, posicao);

            // Caso n�o seja
            if (verifica == 1)
            {
                printf("\nESTOQUE INSUFICIENTE DA MERCADORIA\n"); // Exibe mensagem e vai ao final do loop
            }
            // Caso sim, atualiza o estoque
            else
            {
                estoque[posicao].quantidade -= up_quantidade;
            }
        }
        // Condi��o de parada
        printf("\nDeseja fazer outra transacao? [s/n] ");
        scanf(" %c", &op);
    } while (op == 's' || op == 'S');

    return 0;
}

// Lista o estoque atual
void listar_estoque(Estoque estoque[], int tamanho)
{
    int i; // Contador

    // Percorre o vetor da estrutura
    for (i = 0; i < tamanho; i++)
    {
        // Lista informa��es
        printf("\n%da Mercadoria:\n", i+1);
        printf("Codigo: %d\n", estoque[i].codigo);
        printf("Quantidade: %d\n", estoque[i].quantidade);
    }
}

// Fun��es auxiliares

// Busca se item existe no estoque
int busca_item(Estoque estoque[], int busca, int tamanho)
{
    int i; // Contador

    // Percorre o vetor da estrutura
    for (i = 0; i < tamanho; i++)
    {
        if (busca == estoque[i].codigo) // Caso encontre o codigo buscado
        {
            return i; // Retorna posi��o
        }
    }
    return -1; // Retorna valor negativo caso n�o encontre
}

// Busca se a quantidade � atend�vel no estoque
int busca_quantidade(Estoque estoque[], int busca, int posicao)
{
    // Caso a quantidade requisitada seja menor ou igual a existente
    if (busca <= estoque[posicao].quantidade)
    {
        return 0; // Retorna 0
    }
    return 1; // Retorna 1 caso n�o seja poss�vel
}
