/*
    FEITO POR: Rodrigo de Lima Martins
*/

#include<stdio.h>
#include<stdlib.h>

// Fun��o para fatorial
int fatorial (int n)
{
    int resultado = n;  // Recebe o valor digitado do usu�rio e coloca em resultado
    int i;              // Contador

    for (i = n-1; i > 0; i--)   // Loop decrementa do valor digitado do usu�rio
    {
        resultado *= i;         // Multiplica com o exitente em resultado
    }

    return resultado;           // Retorna o resultado
}

// Fun��o para pot�ncia. Funciona apenas para expoentes inteiros
float potencia (float base, int exp)
{
    float resultado = base; // Recebe o valor digitado do usu�rio para base e coloca em resultado
    int i;                  // Contador

    for (i = exp-1; i > 0; i--) // Loop decrementa do valor do expoente digitado do usu�rio
    {
        resultado *= base;      // Multiplica com o exitente em resultado
    }

    return resultado;           // Retorna o resultado
}

// Fun��o para calulcar probabilidade de se ter olhos azuis
float olhos_azuis (int n, int k)
{
    float resultado; // Armazena o resultado

    // Condi��o de erro na fun��o
    if (n < k)
    {
        return -1;  // Retorna -1
    }

    // Calcula o resultado
    resultado = (fatorial(n) / (fatorial(k) * fatorial(n-k))) * potencia(0.25,k) * potencia(0.75, n-k);

    return resultado;   // Retorna o resultado
}

// Fun��o main
int main (void)
{
    int n, k;   // Vari�veis digitadas pelo usu�rio
    float p;    // Vari�vel para o resultado

    printf("--- Calcular probabilidades: olhos azuis ---\n");

    // Inser��o dos valor n e k
    printf("\nDigite o numero de criancas n: ");
    scanf("%d", &n);
    printf("\nDigite o numero de criancas com olhos azuis k: ");
    scanf("%d", &k);

    // Calcula a probabilidade
    p = olhos_azuis(n,k);

    // Caso receba valores errados, envia mensagem e encerra o programa
    if (p == -1)
    {
        printf("\nERRO: O numero de criancas n deve ser maior ou igual ao numero k!!");
        return 0;
    }
    // Caso receba valores v�lidos, exibe a probabilidade
    else
    {
        printf("\nA probabilidade e de P = %.2f", p);
    }

    return 0;
}
