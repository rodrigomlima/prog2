/*
    Exercício 1: Cria um tabuleiro de campo minado

    FEITO POR: Rodrigo de Lima Martins
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para montar um tabuleiro
int linha_campo (char tabuleiro[10][10])
{
    int i, j, cont = 0, mina, fracao;
    char list[] = {"1000000000"};
    /* list, mina e fracao são para controlar a probabilidade de terem
    minas em cada tabuleiro. A chance de ter menos de 0 minas é muito baixa */
    srand( (unsigned)time(NULL) ); // Garante que o numero de rand seja aleatório

    for (j = 0; j < 10; j++) // Colunas (int j)
    {
        for (i = 0; i < 10; i++) // Linhas (int i)
        {
            if (cont < 10) // Se ainda puder adicionar minas (cont conta as minas - Máximo 10)
            {
                fracao = 3 + (rand() % 7);      // fracao define a probabilidade de ser mina (entre 1/3 a 1/10)
                mina = rand() % fracao;         // Mina seleciona um número do vetor de acordo com o valor de fracao
                tabuleiro[i][j] = list[mina];   // Coloca 0 ou 1 na matriz

                if (tabuleiro[i][j] == '1')     // Caso coloque uma mina
                {
                    cont++;                     // Conta mais uma mina
                }
            }
            else
            {
                tabuleiro[i][j] = '0'; // Coloca 0 se não puder colocar mais minas
            }
        }
    }
    return 0;
}

// Função main
int main(void) {

    char campo[10][10], x, y;   // Matriz e contadores
    FILE *campo_minado;         // Arquivo do campo minado

    campo_minado = fopen("Tabuleiro.txt", "w"); // Cria documento Tabuleiro.txt em modo escrita

    // Caso não consiga criar/abrir o arquivo
    if (campo_minado == NULL)
    {
        printf("ERRO! Impossivel abrir o arquivo!");
        return 1; // Finaliza com 1
    }
    // Caso consiga criar/abrir o arquivo
    else
    {
        linha_campo(campo); // Chama função
        printf("Campo minado gerado:\n\n");
        for (y = 0; y < 10; y++) // Coluna
        {
            for (x = 0; x < 10; x++) // Linha
            {
                printf("%c ", campo[x][y]);                 // Printa campo
                fprintf(campo_minado, "%c", campo[x][y]);   // Escreve no documento
            }
            printf("\n"); // Pula linha
        }
    }
    fclose(campo_minado); // Fecha o documento. Salva

    return 0;
    }
