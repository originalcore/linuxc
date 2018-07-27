# 使用GDB定位线程死锁问题

ps查看到的结果,进程已经休眠(Sl),死锁的概率很大

	$ ps ax -L | grep gout8
	7013  7013 pts/2    Sl     0:00 ./gout8
	7013  7015 pts/2    Sl     0:00 ./gout8

使用gdb调试该程序

	gdb -p `pidof gout8`

查看当前线程调用栈

	(gdb) bt

查看线程信息带星号的表示当前线程,目前在主线程

	(gdb) info thread
	Id   Target Id         Frame
	2    Thread 0x7f3e495ff700 (LWP 7015) "gout8" 0x00007f3e499acd5c in __lll_lock_wait ()
	from /lib64/libpthread.so.0
	* 1    Thread 0x7f3e49da8700 (LWP 7013) "gout8" 0x00007f3e499a56fd in pthread_join ()
	from /lib64/libpthread.so.0

需要切换到死锁的子线程

	(gdb) thread 2
	[Switching to thread 2 (Thread 0x7f3e495ff700 (LWP 7015))]
	#0  0x00007f3e499acd5c in __lll_lock_wait () from /lib64/libpthread.so.0

查看当前线程调用栈

	(gdb) bt
	#0  0x00007f3e499acd5c in __lll_lock_wait () from /lib64/libpthread.so.0
	#1  0x00007f3e499a6b45 in pthread_mutex_lock () from /lib64/libpthread.so.0
	#2  0x0000000000400824 in cnt_reset () at astall.c:11
	#3  0x0000000000400860 in start_routine (arg=0x0) at astall.c:22
	#4  0x00007f3e499a4494 in start_thread () from /lib64/libpthread.so.0
	#5  0x00007f3e496e95dd in clone () from /lib64/libc.so.6

看到#1第地方pthread_mutex_lock已经进入休眠

也就是说可能多次调用了加锁函数pthread_mutex_lock

采用下面操作来记录死锁发生前所有操作

即使显示信息行数超过了终端行数也不要停止显示

	(gdb) set pagination off

将屏幕显示的内容记录到文件中

	(gdb) set logging file debug.log

覆盖同名文件

	(gdb) set logging overwrite

