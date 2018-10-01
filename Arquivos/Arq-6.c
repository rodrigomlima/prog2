/*
    Exercício 6: Recebe 2 arquivos do usuário e cria um terceiro
    a partir das informações dos dois primeiros

    FEITO POR: Rodrigo de Lima Martins
*/
#include<stdio.h>
#include<stdlib.h>

int main(void) {

    char c;             // Impressão dos dados do arquivo
    char frase[100];    // Para armazenar no arquivo

    // Cria 3 arquivos
    FILE *arq1, *arq2, *arq3;

    arq1 = fopen("arquivo1.txt", "w"); // Escrita
    arq2 = fopen("arquivo2.txt", "w"); // Escrita

    // Armazena a frase no arq1
    printf("Digite qualquer coisa: ");
    gets(frase);
    fputs(frase, arq1);

    // Armazena a frase no arq 2
    printf("Digite qualquer outra coisa: ");
    gets(frase);
    fputs(frase, arq2);

    // Fecha os arquivos
    fclose(arq1);
    fclose(arq2);

    arq1 = fopen("arquivo1.txt", "r"); // Leitura
    arq2 = fopen("arquivo2.txt", "r"); // Leitura
    arq3 = fopen("arquivo3.txt", "w"); // Escrita

    // Armazena conteúdo de arq1 em arq3
    while (!feof(arq1))
    {
        fscanf(arq1, "%c", &c);
        fprintf(arq3, "%c", c);
    }
    // Armazena conteúdo de arq2 em ar13
    while (!feof(arq2))
    {
        fscanf(arq2, "%c", &c);
        fprintf(arq3, "%c", c);
    }

    fclose(arq3);                       // Fecha arq3
    arq3 = fopen("arquivo3.txt", "r");  // Leitura

    printf("Arquivos copiados com sucesso!\n\n");

    printf("\nArquivo novo: ");

    // Imprime arq3
    while (!feof(arq3))
    {
        fscanf(arq3, "%c", &c);
        printf("%c", c);
    }

    // Fecha tudo
    fclose(arq1);
    fclose(arq2);
    fclose(arq3);

    return 0;
}

