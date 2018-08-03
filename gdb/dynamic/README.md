# GDB 调试动态库

顶层目录编译动态库和可执行程序

	make

程序的执行(只适合在开发中临时用,通常LD_LIBRARY_PATH是不推荐使用的)

	LD_LIBRARY_PATH=./lib ./testapp

具体设置和说明参见[LinuxC.pdf P257](../../LinuxC.pdf)

动态库的使用不是这里的重点


在gdb里设置动态库加载路径

	(gdb) file testapp
	Reading symbols from testapp...done.

	(gdb) set env LD_LIBRARY_PATH /linuxc/gdb/dynamic/lib

	(gdb) r
	Starting program: /linuxc/gdb/dynamic/testapp
	value = 0
	set value = 911
	value = 911
	[Inferior 1 (process 10570) exited normally]
