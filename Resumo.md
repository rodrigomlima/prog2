# RESUMO PARA A PROVA

## Manipulação de arquivos

É necessária a biblioteca stdio.h para usar arquivos:
```C
#include<stdio.h>
```

### Declaração de um arquivo

Para criar um tipo arquivo, são necessários os seguintes comandos:
```C
FILE * arquivo; // Declarar como ponteiro
arquivo = fopen(arquivo, "modo_de_escrita"); // Função para abertura
```

Em *arquivo*, pode-se passar tanto o nome literalmente (ex.: _"arquivo.txt"_) quanto pelo nome de uma variável string.

A função *fopen* também é a responsável por criar arquivos se estes ainda não existirem

### Verificação de erros

Para verificar um erro de arquivo, basta ver se a função *fopen* retornou NULL, tratando o erro da forma desejada:

```C
if (arquivo == NULL) // Erro ao abrir o arquivo
```

### Modos de abertura

Um arquivo pode ser aberto das seguintes formas:

* __"w": Escrita:__ Coloca o cursor no começo do arquivo. Cria um arquivo novo se não existir o apontado;
* __"r": Leitura:__ Coloca o cursor no começo do arquivo. Se não existir o arquivo, ele dá erro;
* __"a": Anexo:__ Coloca o cursor no final do arquivo. Cria um arquivo novo se não existir o apontado. Permite leitura e escrita, mas não permite o reposicionamento do cursor.

Pode-se também utilizar, em conjunto dos modos acima, os seguintes indicadores:

#### " +" atualização:
Permite atualização em arquivos. Tem diferenças para cada forma de abertura:

* __Leitura (_"r+"_):__ O arquivo precisa exisitir.⋅⋅
* __Escrita (_"w+"_):__ Se existir o arquivo, descarta o arquivo anterior e o arquivo é tratado como um arquivo novo em branco⋅⋅
* __Anexo (_"a+"_):__ Cria uma arquivo se não existir, com reposições de cursor servindo apenas para leitura (escreve necessariamente apenas ao final do arquivo)⋅⋅

#### " b" modo binário:

Faz leitura, escrita e anexos de forma binária, sem formatação textual.

__Observação:__ ENTER e RETURN também são caracteres e são salvos com seus espaços reservados no arquivo.

### Funções de Manipulação de Arquivos

São algumas das funções de manipulação:

#### fopen:
Abre um arquivo. Os dados inseridos ainda ficam na memória, não no arquivo. Sintaxe:

```C
fopen(nome_do_arquivo, "modo_de_escrita");
```

#### fclose:
Fecha o arquivo, salvando os dados alterados. Sintaxe:

```C
fopen(nome_do_arquivo);
```

__Observação:__ para alternar entre modos de leitura, sempre abrir e fechar o arquivo com o modo desejado cada vez.

#### fprintf:
Escreve (_imprime_) num arquivo. Sintaxe:

```C
fprintf(nome_do_arquivo, "Dados a inserir (pode-se por uma variável com %tipo)", variável);
```

Sendo que _variável_ é opcional.

#### fscanf:
Lê de um arquivo. Sintaxe:

```C
fscanf(nome_do_arquivo, "%tipo", variável);
```

#### fwrite:
Escreve no arquivo. Possui mais especificações que _fprintf_ e _fscanf_, permitindo a inserção de tipos complexos, como estruturas e vetores. Sintaxe:

```C
fwrite(variável, tamanho_bytes, número_de_elementos, nome_do_arquivo);
```

#### fread:
Equivaliente ao _fwrite_, mas para ler em arquivos. Sintaxe:

fread(tipo de dado, tamanho(bytes), número de elementos, arquivo);

```C
fread(variável, tamanho_bytes, número_de_elementos, nome_do_arquivo);
```

#### fgets:
Lê de um _local de leitura_ uma linha inteira, independente dos espaços. Sintaxe:

```C
fgets(variável_string, tamanho, local_de_leitura);
```

Por _local de leitura_ entende-se:

* Arquivo;
* _stdin_, que é a entrada de dados pelo usuário

#### fseek:
Posiciona o cursor no arquivo. Sintaxe:

```C
fseek(nome_do_arquivo, tamanho, posição);
```
* Por _tamanho_, deve-se dizer o quanto, em bytes o cursor irá se mover. Esta valor pode ser positivo (para frente) ou negativo (para trás).
* Por _posição_, deve-se dizer a posição de referência para mover o cursor, que pode ser:
    * SEEK_SET: Começo do arquivo;
    * SEEK_CUR: Posição atual do cursor;
    * SEEK_END: Final do arquivo.
    
#### rename:
Renomeia um arquivo. Pode-se passar uma string por variável ou de forma literal. Sintaxe:

```C
rename(nome_antigo, nome_novo);
```

#### remove:
Remove um arquivo. Deve-se passar o nome do arquivo em string ou de forma literal. Sintaxe:

```C
remove(nome_arquivo);
```

## Modularização

Por modularização entenda: criar funções específicas que podem ser chamadas em tempo de execução.

A sintaxe para tal é a seguinte:

```C
tipo_retorno nome_funcao(tipo_retorno parâmetros)
{
    return alguma_coisa; // O retorno deve ser do mesmo tipo do tipo_retorno
}
```
__Observe que:__

* *parâmetros:* Variáveis necessárias para execução da função. São opcionais e pode se ter mais de um;
* *tipo_retorno:* pode ser qualquer tipo definido: int, float, char, FILE, void, etc.
    * O tipo _void_ aponta para vazio. Caso usado numa função, esta não deve ter valores de _return_.

### Passagem de parâmetros
Este tipo de passagem permite apenas a leitura das variáveis passadas, pois cria uma cópia das variáveis. Exemplo:

```C
int incremento (int a)  // Passagem por parâmetro
{
    return ++a;         // Retorno
}

int main(void)
{
    int a = 1;
    int b = incremento(a);  // Chamada da função
    printf("%d %d", a, b);  // Será impresso "1 2". A variável a não é alterada

    return 0;
}
```

Um exemplo clássico de passagem de parâmetros é a função _printf_.

### Passagem de referência
Este tipo de passagem permite permite manipulação de variáveis passadas, pois passa o endereço das variáveis. Note o uso do operador de ponteiros (*) e do operador de endereço (&) Exemplo:

```C
int incremento (int *a) // Passagem por referência
{
    return *++a;
}

int main(void)
{
    int a = 1;
    int b = incremento(&a); // Chamada da função
    printf("%d %d", a, b);  // Será impresso "2 2". A variável a é alterada

    return 0;
}
```

Um exemplo clássico de passagem de parâmetros é a função _scanf_.

#### Observações:

* Não é necessário passar vetores inteiros com operadores de endereço e nem especificar na função a passagem de referência, pois, por padrão, vetores já são do tipo ponteiro;
    * Itens de um vetor, no entanto, precisam dos operadores.
* Uma variável que já seja ponteiro pode ser passada sem os operadores.

## Alocação Dinâmica

Permite que se manipule a memória reservada pelo programa, alocando e desalocando quando necessário. Para se alocar memória, utiliza-se a função _malloc_. Sintaxe:

```C
tipo_retorno * variável;     // declaração da variável
variável = malloc (tamanho); // alocação do seu espaço
```

Um comando muito utlizado conjuntamento do _malloc_ é o _sizeof_, que retorna o tamanho, em bytes, de uma variável. É bem útil quando se manipula estruturas e vetores. Sintaxe:

```C
sizeof(tipo_retorno);
```

Para liberar o espaço alocado da memória, utiliza-se o comando _free_. Sintaxe:

```C
free(variável);
```
