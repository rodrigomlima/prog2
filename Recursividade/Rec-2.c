/*
    FEITO POR: Rodrigo de Lima Martins
*/

#include<stdio.h>

// Fun��o recursiva para imprimir os primeiros 50 numeros
void printN (int n)
{
    if (n <= 50) // Se ainda for verdadeira
    {
        printf("%d\n", n);  // Imprime o numero recebido
        printN(++n);        // Chama a fun��o com incremento
    }
}
// Fun��o main
int main (void)
{
    int n = 1;  // Come�a com o n�mero 1
    printN(n);  // Chama a fun��o recursiva

    return 0;
}
