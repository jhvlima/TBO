# Variables comunes
CC = gcc
CFLAGS = -Wall -O2
VALGRIND = valgrind

# Output binaries
BINARIES = merge_sort_1 merge_sort_2 merge_sort_3 merge_sort_4 merge_sort_5 merge_sort_6 merge_sort_7

# Input files
ENTRADAS_1M = ./input/sorted/100000.txt ./input/reverse_sorted/100000.txt ./input/unif_rand/100000.txt ./input/nearly_sorted/100000.txt
ENTRADAS_10M = ./input/sorted/1000000.txt ./input/reverse_sorted/1000000.txt ./input/unif_rand/1000000.txt ./input/nearly_sorted/1000000.txt

# General target
all: $(BINARIES)

# Rules for compiling each version
merge_sort_%: merge_sort_%.c client.c item.h
	$(CC) $(CFLAGS) -o $@ client.c merge_sort_$*.c

# Rule for running experiments for all versions
run_all: $(BINARIES)
	@for bin in $(BINARIES); do \
	    echo "Running tests for $$bin..."; \
	    $(MAKE) run_tests BIN=$$bin OUTPUT=results_$$bin.txt; \
	done

# Rule for running tests with inputs
run_tests:
	@rm -f $(OUTPUT)
	@for entrada in $(ENTRADAS_1M); do \
	    echo "Processing $$entrada with $(BIN) (1M)..." | tee -a $(OUTPUT); \
	    ./$(BIN) 100000 < $$entrada >> $(OUTPUT); \
	done
	@for entrada in $(ENTRADAS_10M); do \
	    echo "Processing $$entrada with $(BIN) (10M)..." | tee -a $(OUTPUT); \
	    ./$(BIN) 1000000 < $$entrada >> $(OUTPUT); \
	done

# Clean rule
clean:
	rm -f *.o $(BINARIES) results_*.txt
