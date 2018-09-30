/*
    Exerc�cio 3: Programa para zerar duas vari�veis inteiras

    FEITO POR: Rodrigo de Lima Martins
*/

#include<stdio.h>
#include<stdlib.h>

// Fun��o para zerar vari�veis
int zerar (int *a, int *b) // Passagem por refer�ncia
{
    *a = 0;
    *b = 0;
}

// Main
int main(void)
{
    int a, b;

    printf("--- Zerar variaveis ---\n");

    // Insere valores
    printf("Insira o primeiro valor inteiro: ");
    scanf("%d", &a);
    printf("Insira o segundo valor inteiro: ");
    scanf("%d", &b);

    // Zera os valores
    printf("\nValores inseridos: %d %d", a, b);                 // Imprime o digitado
    zerar(&a,&b);                                               // Chama a fun��o
    printf("\n\nValores apos serem zerados: %d %d\n", a, b);    // Imprime zerado

    return 0;
}
