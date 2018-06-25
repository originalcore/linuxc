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
