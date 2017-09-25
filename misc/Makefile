CC=gcc
COMPILE.c=$(CC) $(CFLAGS) $(CPPFLAGS) -c
LINK.c=$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
CFLAGS= -Wall

PROGS =	byteio cmd_action containerof cpmem daemon envi \
	findnumber findsubstr cpuspd getpwd gopt initdarr \
	inotify inotifyep jmp localva strdup parr pbrb \
	recd recdr recdw recu reverstr revert180 scan_cal \
	bigend socketp stack stdouterr structnop swapno \
	threadsync ttyname tdas idx2str pc spa

all:	$(PROGS)

spa: struct_point_array.o
		$(CC) $(CFLAGS) -o $@ $^

pc:	pc.o
		$(CC) $(CFLAGS) -lpthread -o $@ $^

idx2str:	use_index_find_string.o
		$(CC) $(CFLAGS) -o $@ $^

tdas:	two_dimension_array.o
		$(CC) $(CFLAGS) -o $@ $^

ttyname:	ttyname.o
		$(CC) $(CFLAGS) -o $@ $^

threadsync:	thread_sync.o
		$(CC) $(CFLAGS) -lpthread -o $@ $^

swapno:	swap_numbers.o
		$(CC) $(CFLAGS) -o $@ $^

structnop:	struct_without_pack.o
		$(CC) $(CFLAGS) -o $@ $^

stdouterr:	stdout_stderr.o
		$(CC) $(CFLAGS) -o $@ $^

stack:	stack.o
		$(CC) $(CFLAGS) -o $@ $^

socketp:	socketpair.o
		$(CC) $(CFLAGS) -lpthread -o $@ $^

bigend:	set_big_endless.o
		$(CC) $(CFLAGS) -o $@ $^

scan_cal:	scan_calculator.o
		$(CC) $(CFLAGS) -o $@ $^

revert180:	revert180.o
		$(CC) $(CFLAGS) -o $@ $^

reverstr:	revers_string.o
		$(CC) $(CFLAGS) -o $@ $^

recu:	recursion.o
		$(CC) $(CFLAGS) -o $@ $^

recdw:	record_write.o
		$(CC) $(CFLAGS) -o $@ $^

recdr:	record_read.o
		$(CC) $(CFLAGS) -o $@ $^

recd:	record.o
		$(CC) $(CFLAGS) -o $@ $^

pbrb:	print_binary_rever_bit.o
		$(CC) $(CFLAGS) -o $@ $^

parr:	point_to_array.o
		$(CC) $(CFLAGS) -o $@ $^

strdup:	mystrdup.o
		$(CC) $(CFLAGS) -o $@ $^

localva:	local_variable.o
		$(CC) $(CFLAGS) -o $@ $^

jmp:	jmp.o
		$(CC) $(CFLAGS) -o $@ $^

inotifyep:	inotify_epoll.o
		$(CC) $(CFLAGS) -o $@ $^

inotify:	inotify.o
		$(CC) $(CFLAGS) -o $@ $^

initdarr:	init_array.o
		$(CC) $(CFLAGS) -o $@ $^

gopt:	getopt.o
		$(CC) $(CFLAGS) -o $@ $^

byteio:	byte_io.o
		$(CC) $(CFLAGS) -o $@ $^

cmd_action:	cmd_and_action.o
		$(CC) $(CFLAGS) -o $@ $^

containerof :	container_of.o
		$(CC) $(CFLAGS) -o $@ $^

cpmem :	copy_struct_member.o
		$(CC) $(CFLAGS) -o $@ $^

envi :	environ.o
		$(CC) $(CFLAGS) -o $@ $^

daemon :	daemon.o
		$(CC) $(CFLAGS) -o $@ $^

findnumber :	find_number_in_string.o
		$(CC) $(CFLAGS) -o $@ $^

findsubstr :	find_sub_str.o
		$(CC) $(CFLAGS) -o $@ $^

cpuspd :	get_cpu_speed_from_cpuinfo.o
		$(CC) $(CFLAGS) -o $@ $^

getpwd :	get_exe_path.o
		$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(PROGS) *.o a.out iotestfile log.txt recfile
