TOP_DIR ?=..
CC=gcc
COMPILE.c=$(CC) $(CFLAGS) $(CPPFLAGS) -c
LINK.c=$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
CFLAGS= -Wall
INCLUDES=$(TOP_DIR)/include

PROGS =	gopt gopt_long

all:	$(PROGS)

gopt:	getopt.c
		$(CC) -I$(INCLUDES) $(CFLAGS) -o $@ $^

gopt_long:	getopt_long.o
		$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(PROGS) *.o a.out

