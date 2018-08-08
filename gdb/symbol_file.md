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

### 方法1.启动GDB的时候传惨

使用symbol file启动GDB调试

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

### 方法2. 进入GDB后通过add-symbol-file添加调试符号表

先加载strip后的程序,查看程序入口点地址(比如这个例子是0x400430)

	(gdb) file goutd
	Reading symbols from goutd...(no debugging symbols found)...done.
	(gdb) i files
	Symbols from "goutd".
	Local exec file:
			`goutd', file type elf64-x86-64.
			Entry point: 0x400430
			0x0000000000400238 - 0x0000000000400254 is .interp
			0x0000000000400254 - 0x0000000000400274 is .note.ABI-tag
			0x0000000000400274 - 0x0000000000400298 is .note.gnu.build-id
			0x0000000000400298 - 0x00000000004002b4 is .gnu.hash
			0x00000000004002b8 - 0x0000000000400318 is .dynsym
			0x0000000000400318 - 0x0000000000400357 is .dynstr
			0x0000000000400358 - 0x0000000000400360 is .gnu.version
			0x0000000000400360 - 0x0000000000400380 is .gnu.version_r
			0x0000000000400380 - 0x0000000000400398 is .rela.dyn
			0x0000000000400398 - 0x00000000004003c8 is .rela.plt
			0x00000000004003c8 - 0x00000000004003e2 is .init
			0x00000000004003f0 - 0x0000000000400420 is .plt
			0x0000000000400420 - 0x0000000000400428 is .plt.got
			0x0000000000400430 - 0x00000000004005e2 is .text
			0x00000000004005e4 - 0x00000000004005ed is .fini
			0x00000000004005f0 - 0x0000000000400601 is .rodata
			0x0000000000400604 - 0x0000000000400638 is .eh_frame_hdr
			0x0000000000400638 - 0x000000000040072c is .eh_frame
			0x0000000000600e10 - 0x0000000000600e18 is .init_array
			0x0000000000600e18 - 0x0000000000600e20 is .fini_array
			0x0000000000600e20 - 0x0000000000600e28 is .jcr
			0x0000000000600e28 - 0x0000000000600ff8 is .dynamic
			0x0000000000600ff8 - 0x0000000000601000 is .got
			0x0000000000601000 - 0x0000000000601028 is .got.plt
			0x0000000000601028 - 0x0000000000601038 is .data
			0x0000000000601038 - 0x0000000000601040 is .bss

手动添加,需要指定地址

	(gdb) add-symbol-file objcopy_goutd.symbols 0x400430
