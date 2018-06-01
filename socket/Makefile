CC=gcc
COMPILE.c=$(CC) $(CFLAGS) $(CPPFLAGS) -c
LINK.c=$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
CFLAGS= -Wall -DUSE_RW

PROGS =	tcp_server_wrap tcp_client_wrap tcp_server tcp_client \
	tcp_client_inter tcp_server_inter udp_server udp_client

all: $(PROGS)

tcp_server:	tcp_server.o
		$(CC) $(CFLAGS) -o $@ $^

tcp_client:	tcp_client.o
		$(CC) $(CFLAGS) -o $@ $^

tcp_server_wrap:	tcp_server_wrap.o wrap.o
		$(CC) $(CFLAGS) -o $@ $^

tcp_client_wrap:	tcp_client_wrap.o wrap.o
		$(CC) $(CFLAGS) -o $@ $^

tcp_client_inter:	tcp_client_interactive.o wrap.o
		$(CC) $(CFLAGS) -o $@ $^

tcp_server_inter:	tcp_server_interactive.o wrap.o
		$(CC) $(CFLAGS) -o $@ $^

udp_server:	udp_server.o wrap.o
		$(CC) -o $@ $^

udp_client:	udp_client.o wrap.o
		$(CC) -o $@ $^

clean:
	rm -f $(PROGS) *.o
