CC=gcc
CFLAGS= -Wall -g -fno-omit-frame-pointer
#CFLAGS= -Wall -gdwarf-2 -fno-omit-frame-pointer
CFLAGS3= -Wall -g -fno-omit-frame-pointer -DBUG_FIX
#CFLAGS= -Wall -g -fno-omit-frame-pointer -DNO_ERROR_MAKER

PROGS =	gout1 gout2 gout3 gout4 gout5 gout6

all:	$(PROGS)

gout1: test1.o
	$(CC) $(CFLAGS) -o $@ $^

gout2: test2.o
	$(CC) $(CFLAGS) -o $@ $^ -lpthread

# dependece should be a C file instead of an object here
# dependece is C file result as below:
# gcc -Wall -g -fno-omit-frame-pointer -DBUG_FIX -o gout3 test3.c -lpthread
#
# dependece object file result as below(the marco will not take effict):
# gcc -Wall -g -fno-omit-frame-pointer   -c -o test3.o test3.c
# gcc -Wall -g -fno-omit-frame-pointer -DBUG_FIX -o gout3 test3.o -lpthread
gout3: test3.c
	$(CC) $(CFLAGS3) -o $@ $^ -lpthread

gout4 : main.o foo.o bar.o
	$(CC) $(CFLAGS) -o $@ $^

gout5 : set_var_return.o
	$(CC) $(CFLAGS) -o $@ $^

gout6 : convenience.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(PROGS) *.o core*
