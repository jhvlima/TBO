compila:
	gcc -c arvore.c main.c
	gcc -o arvoreProg arvore.o main.o

experiemto: compila
	rm -f experiemto.txt
	bash -c 'for i in {1..10}; do \
		nohup time ./arvoreProg 100000 >> experiemto.txt; \
		sleep 1; \
	done'

experimento: compila
	rm -f experiemto.txt
	bash -c 'for counter in {1..10}; do \
		./arvoreProg 100000 >> experiemto.txt; \
		sleep 1; \
	done'