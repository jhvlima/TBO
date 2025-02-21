all:  experimento

compila:
	gcc -c *.c
	gcc -o prog *.o

experimento: compila
	./prog in/abra.txt 15 > saida.txt
	./prog in/abra.txt 15 >> saida.txt
	./prog in/tale.txt 15 >> saida.txt