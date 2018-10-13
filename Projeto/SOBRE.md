# Sobre o Projeto - Funerária Caronte

Nesta pasta, encontram-se os arquivos de um projeto de gerenciamento de uma funerária, com funções para Estoque, Vendas, manipulação de Conveniados e de Fornecedores. Para facilitar a manutenção deste código, este usou de diversos arquivos para sua implementação.

Este projeto foi originalmente concebido como trabalho da disciplina SI 200, ministrada na Faculdade de Tecnologia da Unicamp, no segundo semestre do ano de 2017.

## 1. Conteúdo do projeto

Este projeto contem, na pasta Arquivos:

* __Main.c:__ Arquivo principal do projeto. Corresponde ao menu principal;
* __Conveniados.c e Conveniados.h:__ Arquivos contendo as funções referentes a manipulação de Conveniados;
* __Estoque.c e Estoque.h:__ Arquivos contendo as funções referentes a manipulação de Estoque;
* __Fornecedores.c e Fornecedores.h:__ Arquivos contendo as funções referentes a manipulação de Fornecedores;
* __Vendas.c e Vendas.h:__ Arquivos contendo as funções referentes a manipulação de Vendas;

Sendo que nos arquivos _.c_ estão as implementações das funções e nos arquivos _.h_ os protótipos das funções do arquivo _.c_ correspondente. _Main.c_ possui apenas a função _int main(void)_, que funciona de menu principal.

## 2. Conceitos utilizados

Este projeto utilizou dos seguintes conceitos da linguagem C:

* Modularização;
* Ponteiros;
* Manipulação de arquivos;
* Alocação Dinâmica;
* Bibliotecas, sendo elas:
    * _stdio.h_;
    * _stdlib.h_;
    * _string.h_;
    * Bibliotecas de criação própria.
* Programação multiarquivos.

## 3. Como compilar o programa

Como o programa contém mais de um arquivo, é necessário incluir os arquivos durante a compilação. Neste item, indicaremos como fazer isso de uma forma simples, não sendo estas as únicas possíveis.

### 3.1. Em Windows

Simplesmente adicione os arquivos num novo projeto da IDE utilizada. O projeto será compilado como um só programa.

### 3.2. Em Linux

Acesse a pasta com os arquivos dos códigos via terminal. Como há um arquivo _makefile_ entre os arquivos na pasta do projeto, basta-se:

1. Usar o comando _make_ para construir o projeto. Este será construído com o nome _Main_;
2. Usar o comando _./Main_ para rodar o programa.

## 4. Possíveis problemas do projeto

O projeto pode apresentar alguns problemas durante a execução:

1. __Erros de execução:__ O código foi escrito ano passado e não foi revisado minuciosamente, ou algumas das modificações feitas recentemente podem ter prejudicado seu funcionamento normal;
2. __Erros de lógica:__ Algumas funções podem não se comportar como deveriam, principalmente na parte de _Vendas_;
3. __Arquivos corrompidos:__ Alguns arquivos podem ser corrompidos caso a função seja encerrada abruptamente.

Estes erros devem ser resolvidos em novas versões futuramente.

## 5. Atualizações pretendidas

O projeto pretende ainda contar com:

1. Alteração parcial dos registros;
2. Função de exclusão para estoque;
3. Melhor modularização dos cadastros;
4. Modularização de outros menus criados na tela;
5. Inserção de mensagens de erro mais educativas;
6. Melhoria do uso da função de alteração de estoque;
7. Simplificação de coleta de lixo no programa;
8. Fechamento de arquivo e liberação de memória em condições de saída prococe que ainda não tem esta implementação;
9. Simplificação da realização de vendas com cadastros novos;
10. Maior versatilidade em algumas funções, para permitir um melhor reúso do código;
11. Possíveis comentários desformatados.

## 6. Notas sobre versões:

Sendo que o primeiro número é de versão de revisão e o segundo de correção de erros menores.

* __Versão 1.0:__ Upload do arquivo do projeto no Github;
* __Versão 1.1:__ Correção de erro de compilação encontrado em _Conveniados.c_.
