compilaBST:
	gcc -c arvore.c main.c
	gcc -o arvoreProg arvore.o main.o

experimentoBST: compila
	rm -f experiemto.txt
	bash -c 'for counter in {1..10}; do \
		./arvoreProg 100000 >> experiementoBST.txt; \
		sleep 1; \
	done'