/*
    Pograma para somar um n�mero de 1 at� n, com n
    digitado pelo usu�rio

    FEITO POR: Rodrigo de Lima Martins
*/

#include <stdio.h>
#include <stdlib.h>

// Fun��o recursiva para somar n�meros de 1 at� N (digitado pelo usu�rio)
int somaN(int n)
{
    int r;                  // Armazena o resultado
    if (n == 0)             // Se for 0, retorna 0
        return 0;
    else
    {
        r = n + somaN(n-1); // Igualmente como fatorial, mas como soma
        return r;           // Retorna o valor do resultado
    }
}
// Fun��o main
int main (void)
{
    int numero; // Para inser��o do n�mero

    // Digita um n�mero qualquer
    printf("Digite um numero: ");
    scanf("%d", &numero);

    // Chama a soma de 1 at� o N
    printf("A soma de 1 ate %d e: %d", numero, somaN(numero));

    return 0;
}
