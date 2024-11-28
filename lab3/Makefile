entradas = ./in/sorted/10Ksorted.txt ./in/sorted/100Ksorted.txt ./in/sorted/1Ksorted.txt ./in/reverse_sorted/1Kreverse_sorted.txt ./in/reverse_sorted/10Kreverse_sorted.txt ./in/reverse_sorted/100Kreverse_sorted.txt ./in/unif_rand/100Kunif_rand.txt ./in/unif_rand/1Kunif_rand.txt ./in/unif_rand/10Kunif_rand.txt ./in/nearly_sorted/1Knearly_sorted.txt ./in/nearly_sorted/100Knearly_sorted.txt ./in/nearly_sorted/10Knearly_sorted.txt

bub:
	gcc -Wall client.c bubble_sort.c
	rm -rf results_bubble.txt
	@for entrada in $(entradas); do \
	    echo "Procesando $$entrada..." | tee -a results_bubble.txt; \
	    ./a.out < $$entrada >> results_bubble.txt; \
	done
sel:
	gcc -Wall client.c selection_sort.c

ins:
	gcc -Wall client.c insertion_sort.c

sha:
	gcc -Wall client.c shaker_sort.c

clean:
	rm -f *.o a.out
