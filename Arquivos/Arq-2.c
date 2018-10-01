/*
    Exercício 2: usa o arquivo de tabuleiro criado do Exercício 1 e o lê,
    criando um jogo de Campo Minado. Não há implmentações para um jogo já
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

    campo_minado = fopen("Tabuleiro.txt", "r"); // Lê documento Tabuleiro.txt

    if (campo_minado == NULL) // Caso não consiga ler
    {
        printf("ERRO! Impossivel abrir o arquivo!");
        return 1; // Finaliza com 1
    }

    do // Roda o jogo em loop. Sai se acerta uma mina
    {
        printf("-------- CAMPO MINADO --------\n");
        if (pontos > 0) // Informa a última posicao caso tenha acertado algum
        {
            printf("\nPosicao anterior: %d-%d\n", x, y);
        }

        // Pede a posição no campo
        printf("\nDigite uma posicao do campo minado: [linha e coluna entre 0 e 9]: ");
        scanf("%d %d", &x, &y);

        fseek(campo_minado, ((x*10)+y), SEEK_SET);  // Percorre no arquivo ate a posicao

        pos = fgetc(campo_minado);                  // Armazena a posição no char pos

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
        system("pause"); // Pausa a execução do programa
        system("cls"); // Limpa a tela
        */

    } while (pos != '1'); // Condição de saída

    fclose(campo_minado); // Fecha o documento

    return 0;
}

