/*
    FEITO POR: Rodrigo de Lima Martins
*/

#include<stdio.h>

// Fun��o recursiva para mostrar os n�meros da sequ�ncia de fibonacci
void fibonacci (int a, int b)
{
    if ((a + b) <= 89)      // 89 � o d�cimo n�mero da sequ�ncia (caso esta comece com 1)
    {
        printf("%d ", a+b); // Imprime o n�mero
        fibonacci(b, a+b);  // Chama a fun��o novamente
    }
}
// Fun��o main
int main(void)
{
    int a = 0, b = 1;   // Insere os dois primeiros n�meros da sequ�ncia

    fibonacci(a,b);     // Chama a fun��o

    return 0;
}
