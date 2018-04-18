# addr2line Usage

## example1

Error log as below

	04-16 18:27:16.917 F/DEBUG ( 237): backtrace:
	04-16 18:27:16.917 F/DEBUG ( 237): #00 pc 000442b8 /system/lib/libc.so (tgkill+12)
	04-16 18:27:16.917 F/DEBUG ( 237): #01 pc 00041ec5 /system/lib/libc.so (pthread_kill+32)
	04-16 18:27:16.917 F/DEBUG ( 237): #02 pc 0001badf /system/lib/libc.so (raise+10)
	04-16 18:27:16.917 F/DEBUG ( 237): #03 pc 00018c91 /system/lib/libc.so (_libc_android_abort+34)
	04-16 18:27:16.917 F/DEBUG ( 237): #04 pc 00016784 /system/lib/libc.so (abort+4)
	04-16 18:27:16.917 F/DEBUG ( 237): #05 pc 0000d92b /system/lib/libsensorservice.so
	04-16 18:27:16.917 F/DEBUG ( 237): #06 pc 00010855 /system/lib/libutils.so (_ZN7android6Thread11_threadLoopEPv+112)
	04-16 18:27:16.917 F/DEBUG ( 237): #07 pc 000600db /system/lib/libandroid_runtime.so (_ZN7android14AndroidRuntime15javaThreadShellEPv+70)
	04-16 18:27:16.917 F/DEBUG ( 237): #08 pc 000417c7 /system/lib/libc.so (_ZL15_pthread_startPv+30)
	04-16 18:27:16.917 F/DEBUG ( 237): #09 pc 00019313 /system/lib/libc.so (__start_thread+6)

Using addr2line find out the error place

	arm-linux-gnueabihf-addr2line -e out/target/product/rk3288/symbols/system/lib/libsensorservice.so 0000d92b

## example2(see addr2line_usage.c)
