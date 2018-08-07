# 多进程和多线程调试

[参考文章 gdb调试多进程](https://www.cnblogs.com/jianyungsun/p/8085153.html)

## 多进程调试设置

默认设置下,在调试多进程程序时GDB只会调试主进程.但是GDB(版本V7.0后)支持多进程的分别以及同时调试,换句话说,GDB可以同时调试多个程序

只需要设置follow-fork-mode(默认值:parent)和detach-on-fork(默认值:on)即可

|follow-fork-mode|detach-on-fork|说明|
|----|----|----|
|parent|on|只调试主进程(GDB默认)|
|child|on|只调试子进程|
|parent|off|同时调试两个进程,gdb跟主进程,子进程block在fork位置|
|child|off|同时调试两个进程,gdb跟子进程,主进程block在fork位置|

设置方法

	set follow-fork-mode [parent|child]
	set detach-on-fork [on|off]

## 多进程调试实例[multi_process.c](./multi_process.c)

加载程序,并在loop_work打断点

	(gdb) file goutc
	Reading symbols from goutc...done.
	(gdb) b loop_work
	Breakpoint 1 at 0x4008c7: file multi_process.c, line 37.

想从打印信息看下当前调试的是哪个进程或线程,所以这里忽视前5次断点

	(gdb) ignore 1 5
	Will ignore next 5 crossings of breakpoint 1.

设置当前跟踪子进程(此时主进程将卡在fork的地方)

	(gdb) set follow-fork-mode child
	(gdb) set detach-on-fork off
	(gdb) r
	Starting program: goutc
	[Thread debugging using libthread_db enabled]
	Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
	Start to create two processes
	[New process 5954]
	[Thread debugging using libthread_db enabled]
	Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
	Reading symbols from
	/usr/lib/debug/.build-id/ce/17e023542265fc11d9bc8f534bb4f070493d30.debug...done.
	Reading symbols from /usr/lib/debug/lib/x86_64-linux-gnu/libc-2.23.so...done.
	Reading symbols from /usr/lib/debug/lib/x86_64-linux-gnu/ld-2.23.so...done.
	child_p:  pid[5954] created		<====这里可以看到当前跑的是子进程
	DEBUG: [loop_work]: child_p:
	DEBUG: [loop_work]: child_p:
	DEBUG: [loop_work]: child_p:
	DEBUG: [loop_work]: child_p:
	DEBUG: [loop_work]: child_p:
	[Switching to Thread 0x7ffff7fcf700 (LWP 5954)]

	Thread 2.1 "goutc" hit Breakpoint 1, loop_work (msg=0x7fffffffe050 "child_p: ")
	at multi_process.c:37
	37                      DBG_PRINT("%s\n", msg);

查看当前进程情况

	(gdb) i inferiors
	  Num  Description       Executable
	  1    process 5950      goutc
	* 2    process 5954      goutc

切换到主进程

	(gdb) inferior 1
	[Switching to inferior 1 [process 5950] (goutc)]
	[Switching to thread 1.1 (Thread 0x7ffff7fcf700 (LWP 5950))]

再次忽视5次断点并执行(可见当前执行的是主进程中的代码)

	(gdb) ignore 1 5
	(gdb) c
	Continuing.
	DEBUG: [loop_work]: parent_t:
	DEBUG: [loop_work]: child_t:
	DEBUG: [loop_work]: parent_t:
	DEBUG: [loop_work]: child_t:
	DEBUG: [loop_work]: parent_t:
	DEBUG: [loop_work]: child_t:

	Thread 1.1 "goutc" hit Breakpoint 1, loop_work (msg=0x400c77 "parent_t: ") at
	multi_process.c:37
	37                      DBG_PRINT("%s\n", msg);

查看当前线程信息

	(gdb) i threads
	  Id   Target Id         Frame
	* 1.1  Thread 0x7ffff7fcf700 (LWP 5950) "goutc" loop_work (msg=0x400c77 "parent_t: ") at multi_process.c:37
	  1.2  Thread 0x7ffff77ef700 (LWP 6088) "goutc" loop_work (msg=0x400bc9 "child_t: ") at multi_process.c:37
	  2.1  Thread 0x7ffff7fcf700 (LWP 5954) "goutc" loop_work (msg=0x7fffffffe050 "child_p: ") at multi_process.c:37

让多个进程同时执行

	set schedule-multiple on

查看和设置print inferior-events设置的状态

	show print inferior-events
	set print inferior-events [on | off]

杀死某个进程,比如进程号4

	kill inferiors 4
