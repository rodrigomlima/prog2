// Lista de funções para Estoque
#ifndef ESTOQUE_H
#define ESTOQUE_H

// Estruturas
typedef struct sEstoque Item; // Estrutura para estoque com o nome Item

// Funções
int estoqueMenu(void);   // Menu da seçao estoque
int iniEstoque(void);    // Inicializa o estoque
int lEstoque(void);      // Listar estoque
int conEstoque(int key); // Consultar estoque
int altEstoque(int pos); // Altera valores dos itens no estoque

// Funções Auxiliares
void menuConsultaEstoque(int key);                          // Menu para busca de estoque
void imprimeEstoque(Item *imprime);                         // Mostra os dados de estoque
int colCodProduto(int *codigo, int *quantia, float *valor); // Função para coletar dados de estoque. Usado no .c de Vendas

#endif // ESTOQUE_H
