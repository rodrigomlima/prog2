# Arquivo Makefile para compilar o programa de gerenciamento da funerária
#
# Compilador padrao
CC=gcc
#
# Arquivos fonte
FONTES=caronte.c Conveniados.c Estoque.c Fornecedores.c Vendas.c
OBJETOS=$(FONTES:.c=.o)
EXECUTAVEL=Main

#Dependencias de Compilacao
all: $(EXECUTAVEL)

Main: Conveniados.o Estoque.o Fornecedores.o Vendas.o
	$(CC) -o Main Main.c Conveniados.o Estoque.o Fornecedores.o Vendas.o

Conveniados.o: Conveniados.c Conveniados.h
	$(CC) -c Conveniados.c

Estoque.o: Estoque.c Estoque.h
	$(CC) -c Estoque.c

Fornecedores.o: Fornecedores.c Fornecedores.h
	$(CC) -c Fornecedores.c

Vendas.o: Vendas.c Vendas.h
	$(CC) -c Vendas.c

#Limpeza
clean:
	rm -f $(OBJETOS) $(EXECUTAVEL)