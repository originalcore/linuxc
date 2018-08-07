# GDB调试信息的使用

GDB调试要求在编译的时候需要-g选项

但是程序发布需要用strip将调试信息删除

所以可以在编译过程中生成调试符号表

	$(OBJCOPY) --only-keep-debug $@ objcopy_$@.symbols
	$(STRIP) --only-keep-debug $@ -o strip_$@.symbols

## 正常运行strip后的程序

加载strip后的程序能看到提示(no debugging symbols found)

	(gdb) file goutd
	Reading symbols from goutd...(no debugging symbols found)...done.
	(gdb) start
	Function "main" not defined.
	Make breakpoint pending on future shared library load? (y or [n])
	Starting program: goutd

## 手动加载调试符号表

使用symbol file启动调试

	gdb -e goutd -s objcopy_goutd.symbols
	或
	gdb -e goutd -s strip_goutd.symbols

启动后显示如下

	Reading symbols from objcopy_goutd.symbols...done.
	(gdb) start
	Temporary breakpoint 1 at 0x400535: file hello.c, line 7.
	Starting program: goutd

	Temporary breakpoint 1, main (argc=1, argv=0x7fffffffe188) at hello.c:7
	7               for (i = 0; i < 3; i++)
