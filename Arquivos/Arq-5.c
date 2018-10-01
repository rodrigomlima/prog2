/*
    Exercício 5: Insere dados de 10 alunos num arquivo e depois
    disponibiliza uma busca de acordo com RA, mostrando, ainda
    o nome do melhor amigo do aluno.
    O programa permite apenas uma busca por execução

    FEITO POR: Rodrigo de Lima Martins
*/
#include<stdio.h>
#include<stdlib.h>

struct Aluno
{
    char Nome[40];
    char Ensino[30];
    int ID;
    int RA;
    int IDMelhorAmigo;
};

int main(void)
{

    int i;          // Contador
    int tam;        // Tamanho da Estrutura
    int pos;        // Posição no arquivo
    int buscaRA;    // Para buscar RA pedido
    char c;         // Lixo

    // Aloca dinamicamente a estrutura
    struct Aluno *alunos=malloc(sizeof(struct Aluno));

    // Declara tipo FILE
    FILE *lista_alunos;

    lista_alunos = fopen("lista-alunos.txt", "wb"); // Abre para escrita binária

    tam = sizeof(struct Aluno);                     // Lê tamanho da estrutura

    /*
        PARTE 1:
        Inserção de dados dos alunos no arquivo
        Devem ser feitas 10 inserções
    */
    for (i = 0; i < 10; i++)
    {
        // Inserção de dados dos alunos
        alunos->ID = i*tam;     // ID automático (valor i * tamanho da estrutura)
        printf("Digite o nome do aluno: ");
        fgets(alunos->Nome, 40, stdin);
        printf("Digite o ensino: ");
        fgets(alunos->Ensino, 30, stdin);
        printf("Digite seu RA: ");
        scanf("%d", &alunos->RA);
        printf("Digite a posicao do melhor amigo [0/9]: ");
        scanf("%d", &alunos->IDMelhorAmigo);
        alunos->IDMelhorAmigo = alunos->IDMelhorAmigo * tam;

        scanf("%c", &c); // Lixo

        // Escreve no arquivo
        fwrite(alunos, sizeof(struct Aluno), 1, lista_alunos);
        system("cls");
    }

    fclose(lista_alunos); // Fecha arquivo

    /*
        PARTE 2:
        Busca de dados do aluno a partir do RA e do nome do melhor amigo
        a partir do ID fornecido.
        O programa permite apenas uma busca por sessão
    */

    // Abre para leitura binária
    lista_alunos = fopen("lista-alunos.txt", "rb");

    // Lê o RA requerido para busca
    printf("Digite o RA do aluno desejado: ");
    scanf("%d", &buscaRA);

    // Roda o arquivo procurando o RA correspondente
    for (pos = 0; pos < 10; pos++)
    {
        fseek(lista_alunos, tam*pos, SEEK_SET);                 // Posiciona o cursor na posição n
        fread(alunos, sizeof(struct Aluno), 1, lista_alunos);   // Lê a estrutura correspondente

        // Imprime informações se verdadeiro
        if (buscaRA == alunos->RA)
        {
             printf("\n Aluno: %s\n Ensino: %s\n RA: %d", alunos->Nome, alunos->Ensino, alunos->RA);
             break;
        }
    }

    // Caso não encontre, manda mensagem e encerra o programa
    if (pos >= 10)
    {
        printf("A busca nao obteve resultados!");
        return 1;
    }

    // Armazena o ID (posição no aruqivo) do melhor amigo
    pos = alunos->IDMelhorAmigo;
    fseek(lista_alunos, pos, SEEK_SET);                     // Leva o cursor para esta posição

    fread(alunos, sizeof(struct Aluno), 1, lista_alunos);   // Lê a estrutura correspondente

    printf("\n Nome do melhor amigo: %s", alunos->Nome);    // Imprime o nome do melhor amigo

    fclose(lista_alunos);                                   // Fecha o arquivo

    return 0;
}
