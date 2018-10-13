// Lista de funções para Vendas
#ifndef VENDAS_H
#define VENDAS_H

// Estruturas
typedef struct Transacao Venda; // Estrutura para venda com nome Venda

// Funções principais
int vendasMenu(void);   // Menu da seçao Vendas
int efeVenda(void);     // Efetuar uma venda
int conVenda(void);     // Consultar vendas feitas

// Funções auxiliares
void imprimeVenda(Venda *imprime);  // Mostra os dados da venda
int lVenda(void);                   // Lista todas as vendas

#endif // VENDAS_H


