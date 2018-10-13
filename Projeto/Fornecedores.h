// Lista de fun��es para Fornecedores
#ifndef FORNECEDORES_H
#define FORNECEDORES_H

// Estruturas
typedef struct cFornecedor Fornecedor; // Estrutura para fornecedores com nome Fornecedor

// Fun��es Principais
int fornecedorMenu(void);   // Menu da se��o de fornecedor
int cadFornecedor(void);    // Cadastrar fornecedor
int lForncedor(void);       // Lista fornecedores
int conFornecedor(int key); // Consulta fornecedor
int altFornecedor(int pos); // Altera fornecedor
int excFornecedor(int pos); // Exclui fornecedor

// Fum��es Auxiliares
void menuConsultaFornecedor(int key);           // Menu para busca de fornecedor
void imprimeFornecedor(Fornecedor *imprime);    // Mostra os dados do fornecedor

#endif // FORNECEDORES_H
