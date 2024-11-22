compilaBST:
	gcc -c arvore.c pilha.c fila.c main.c
	gcc -o arvoreProg arvore.o pilha.o fila.o main.o

experimentoBST: compilaBST
	rm -f experiemto.txt
	bash -c 'for counter in {1..10}; do \
		./arvoreProg 100000 >> experiemento.txt; \
		sleep 1; \
	done'

experimentoCaminhamento: compilaBST
	./arvoreProg 10000000 > experimentoCaminhamento.txt
