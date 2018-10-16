CC=gcc
COMPILE.c=$(CC) $(CFLAGS) $(CPPFLAGS) -c
LINK.c=$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
CFLAGS= -Wall

PROGS = traversal_demo bst_demo \
		precreate_demo forktree_demo

all:	$(PROGS)

traversal_demo : traversal_demo.o lnx_queue.o lnx_stack.o binarytree.o node.o
	$(CC) $(CFLAGS) -o $@ $^

bst_demo : bst_demo.o lnx_queue.o lnx_stack.o binarytree.o node.o
	$(CC) $(CFLAGS) -o $@ $^

precreate_demo : precreate_demo.o lnx_queue.o lnx_stack.o binarytree.o node.o
	$(CC) $(CFLAGS) -o $@ $^

forktree_demo : forktree_demo.o lnx_queue.o lnx_stack.o binarytree.o node.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(PROGS) *.o
