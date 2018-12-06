CC=gcc
CFLAGS= -Wall -ftest-coverage -fprofile-arcs

PROGS =	bubbleSort qsort

all:	$(PROGS)

bubbleSort: bubble_sort.o
		$(CC) $(CFLAGS) -o $@ $^

qsort: quick_sort.o
		$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(PROGS) *.o *.gcda *.gcno *.gcov
