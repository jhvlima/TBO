compila:
	gcc -c arrayInt.c main.c
	gcc -o progArrayInt arrayInt.o main.o
	gcc -c arrayChar.c main.c
	gcc -o progArrayChar arrayChar.o main.o
	gcc -c arrayBit.c main.c
	gcc -o progArrayBit arrayBit.o main.o

int: compila
	nohup valgrind ./progArrayInt 100 > outArrayInt.txt

char: compila
	nohup valgrind ./progArrayChar 100 > outArrayChar.txt

bit: compila
	nohup valgrind ./progArrayBit 100 > outArrayBit.txt

experimentoMemoria: compila
	rm -rf experimentoMem*
	nohup valgrind ./progArrayInt 100000 >> experimentoMemInt.txt; \
	nohup valgrind ./progArrayChar 100000 >> experimentoMemChar.txt; \
	nohup valgrind ./progArrayBit 100000 >> experimentoMemBit.txt; \

experimentoTime: compila
	rm -rf experimentoTime*
		bash -c 'for i in {3..10}; do \
			nohup time ./progArrayInt $$(echo "10^$$i" | bc) >> experimentoTimeInt.txt; \
			nohup time ./progArrayChar $$(echo "10^$$i" | bc) >> experimentoTimeChar.txt; \
			nohup time ./progArrayBit $$(echo "10^$$i" | bc) >> experimentoTimeBit.txt; \
		done'