// Lista de funções para Conveniados
#ifndef CONVENIADOS_H
#define CONVENIADOS_H

// Estruturas
typedef struct cConveniado Conveniado; // Estrutura para conveniados com nome Conveniado

// Funções principais
int conveniadoMenu(void);   // Menu de seçao conveniados
int cadConveniado(void);    // Cadastrar conveniado
int lConveniado(void);      // Lista conveniados
int conConveniado(int key); // Consulta conveniado
int altConveniado(int pos); // Altera conveniado
int excConveniado(int pos); // Exclui conveniado

// Funções Auxiliares
void menuConsultaConveniado(int key);           // Menu para busca de conveniado
void imprimeConveniado(Conveniado *imprime);    // Mostra os dados do conveniado
int colCadastro(int *codigo);                   // Função para coletar dados de cadastro. Usado no .c de Vendas

#endif // CADASTRO_H
