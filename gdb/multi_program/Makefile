CC=gcc
CFLAGS= -Wall -g -fno-omit-frame-pointer

PROGS =	udp_client udp_server

all:	$(PROGS)

udp_client:	udp_client.o wrap.o
	$(CC) $(CFLAGS) -o $@ $^

udp_server:	udp_server.o wrap.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(PROGS) *.o core*
