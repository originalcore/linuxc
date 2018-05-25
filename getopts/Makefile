CC=gcc
COMPILE.c=$(CC) $(CFLAGS) $(CPPFLAGS) -c
LINK.c=$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
CFLAGS= -Wall

PROGS =	gopt gopt_long

all:	$(PROGS)

gopt:	getopt.o
		$(CC) $(CFLAGS) -o $@ $^

gopt_long:	getopt_long.o
		$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(PROGS) *.o a.out

