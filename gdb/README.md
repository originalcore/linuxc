# GDB调试

[参考文章gdb调试coredump](https://blog.csdn.net/sunxiaopengsun/article/details/72974548)

## coredump配置

查看系统是否打开coredump

	ulimit -c

设置系统开启coredump

	ulimit -c unlimited

自定义coredump文件名(在目录/path/to/下保存, 格式为core_filename_time_pid)

	echo /path/to/core_%e_%t_%p > /proc/sys/kernel/core_pattern

## 使用coredump

使用gdb和coredump调试程序(格式如下)

	gdb a.out core_dump_file

## 例子1

	gdb gout1 core_gout1_1529915161_5890

查看堆栈使用bt或者where命令

	(gdb) bt
	#0  0x00000000004004e6 in error_maker () at test1.c:7
	#1  0x0000000000400500 in main (argc=1, argv=0x7ffe528e2348) at test1.c:12
	(gdb) where
	#0  0x00000000004004e6 in error_maker () at test1.c:7
	#1  0x0000000000400500 in main (argc=1, argv=0x7ffe528e2348) at test1.c:12

## 例子2


加载应用程序

	(gdb) file gout2

加载coredump文件

	(gdb) core-file core_gout2_1529925536_10604

重新执行程序(可以不执行这步, 如果使用coredump的话就不要步)
运行了该命令后就不是使用coredump了,看到的信息有一些差异

	(gdb) r

查看所有线程信息

	(gdb) info thread
	  Id   Target Id         Frame
	  1    Thread 0x7ffff7fd9700 (LWP 10987) "gout2" 0x00007ffff7bc298d in
	pthread_join (
		threadid=140737345681152, thread_return=0x0) at pthread_join.c:90
	  2    Thread 0x7ffff77ef700 (LWP 10991) "gout2" 0x00007ffff78bc30d in nanosleep
	()
		at ../sysdeps/unix/syscall-template.S:84
	* 3    Thread 0x7ffff6fee700 (LWP 10992) "gout2" 0x0000000000400834 in
	  error_maker () at test2.c:14

查看所有线程的调用栈

	(gdb) thread apply all bt

	Thread 3 (Thread 0x7ffff6fee700 (LWP 10992)):
	#0  0x0000000000400834 in error_maker () at test2.c:14
	#1  0x0000000000400881 in start_routine (args=0x7fffffffe884) at test2.c:29
	#2  0x00007ffff7bc16ba in start_thread (arg=0x7ffff6fee700) at
	pthread_create.c:333
	#3  0x00007ffff78f741d in clone () at
	../sysdeps/unix/sysv/linux/x86_64/clone.S:109

	Thread 2 (Thread 0x7ffff77ef700 (LWP 10991)):
	#0  0x00007ffff78bc30d in nanosleep () at ../sysdeps/unix/syscall-template.S:84
	#1  0x00007ffff78bc25a in __sleep (seconds=0) at ../sysdeps/posix/sleep.c:55
	#2  0x0000000000400859 in start_routine (args=0x7fffffffe884) at test2.c:25
	#3  0x00007ffff7bc16ba in start_thread (arg=0x7ffff77ef700) at
	pthread_create.c:333
	#4  0x00007ffff78f741d in clone () at
	../sysdeps/unix/sysv/linux/x86_64/clone.S:109

	Thread 1 (Thread 0x7ffff7fd9700 (LWP 10987)):
	#0  0x00007ffff7bc298d in pthread_join (threadid=140737345681152,
	thread_return=0x0)
		at pthread_join.c:90
	#1  0x0000000000400933 in main (argc=1, argv=0x7fffffffe998) at test2.c:54

- 可以看到有3个线程,主线程Thread1调用pthread_join
- 子线程Thread2 未满足判断条件,所以处在sleep中
- 子线程Thread3 满足判断条件,执行error_maker
