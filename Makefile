#Makefile for "Laboratorio 06" C++ aplication
#Created by Eduardo Rique

# Comandos do sistema operacional
# Linux: rm -rf
# Windows: cmd //C del
RM = rm -rf

# Compilador
CC = g++

# Variaveis para os subdiretorios
BIN_DIR = ./bin
OBJ_DIR = ./build
DOC_DIR = ./doc
INC_DIR = ./include
SRC_DIR = ./src

# Opcoes de compilacao
CFLAGS = -Wall -pedantic -ansi -std=c++11 -I $(INC_DIR)

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean distclean doxy

# Define o alvo (target) para a compilacao completa.
# Ao final da compilacao, remove os arquivos objeto.
all: clean tarefa1 tarefa2 tarefa3 doxy
debug: CFLAGS += -g -O0
debug: clean tarefa1 tarefa2 tarefa3

# Alvo (target) para a construcao do executavel tarefa1
# Define os arquivos tratastring.o e tarefa1main.o como dependencias
tarefa1: $(OBJ_DIR)/tratastring.o $(OBJ_DIR)/tarefa1main.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel $@ criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto tratastring.o
# Define os arquivos tratastring.cpp e tratastring.h como dependencias.
$(OBJ_DIR)/tratastring.o: $(SRC_DIR)/tarefa1/tratastring.cpp $(INC_DIR)/tarefa1/tratastring.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto tarefa1main.o
# Define o arquivo tarefa1main.cpp como dependencia.
$(OBJ_DIR)/tarefa1main.o: $(SRC_DIR)/tarefa1/tarefa1main.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do executavel tarefa2
# Define os arquivos lista.o e tarefa2.o como dependencias
tarefa2: $(OBJ_DIR)/tarefa2main.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel $@ criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto tarefa2main.o
# Define o arquivo tarefa2main.cpp como dependencia.
$(OBJ_DIR)/tarefa2main.o: $(SRC_DIR)/tarefa2/tarefa2main.cpp $(INC_DIR)/tarefa2/lista.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do executavel tarefa3
# Define os arquivos turma.o, aluno.o, funcoes.o, menu.o e tarefa3main.o como dependencias
tarefa3: $(OBJ_DIR)/turmas.o $(OBJ_DIR)/tarefa3main.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel $@ criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto turma.o
# Define os arquivos turma.cpp e turma.h como dependencias.
$(OBJ_DIR)/turmas.o: $(SRC_DIR)/tarefa3/turmas.cpp $(INC_DIR)/tarefa3/lista.h $(INC_DIR)/tarefa3/turmas.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto aluno.o
# Define os arquivos aluno.cpp e aluno.h como dependencias.
$(OBJ_DIR)/tarefa3main.o: $(SRC_DIR)/tarefa3/tarefa3main.cpp $(INC_DIR)/tarefa3/lista.h $(INC_DIR)/tarefa3/turmas.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
