/*
    Exerc�cio 4: Programa para ler valores de um vetor
    O vetor foi definido estaticamente para facilitar a programa��o.
    Aplica��es mais vers�teis poderiam usar a mesma l�gica.

    FEITO POR: Rodrigo de Lima Martins
*/

#include<stdio.h>
#define TAM 10

int vetor[TAM] = {1,2,3,4,5,6,7,8,9,10};

// Fun��o recursiva para imprimir os valores de um vetor
void print_vetor (int n)
{
    if (n < TAM) // Se ainda for verdadeira
    {
        printf("%d ", vetor[n]);    // Imprime a posi��o do vetor
        print_vetor(++n);           // Chama a fun��o com incremento
    }
}
// Fun��o main
int main (void)
{
    int n = 0;      // Come�a com o n�mero 0
    print_vetor(n); // Chama a fun��o recursiva

    return 0;
}
