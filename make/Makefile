CC=gcc
COMPILE.c=$(CC) $(CFLAGS) $(CPPFLAGS) -c
LINK.c=$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
#CFLAGS= -Wall
CFLAGS= -Wall -DSHOULD_DEFINE_THIS

PROGS =	skeleton

all:	$(PROGS)

$(PROGS): test.o
		$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(PROGS) *.o
