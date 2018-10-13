// Lista de fun��es para Vendas
#ifndef VENDAS_H
#define VENDAS_H

// Estruturas
typedef struct Transacao Venda; // Estrutura para venda com nome Venda

// Fun��es principais
int vendasMenu(void);   // Menu da se�ao Vendas
int efeVenda(void);     // Efetuar uma venda
int conVenda(void);     // Consultar vendas feitas

// Fun��es auxiliares
void imprimeVenda(Venda *imprime);  // Mostra os dados da venda
int lVenda(void);                   // Lista todas as vendas

#endif // VENDAS_H


