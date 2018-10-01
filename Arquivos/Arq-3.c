/*
    Exercício 3: Insere dados sobre filmes que passam num cinema em um arquivo
    e permite a visualização de 2 relatórios:
    1. Filmes que passam numa sala
    2. Salas que passam um filme

    FEITO POR: Rodrigo de Lima Martins
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Filme {
    char nome[100];
    char sala[30];
    int duracao;
    };

int main(void) {

    // Declaração de variáveis
    char key;               // Para sair do loop / lixo
    char busca_Sala[30];    // Vetor para buscar sala do filme
    char busca_Filme[100];  // Vetor para buscar o nome do filme
    int con = 1;            // Apura casos de repetição da função;
    int num = 0;            // Número de vezes que o loop roda
    int tam;                // Armazena o tamanho da struct
    int pos = 0;            // posição na estrutura
    int option;             // opção do menu
    int comp;               // compara valores

    // Cria estrutura e arquivo
    struct Filme *filmes=malloc(sizeof(struct Filme));
    FILE *log_sessao;

    // Abre pra escrita binária
    log_sessao = fopen("Sessoes.txt", "wb");
    tam = sizeof(struct Filme); // Guarda o tamanho do grupo

    /*
        PARTE 1: INSERÇÃO DE DADOS NO ARQUIVO
    */
    do {
        // Caso para repetições: armazena o lixo
        if (con == 0)
        {
            scanf("%c", &key);
        }

        // Informações do filme
        //nome
        printf("Digite o nome do filme desejado: ");
        fgets(filmes->nome, 100, stdin);
        // sala (char)
        printf("Digite o a sala do filme: ");
        fgets(filmes->sala, 30, stdin);
        // duração
        printf("Digite a duracao do filme (em minutos): ");
        scanf("%d", &filmes->duracao);

        scanf("%c", &key); // Lixo

        // Para saber se quer se repetir o loop
        printf("Voce deseja inserir mais um filme? [S/N] ");
        scanf("%c", &key);
        con = 0; // Caso o loop repita

        // Grava no arquivo a estrutura com seu tamanho completo
        fwrite(filmes, sizeof(struct Filme), 1, log_sessao);
        num++; // Conta +1 no numero de filmes

        // Apenas em Windows
        //system("cls");

    } while(key != 'n');

    // Fecha o arquivo
    fclose(log_sessao);

    // Abre para leitura binária
    log_sessao = fopen("Sessoes.txt", "rb");

    /*
        PARTE 1: BUSCA DE INFORMAÇÕES NO ARQUIVO
    */
    do {
        // Menu de opções
        printf("Qual tipo de busca deseja fazer?\n");
        printf("\n 1. Filmes correspondentes a sala");
        printf("\n 2. Salas correspondetes ao filme");
        printf("\n 9. Sair\n ");
        scanf("%d", &option); // Coleta a opção correspndente

        switch (option) {

        // FIlmes correspondentes a sala
        case 1:
        {
            scanf("%c", &key); // Lixo
            printf("Digite a sala desajada: ");
            fgets(busca_Sala, 30, stdin); // Lê e armazena sala para busca

            // Até o número de posições de filme
            for (pos = 0; pos < num; pos++) {

                // Posiciona o cursor no início da estrutura de posição n e o lê
                fseek(log_sessao, tam*pos, SEEK_SET);
                fread(filmes, sizeof(struct Filme), 1, log_sessao);

                comp = strcmp(busca_Sala, filmes->sala); // Compara os valores

                if (comp == 0) // Imprime se verdadeiro
                {
                    printf("Filme encontrado: %s\n", filmes->nome);
                }
            }
            break;
        }

        // Salas correspondentes a filmes
        case 2:
        {
            scanf("%c", &key); // Lixo
            printf("Digite o filme desejado: ");
            fgets(busca_Filme, 100, stdin); // Lê e armazena filme para busca

            // Até o número de posições de filme
            for (pos = 0; pos < num; pos++) {

                // Posiciona o cursor no início da estrutura de posição n e o lê
                fseek(log_sessao, tam*pos, SEEK_SET);
                fread(filmes, sizeof(struct Filme), 1, log_sessao);

                comp = strcmp(busca_Filme, filmes->nome); // Compara os valores

                if (comp == 0) {
                    printf("Filme passara na sala: %s\n", filmes->sala); // Imprime se verdadeiro
                }
            }
            break;
        }
        case 9:
            return 0;   // Sai do programa
            break;
        default:        // Opção inválida
            printf("Opcao invalida! Digite novamente: ");
        }

        // Condição para repetição
        printf("Voce deseja fazer outra busca? [S/N] ");
        scanf("%c", &key);

        // Coloca o cursor no começo novamente
        rewind(log_sessao);

        // Apenas em Windows
        //system("cls");
    } while(key != 'n');

    fclose(log_sessao); // Fecha o arquivo

    return 0;
}
