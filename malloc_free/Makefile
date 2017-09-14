CC=gcc
COMPILE.c=$(CC) $(CFLAGS) $(CPPFLAGS) -c
LINK.c=$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
CFLAGS= -Wall

PROGS =	output_value redirect para_allocator ret_ptr retalloc

all:	$(PROGS)

retalloc:	ret_allocator.o main_retalloc.o
		$(CC) $(CFLAGS) -o $@ $^

ret_ptr:	ret_ptr.o main_ret.o
		$(CC) $(CFLAGS) -o $@ $^

output_value:	output_value.o main_output.o
		$(CC) $(CFLAGS) -o $@ $^

redirect:	redirect_ptr.o main_red.o
		$(CC) $(CFLAGS) -o $@ $^

para_allocator:	para_allocator.o main_para.o
		$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(PROGS) *.o
