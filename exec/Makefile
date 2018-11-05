CC = gcc
CFLAGS = -Wall
PROGS = execlp upper wrapper execv_ep execl_ep \
	execle_ep execve_ep execlp_ep execvp_ep

ALL: $(PROGS)

execlp : exec_function.c
	$(CC) $(CFLAGS) -o $@ $<

upper : upper.c
	$(CC) $(CFLAGS) -o $@ $<

wrapper : wrapper.c
	$(CC) $(CFLAGS) -o $@ $<

execl_ep : execl_example.o
	$(CC) $(CFLAGS) -o $@ $<

execle_ep : execle_example.o
	$(CC) $(CFLAGS) -o $@ $<

execv_ep : execv_example.o
	$(CC) $(CFLAGS) -o $@ $<

execve_ep : execve_example.o
	$(CC) $(CFLAGS) -o $@ $<

execlp_ep : execlp_example.o
	$(CC) $(CFLAGS) -o $@ $<

execvp_ep : execvp_example.o
	$(CC) $(CFLAGS) -o $@ $<

clean :
	rm -f $(PROGS)
