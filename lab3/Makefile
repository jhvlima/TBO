# Variables comunes
CC = gcc
CFLAGS = -Wall
VALGRIND = valgrind
BIN_BUB = bubble_sort
BIN_SEL = selection_sort
BIN_INS = insertion_sort
BIN_SHA = shaker_sort

ENTRADAS_1K = ./in/sorted/1Ksorted.txt ./in/reverse_sorted/1Kreverse_sorted.txt \
              ./in/unif_rand/1Kunif_rand.txt ./in/nearly_sorted/1Knearly_sorted.txt
ENTRADAS_10K = ./in/sorted/10Ksorted.txt ./in/reverse_sorted/10Kreverse_sorted.txt \
               ./in/unif_rand/10Kunif_rand.txt ./in/nearly_sorted/10Knearly_sorted.txt
ENTRADAS_100K = ./in/sorted/100Ksorted.txt ./in/reverse_sorted/100Kreverse_sorted.txt \
                ./in/unif_rand/100Kunif_rand.txt ./in/nearly_sorted/100Knearly_sorted.txt

# Regla general para compilar
all: $(BIN_BUB) $(BIN_SEL) $(BIN_INS) $(BIN_SHA)

# Reglas para compilar cada algoritmo
$(BIN_BUB): client.c bubble_sort.c
	$(CC) $(CFLAGS) -o $@ client.c bubble_sort.c

$(BIN_SEL): client.c selection_sort.c
	$(CC) $(CFLAGS) -o $@ client.c selection_sort.c

$(BIN_INS): client.c insertion_sort.c
	$(CC) $(CFLAGS) -o $@ client.c insertion_sort.c

$(BIN_SHA): client.c shaker_sort.c
	$(CC) $(CFLAGS) -o $@ client.c shaker_sort.c

# Reglas para ejecutar pruebas
bub: $(BIN_BUB)
	@rm -rf results_bubble.txt
	$(MAKE) run_tests BIN=$(BIN_BUB) OUTPUT=results_bubble.txt

sel: $(BIN_SEL)
	@rm -rf results_selection.txt
	$(MAKE) run_tests BIN=$(BIN_SEL) OUTPUT=results_selection.txt

ins: $(BIN_INS)
	@rm -rf results_insertion.txt
	$(MAKE) run_tests BIN=$(BIN_INS) OUTPUT=results_insertion.txt

sha: $(BIN_SHA)
	@rm -rf results_shaker.txt
	$(MAKE) run_tests BIN=$(BIN_SHA) OUTPUT=results_shaker.txt

# Regla para ejecutar pruebas com las entradas
run_tests:
	@for entrada in $(ENTRADAS_1K); do \
	    echo "Procesando $$entrada com $(BIN) (1K)..." | tee -a $(OUTPUT); \
	    ./$(BIN) 1000 < $$entrada >> $(OUTPUT); \
	done
	@for entrada in $(ENTRADAS_10K); do \
	    echo "Procesando $$entrada com $(BIN) (10K)..." | tee -a $(OUTPUT); \
	    ./$(BIN) 10000 < $$entrada >> $(OUTPUT); \
	done
	@for entrada in $(ENTRADAS_100K); do \
	    echo "Procesando $$entrada com $(BIN) (100K)..." | tee -a $(OUTPUT); \
	    ./$(BIN) 100000 < $$entrada >> $(OUTPUT); \
	done

# Regla para limpiar archivos generados
clean:
	rm -f *.o $(BIN_BUB) $(BIN_SEL) $(BIN_INS) $(BIN_SHA) results_*.txt
