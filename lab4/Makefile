# Variables comunes
CC = gcc
CFLAGS = -Wall
VALGRIND = valgrind
BIN_MER = merge_sort

ENTRADAS_1M = ./input/sorted/100000.txt ./input/reverse_sorted/100000.txt ./input/unif_rand/100000.txt ./input/nearly_sorted/100000.txt
ENTRADAS_10M = ./input/sorted/1000000.txt ./input/reverse_sorted/1000000.txt ./input/unif_rand/1000000.txt ./input/nearly_sorted/1000000.txt

# Regra geral para fezer os exeperimento
all: mer

# Regra para compilar cada algoritmo
$(BIN_MER): client.c merge_sort.c
	$(CC) $(CFLAGS) -o $@ client.c merge_sort.c

# Regra para executar testes
mer: $(BIN_MER)
	@rm -rf results_merge.txt
	$(MAKE) run_tests BIN=$(BIN_MER) OUTPUT=results_merge.txt

# Regra para executar testes com as entradas
run_tests:
	@for entrada in $(ENTRADAS_1K); do \
	    echo "Procesando $$entrada com $(BIN) (1M)..." | tee -a $(OUTPUT); \
	    ./$(BIN) 100000 < $$entrada >> $(OUTPUT); \
	done
	@for entrada in $(ENTRADAS_10K); do \
	    echo "Procesando $$entrada com $(BIN) (10M)..." | tee -a $(OUTPUT); \
	    ./$(BIN) 1000000 < $$entrada >> $(OUTPUT); \
	done

# Regra para limpar arquivos gerados
clean:
	rm -f *.o $(BIN_MER) results_*.txt
