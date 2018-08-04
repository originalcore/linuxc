# GDB 调试动态库和静态库

顶层目录编译动态库和可执行程序

	make

程序的执行(只适合在开发中临时用,通常LD_LIBRARY_PATH是不推荐使用的)

	LD_LIBRARY_PATH=./lib/static:./lib/dynamic ./testapp

具体设置和说明参见[LinuxC.pdf P257](../../LinuxC.pdf)


加载程序

	(gdb) file testapp
	Reading symbols from testapp...done.

设置LD_LIBRARY_PATH(绝对路径和相对路径都可以)

	(gdb) set env LD_LIBRARY_PATH /linuxc/gdb/libdebug/lib/dynamic:/linuxc/gdb/libdebug/lib/static
	(gdb) set env LD_LIBRARY_PATH ./lib/dynamic:.libdebug/lib/static

查看环境变量

	(gdb) show env LD_LIBRARY_PATH

执行程序

	(gdb) r
	Starting program: /linuxc/gdb/libdebug/testapp
	dynamic test start
	value = 0
	set value = 911
	value = 911
	dynamic test end
	static test start
	value = 0
	set value = 911
	value = 911
	static test end
	[Inferior 1 (process 15165) exited normally]
