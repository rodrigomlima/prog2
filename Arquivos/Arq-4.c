/*
    Exercício 4: Insere dados de 10 alunos num arquivo e depois
    disponibiliza uma busca de acordo com posição.
    O programa permite apenas uma busca por execução

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
    // Declaração de variáveis
    int i;              // Contador
    int tam;            // Tamanho da estrutura
    int pos;            // Posição no arquivo
    char c;             // Lixo

    FILE *lista_alunos; // Arquivo para lista de alunos

    // Aloca a estrutura dinamicamente
    struct Aluno *alunos=malloc(sizeof(struct Aluno));

    lista_alunos = fopen("lista-alunos.txt", "wb"); // Escrita binária

    /*
        PARTE 1:
        Inserção de dados dos alunos no arquivo
        Devem ser feitas 10 inserções
    */
    for (i = 0; i < 10; i++)
    {
        // Inserção de dados dos alunos
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
        Busca do aluno na posição desejada. O programa permite apenas uma única
        busca por sessão.
    */
    tam = sizeof(struct Aluno);                             // Lê tamanho da estrutura

    lista_alunos = fopen("lista-alunos.txt", "rb");         // Abre o aruqivo em leitura binária

    printf("Digite a posicao do aluno desejado: ");         // Diz a posição que se quer
    scanf("%d", &pos);
    pos--;                                                  // Diminui em 1 a posição (posição 1 é 0)

    fseek(lista_alunos, tam*pos, SEEK_SET);                 // Coloca o cursor na posição pedida

    fread(alunos, sizeof(struct Aluno), 1, lista_alunos);   // Lê a estrutura que está na posição

    // Imprime os valores da estrutura
    printf("\n Aluno: %s\n Ensino: %s\n RA: %d", alunos->Nome, alunos->Ensino, alunos->RA);

    fclose(lista_alunos); // Fecha o arquivo

    return 0;
}
