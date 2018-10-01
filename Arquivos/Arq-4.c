/*
    Exerc�cio 4: Insere dados de 10 alunos num arquivo e depois
    disponibiliza uma busca de acordo com posi��o.
    O programa permite apenas uma busca por execu��o

    FEITO POR: Rodrigo de Lima Martins
*/

#include<stdio.h>
#include<stdlib.h>

struct Aluno
{
    char Nome[40];
    char Ensino[30];
    int RA;
};

int main(void)
{
    // Declara��o de vari�veis
    int i;              // Contador
    int tam;            // Tamanho da estrutura
    int pos;            // Posi��o no arquivo
    char c;             // Lixo

    FILE *lista_alunos; // Arquivo para lista de alunos

    // Aloca a estrutura dinamicamente
    struct Aluno *alunos=malloc(sizeof(struct Aluno));

    lista_alunos = fopen("lista-alunos.txt", "wb"); // Escrita bin�ria

    /*
        PARTE 1:
        Inser��o de dados dos alunos no arquivo
        Devem ser feitas 10 inser��es
    */
    for (i = 0; i < 10; i++)
    {
        // Inser��o de dados dos alunos
        printf("Digite o nome do aluno: ");
        fgets(alunos->Nome, 40, stdin);
        printf("Digite o ensino: ");
        fgets(alunos->Ensino, 30, stdin);
        printf("Digite seu RA: ");
        scanf("%d", &alunos->RA);

        scanf("%c", &c); // Lixo

        // Escreve no arquivo
        fwrite(alunos, sizeof(struct Aluno), 1, lista_alunos);
    }

    fclose(lista_alunos); // Fecha arquivo

    /*
        PARTE 2:
        Busca do aluno na posi��o desejada. O programa permite apenas uma �nica
        busca por sess�o.
    */
    tam = sizeof(struct Aluno);                             // L� tamanho da estrutura

    lista_alunos = fopen("lista-alunos.txt", "rb");         // Abre o aruqivo em leitura bin�ria

    printf("Digite a posicao do aluno desejado: ");         // Diz a posi��o que se quer
    scanf("%d", &pos);
    pos--;                                                  // Diminui em 1 a posi��o (posi��o 1 � 0)

    fseek(lista_alunos, tam*pos, SEEK_SET);                 // Coloca o cursor na posi��o pedida

    fread(alunos, sizeof(struct Aluno), 1, lista_alunos);   // L� a estrutura que est� na posi��o

    // Imprime os valores da estrutura
    printf("\n Aluno: %s\n Ensino: %s\n RA: %d", alunos->Nome, alunos->Ensino, alunos->RA);

    fclose(lista_alunos); // Fecha o arquivo

    return 0;
}
