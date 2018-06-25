CC=gcc
COMPILE.c=$(CC) $(CFLAGS) $(CPPFLAGS) -c
LINK.c=$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
CFLAGS= -Wall -g -fno-omit-frame-pointer

PROGS =	gout1 gout2

all:	$(PROGS)

gout1: test1.o
		$(CC) $(CFLAGS) -o $@ $^

gout2: test2.o
		$(CC) $(CFLAGS) -o $@ $^ -lpthread

clean:
	rm -f $(PROGS) *.o core*
