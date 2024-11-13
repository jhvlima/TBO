compila:
	gcc -c *.c
	gcc -o progJosefo *.o

experimento: compila
		rm -f experimento.txt
		bash -c 'for i in {3..9}; do \
			nohup time ./progJosefo $$(echo "10^$$i" | bc) 10 >> experimento.txt; \
		done'