开启记录日志

	(gdb) set logging on
	Copying output to debug.log.
	(gdb) start
	The program being debugged has been started already.
	Start it from the beginning? (y or n) y
	Temporary breakpoint 1 at 0x4008ad: file astall.c, line 33.
	Starting program: /home/zeroway/github/linuxc/gdb/gout8
	[Thread debugging using libthread_db enabled]
	Using host libthread_db library "/lib64/libthread_db.so.1".

	Temporary breakpoint 1, main (argc=1, argv=0x7fffffffdd68) at astall.c:33
	33      {

将pthread_mutex_lock和pthread_mutex_unlock地址保存在变量中,并打上断点

	(gdb) set $addr1 = pthread_mutex_lock
	(gdb) set $addr2 = pthread_mutex_unlock
	(gdb) b *$addr1
	Breakpoint 2 at 0x7ffff7bc8ad0
	(gdb) b *$addr2
	Breakpoint 3 at 0x7ffff7bca200

输入下面脚本开始测试

	(gdb) while 1
	 >c
	 >if $pc != $addr1 && $pc != $addr2
	  >quit
	  >end
	 >bt
	 >end

	Breakpoint 2, 0x00007ffff7bc8ad0 in pthread_mutex_lock () from /lib64/libpthread.so.0
	#0  0x00007ffff7bc8ad0 in pthread_mutex_lock () from /lib64/libpthread.so.0
	#1  0x00007ffff793c103 in _dl_addr () from /lib64/libc.so.6
	#2  0x00007ffff789eb16 in ?? () from /lib64/libc.so.6
	#3  0x00007ffff789edae in ?? () from /lib64/libc.so.6
	#4  0x00007ffff789e5ca in calloc () from /lib64/libc.so.6
	#5  0x00007ffff7dec982 in ?? () from /lib64/ld-linux-x86-64.so.2
	#6  0x00007ffff7ded34e in _dl_allocate_tls () from /lib64/ld-linux-x86-64.so.2
	#7  0x00007ffff7bc6f05 in pthread_create@@GLIBC_2.2.5 () from /lib64/libpthread.so.0
	#8  0x00000000004008d7 in main (argc=1, argv=0x7fffffffdd68) at astall.c:36

	Breakpoint 3, 0x00007ffff7bca200 in pthread_mutex_unlock () from /lib64/libpthread.so.0
	#0  0x00007ffff7bca200 in pthread_mutex_unlock () from /lib64/libpthread.so.0
	#1  0x00007ffff793c29b in _dl_addr () from /lib64/libc.so.6
	#2  0x00007ffff789eb16 in ?? () from /lib64/libc.so.6
	#3  0x00007ffff789edae in ?? () from /lib64/libc.so.6
	#4  0x00007ffff789e5ca in calloc () from /lib64/libc.so.6
	#5  0x00007ffff7dec982 in ?? () from /lib64/ld-linux-x86-64.so.2
	#6  0x00007ffff7ded34e in _dl_allocate_tls () from /lib64/ld-linux-x86-64.so.2
	#7  0x00007ffff7bc6f05 in pthread_create@@GLIBC_2.2.5 () from /lib64/libpthread.so.0
	#8  0x00000000004008d7 in main (argc=1, argv=0x7fffffffdd68) at astall.c:36
	[New Thread 0x7ffff7821700 (LWP 7084)]
	[Switching to Thread 0x7ffff7821700 (LWP 7084)]

	Breakpoint 2, 0x00007ffff7bc8ad0 in pthread_mutex_lock () from /lib64/libpthread.so.0
	#0  0x00007ffff7bc8ad0 in pthread_mutex_lock () from /lib64/libpthread.so.0
	#1  0x0000000000400850 in start_routine (arg=0x0) at astall.c:20
	#2  0x00007ffff7bc6494 in start_thread () from /lib64/libpthread.so.0
	#3  0x00007ffff790b5dd in clone () from /lib64/libc.so.6

	Breakpoint 3, 0x00007ffff7bca200 in pthread_mutex_unlock () from /lib64/libpthread.so.0
	#0  0x00007ffff7bca200 in pthread_mutex_unlock () from /lib64/libpthread.so.0
	#1  0x000000000040087b in start_routine (arg=0x0) at astall.c:25
	#2  0x00007ffff7bc6494 in start_thread () from /lib64/libpthread.so.0
	#3  0x00007ffff790b5dd in clone () from /lib64/libc.so.6
	cnt = 1

	Breakpoint 2, 0x00007ffff7bc8ad0 in pthread_mutex_lock () from /lib64/libpthread.so.0
	#0  0x00007ffff7bc8ad0 in pthread_mutex_lock () from /lib64/libpthread.so.0
	#1  0x0000000000400850 in start_routine (arg=0x0) at astall.c:20
	#2  0x00007ffff7bc6494 in start_thread () from /lib64/libpthread.so.0
	#3  0x00007ffff790b5dd in clone () from /lib64/libc.so.6

	Breakpoint 3, 0x00007ffff7bca200 in pthread_mutex_unlock () from /lib64/libpthread.so.0
	#0  0x00007ffff7bca200 in pthread_mutex_unlock () from /lib64/libpthread.so.0
	#1  0x000000000040087b in start_routine (arg=0x0) at astall.c:25
	#2  0x00007ffff7bc6494 in start_thread () from /lib64/libpthread.so.0
	#3  0x00007ffff790b5dd in clone () from /lib64/libc.so.6
	cnt = 2

	Breakpoint 2, 0x00007ffff7bc8ad0 in pthread_mutex_lock () from /lib64/libpthread.so.0
	#0  0x00007ffff7bc8ad0 in pthread_mutex_lock () from /lib64/libpthread.so.0
	#1  0x0000000000400850 in start_routine (arg=0x0) at astall.c:20
	#2  0x00007ffff7bc6494 in start_thread () from /lib64/libpthread.so.0
	#3  0x00007ffff790b5dd in clone () from /lib64/libc.so.6

	Breakpoint 3, 0x00007ffff7bca200 in pthread_mutex_unlock () from /lib64/libpthread.so.0
	#0  0x00007ffff7bca200 in pthread_mutex_unlock () from /lib64/libpthread.so.0
	#1  0x000000000040087b in start_routine (arg=0x0) at astall.c:25
	#2  0x00007ffff7bc6494 in start_thread () from /lib64/libpthread.so.0
	#3  0x00007ffff790b5dd in clone () from /lib64/libc.so.6
	cnt = 3

	Breakpoint 2, 0x00007ffff7bc8ad0 in pthread_mutex_lock () from /lib64/libpthread.so.0
	#0  0x00007ffff7bc8ad0 in pthread_mutex_lock () from /lib64/libpthread.so.0
	#1  0x0000000000400850 in start_routine (arg=0x0) at astall.c:20
	#2  0x00007ffff7bc6494 in start_thread () from /lib64/libpthread.so.0
	#3  0x00007ffff790b5dd in clone () from /lib64/libc.so.6

	Breakpoint 2, 0x00007ffff7bc8ad0 in pthread_mutex_lock () from /lib64/libpthread.so.0
	#0  0x00007ffff7bc8ad0 in pthread_mutex_lock () from /lib64/libpthread.so.0
	#1  0x0000000000400824 in cnt_reset () at astall.c:11
	#2  0x0000000000400860 in start_routine (arg=0x0) at astall.c:22
	#3  0x00007ffff7bc6494 in start_thread () from /lib64/libpthread.so.0
	#4  0x00007ffff790b5dd in clone () from /lib64/libc.so.6
	^C  <===这里ctrl_c结束了程序
	Program received signal SIGINT, Interrupt.
	[Switching to Thread 0x7ffff7fc6700 (LWP 7075)]
	0x00007ffff7bc76fd in pthread_join () from /lib64/libpthread.so.0
	A debugging session is active.

也可以将上面命令保存在debug.cmd中

	set pagination off
	set logging file debug.log
	set logging overwrite
	set logging on
	start
	set $addr1 = pthread_mutex_lock
	set $addr2 = pthread_mutex_unlock
	b *$addr1
	b *$addr2
	b *$addr2
	while 1
	c
	if $pc != $addr1 && $pc != $addr2
	quit
	end
	bt
	end

输入下面命令同样能够得到需要的调试信息

	gdb gout8 -x debug.cmd

查看输出的日志信息可以发现在astall.c 20行和22行两次加锁最终导致死锁

	Breakpoint 2, 0x00007ffff7bc8ad0 in pthread_mutex_lock () from /lib64/libpthread.so.0
	#0  0x00007ffff7bc8ad0 in pthread_mutex_lock () from /lib64/libpthread.so.0
	#1  0x0000000000400850 in start_routine (arg=0x0) at astall.c:20 <==这里加锁
	#2  0x00007ffff7bc6494 in start_thread () from /lib64/libpthread.so.0
	#3  0x00007ffff790b5dd in clone () from /lib64/libc.so.6

	Breakpoint 2, 0x00007ffff7bc8ad0 in pthread_mutex_lock () from /lib64/libpthread.so.0
	#0  0x00007ffff7bc8ad0 in pthread_mutex_lock () from /lib64/libpthread.so.0
	#1  0x0000000000400824 in cnt_reset () at astall.c:11 <==这里加锁
	#2  0x0000000000400860 in start_routine (arg=0x0) at astall.c:22
	#3  0x00007ffff7bc6494 in start_thread () from /lib64/libpthread.so.0
	#4  0x00007ffff790b5dd in clone () from /lib64/libc.so.6
	^C  <===这里ctrl_c结束了程序
	Program received signal SIGINT, Interrupt.
	[Switching to Thread 0x7ffff7fc6700 (LWP 7075)]
	0x00007ffff7bc76fd in pthread_join () from /lib64/libpthread.so.0
	A debugging session is active.
