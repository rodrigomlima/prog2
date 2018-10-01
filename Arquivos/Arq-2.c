/*
    Exerc�cio 2: usa o arquivo de tabuleiro criado do Exerc�cio 1 e o l�,
    criando um jogo de Campo Minado. N�o h� implmenta��es para um jogo j�
    ganho

    FEITO POR: Rodrigo de Lima Martins
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int x, y;           // Coordenadas
    int pontos = 0;     // Marcador de pontos
    char pos;           // Armazena valor da coordenada
    FILE *campo_minado; // Arquivo do campo minado

    campo_minado = fopen("Tabuleiro.txt", "r"); // L� documento Tabuleiro.txt

    if (campo_minado == NULL) // Caso n�o consiga ler
    {
        printf("ERRO! Impossivel abrir o arquivo!");
        return 1; // Finaliza com 1
    }

    do // Roda o jogo em loop. Sai se acerta uma mina
    {
        printf("-------- CAMPO MINADO --------\n");
        if (pontos > 0) // Informa a �ltima posicao caso tenha acertado algum
        {
            printf("\nPosicao anterior: %d-%d\n", x, y);
        }

        // Pede a posi��o no campo
        printf("\nDigite uma posicao do campo minado: [linha e coluna entre 0 e 9]: ");
        scanf("%d %d", &x, &y);

        fseek(campo_minado, ((x*10)+y), SEEK_SET);  // Percorre no arquivo ate a posicao

        pos = fgetc(campo_minado);                  // Armazena a posi��o no char pos

        if (pos == '1')                             // Caso acerte uma mina
        {
            printf("\nMINA! O jogo acabou!\nVoce deu %d tiros certeiros\n\n", pontos);
        }
        else // Caso acerte o campo
        {
            pontos++;
            printf("\nCAMPO! Continue jogando!\nVoce deu %d tiros certeiros\n\n", pontos);
        }
        rewind(campo_minado); // Volta ao inicio do arquivo

        // Funcionam apenas em Windows:
        /*
        system("pause"); // Pausa a execu��o do programa
        system("cls"); // Limpa a tela
        */

    } while (pos != '1'); // Condi��o de sa�da

    fclose(campo_minado); // Fecha o documento

    return 0;
}

