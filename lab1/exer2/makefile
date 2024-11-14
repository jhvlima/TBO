all: experimento experimentoValgrind

compila:
	gcc -c *.c
	gcc -o progJosefo *.o

experimentoValgrind: compila
		rm -f experimentoValgrind.txt
		bash -c 'for i in {3..9}; do \
			nohup time valgrind ./progJosefo $$(echo "10^$$i" | bc) 10 >> experimentoValgrind.txt; \
		done'

experimento: compila
		rm -f experimento.txt
		bash -c 'for i in {3..9}; do \
			nohup time ./progJosefo $$(echo "10^$$i" | bc) 10 >> experimento.txt; \
		done'