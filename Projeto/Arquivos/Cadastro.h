#ifndef CADASTRO_H
#define CADASTRO_H

// Funções
int cadastroFC(void); // Menu de seçao cadastro
int cadConveniado(void); // Cadastrar conveniado
int cadFornecedor(void); // Cadastrar fornecedor
int lConveniado(void); // Lista conveniados
int lForncedor(void); // Lista fornecedores
int conConveniado(int key); // Consulta conveniado

// Estruturas
typedef struct cConveniado Conveniado; // Estrutura para conveniados com nome Conveniado
typedef struct cFornecedor Fornecedor; // Estrutura para fornecedores com nome Fornecedor

#endif // CADASTRO_H
