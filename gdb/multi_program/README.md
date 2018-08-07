# GDB 同时调试多个程序

## 实例(udp客户端和服务器通行)

加载服务器端程序

	(gdb) file udp_server
	Reading symbols from udp_server...done.

加载客户端程序

	(gdb) add-inferior -copies 1 -exec udp_client
	Added inferior 2
	Reading symbols from udp_client...done.

查看当前状态

	(gdb) i inferiors
	  Num  Description       Executable
	* 1    <null>            udp_server
	  2    <null>            udp_client

在服务器端打一个断点后运行服务器

	(gdb) b do_something_for_client
	Breakpoint 1 at 0x400b76: file udp_server.c, line 15.
	(gdb) r
	Starting program: udp_server
	Accepting connecting...
	^C				<====这里ctrl-c手动停止服务器
	Program received signal SIGINT, Interrupt.
	0x00007ffff7b15313 in __recvfrom_nocancel () at ../sysdeps/unix/syscall-template.S:84
	84      ../sysdeps/unix/syscall-template.S: No such file or directory.

切换到客户端打断点后运行客户端程序

	(gdb) inferior 2
	[Switching to inferior 2 [<null>] (udp_client)]
	(gdb) b stub_code_for_gdb
	Breakpoint 2 at 0x400b4a: file udp_client.c, line 17.
	(gdb) set args 127.0.0.1		<====客户端程序启动需要传一个参数
	(gdb) r
	Starting program: udp_client 127.0.0.1
	hello,it's me					<====输入一些内容,发送给服务器

	Thread 2.1 "udp_client" hit Breakpoint 2, stub_code_for_gdb () at udp_client.c:17
	17              printf("this is stub code\n");

切换到服务器运行

	(gdb) inferior 1
	[Switching to inferior 1 [process 12768] (udp_server)]
	[Switching to thread 1.1 (process 12768)]
	#0  0x00007ffff7b15313 in __recvfrom_nocancel () at ../sysdeps/unix/syscall-template.S:84
	84      ../sysdeps/unix/syscall-template.S: No such file or directory.
	(gdb) c
	Continuing.
	recv 14 bytes from 127.0.0.1 at port 42859

	Thread 1.1 "udp_server" hit Breakpoint 1, do_something_for_client (buf=0x7fffffffe000 "hello,it's me\n", bytes=14) at udp_server.c:15
	15              for (i = 0; i < bytes; i++)
	(gdb) finish	<====此时服务器停在打断点的地方,使用finish跑完部分代码好调试
	Run till exit from #0  do_something_for_client (buf=0x7fffffffe000 "hello,it's me\n", bytes=14) at udp_server.c:15
	main (argc=1, argv=0x7fffffffe158) at udp_server.c:63
	63                      bytes = sendto(sock_fd, buf, bytes, 0, (struct sockaddr*)&client_addr, sizeof(client_addr));
	(gdb) n
	64                      if (bytes == -1)
	(gdb) p bytes
	$1 = 14
	(gdb) p buf		<====这里看到经过服务器处理后的数据,即将发送给客户端
	$2 = "HELLO,IT'S ME\n", '\000' <repeats 22 times>
	(gdb) c		<====让服务器继续跑完
	Continuing.
	^C				<====这里ctrl-c手动停止服务器
	Thread 1.1 "udp_server" received signal SIGINT, Interrupt.
	0x00007ffff7b15313 in __recvfrom_nocancel () at ../sysdeps/unix/syscall-template.S:84
	84      ../sysdeps/unix/syscall-template.S: No such file or directory.

再次切换到客户端

	(gdb) inferior 2
	[Switching to inferior 2 [process 12793] (udp_client)]
	[Switching to thread 2.1 (process 12793)]
	#0  stub_code_for_gdb () at udp_client.c:17
	17              printf("this is stub code\n");
	(gdb) n		<====客户端此时停在打断点的地方
	this is stub code
	18      }
	(gdb) n
	main (argc=2, argv=0x7fffffffe148) at udp_client.c:51
	51                      bytes = recvfrom(sock_fd, buf, MAXLINE, 0, NULL, 0);
	(gdb) n
	52                      if (bytes == -1)
	(gdb) p bytes
	$3 = 14
	(gdb) p buf		<====这里可以看到服务器处理后发送过来的数据
	$4 = "HELLO,IT'S ME\n\000\377", '\000' <repeats 16 times>
