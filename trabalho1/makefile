# Variables comunes
CC = gcc
CFLAGS = -Wall
VALGRIND = valgrind
BIN = main

# Regra geral para fezer os exeperimento
all: mer

# Regra para compilar cada algoritmo
$(BIN): main.c
	$(CC) $(CFLAGS) -o $@ main.c

# Regra para executar testes
mer: $(BIN)
	$(MAKE) run_tests BIN=$(BIN) OUTPUT=results_merge.txt

# Regra para executar testes com as entradas
run_tests:
	@for entrada in $(ENTRADAS_1M); do \
	    echo "Procesando $$entrada com $(BIN) (1M)..." | tee -a $(OUTPUT); \
	    ./$(BIN) 100000 < $$entrada >> $(OUTPUT); \
	done

# Regra para limpar arquivos gerados
clean:
	rm -f *.o $(BIN) results_*.txt
