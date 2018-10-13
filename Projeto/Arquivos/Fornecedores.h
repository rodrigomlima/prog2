// Lista de funções para Fornecedores
#ifndef FORNECEDORES_H
#define FORNECEDORES_H

// Estruturas
typedef struct cFornecedor Fornecedor; // Estrutura para fornecedores com nome Fornecedor

// Funções Principais
int fornecedorMenu(void);   // Menu da seção de fornecedor
int cadFornecedor(void);    // Cadastrar fornecedor
int lForncedor(void);       // Lista fornecedores
int conFornecedor(int key); // Consulta fornecedor
int altFornecedor(int pos); // Altera fornecedor
int excFornecedor(int pos); // Exclui fornecedor

// Fumções Auxiliares
void menuConsultaFornecedor(int key);           // Menu para busca de fornecedor
void imprimeFornecedor(Fornecedor *imprime);    // Mostra os dados do fornecedor

#endif // FORNECEDORES_H
