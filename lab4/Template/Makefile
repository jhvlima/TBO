all:
	gcc -g -Wall *.c -lm -lglut -lGL

testa: all
	./a.out 200 ../in/diffusion200.txt

clean:
	rm -f *.o a.out
