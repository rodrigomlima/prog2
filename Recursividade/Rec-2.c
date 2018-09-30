/*
    Exercício 2: Mostra números de 1 a 50
    FEITO POR: Rodrigo de Lima Martins
*/

#include<stdio.h>

// Função recursiva para imprimir os primeiros 50 numeros
void printN (int n)
{
    if (n <= 50) // Se ainda for verdadeira
    {
        printf("%d\n", n);  // Imprime o numero recebido
        printN(++n);        // Chama a função com incremento
    }
}
// Função main
int main (void)
{
    int n = 1;  // Começa com o número 1
    printN(n);  // Chama a função recursiva

    return 0;
}
