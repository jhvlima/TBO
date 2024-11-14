all: experimento

compila:
	gcc -c *.c
	gcc -o dijkstra *.o

experimento: compila
	./dijkstra < expressao.txt > experimento.txt