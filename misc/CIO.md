# C库函数I/O

## 以字节位单位的I/O函数

[代码例子](./byte_io.c)

|函数|效果|
|--|--
|fgetc|从指定的文件中读一个字节
|getchar|从标准输入读一个字节,相当于fgetc(stdin)

fgetc几点说明

- 要用fgetc函数读一个文件,该文件的打开方式必须是可读的
- 每调用一次fgetc读写位置向后移动一个字节,因此可以连续多次调用fgetc函数依次读取多个字节
- 返回值必须转换成int再返回

|函数|效果|
|--|--
|fputc|向指定的文件中写一个字节
|putchar|向标准输出写一个字节,相当于fputc(c, stdout)

fputc使用说明

- 要用fputc函数写一个文件,该文件的打开方式必须是可写的(包括追加)
- 每调用一次fputc,读写位置向后移动一个字节,因此可以连续多次调用fputc函数依次写入多个字节,但如果文件是以追加方式打开的,每次调用fputc时总是将读写位置移到文件末尾然后把要写入的字节追加到后面

在终端输入表示EOF的两种方法

- 在一行的开头输入ctrl-d(如果不在一行的开头则需要输入两次ctrl-d)
- 使用shell的Heredoc语法

示例如下

输入一次ctrl-d

	./byteio
	abcd	<--这里输入回车
	abcd	<--这行是输入ctrl-d后才输出的结果

输入两次ctrl-d

	./byteio
	abcdabcd <--在输入abcd后连续输入两次ctrl-d就会得到后面的结果

使用Heredoc(这里用END标识)

	./byteio << END
	> abcd
	> END
	abcd	<--这行是输出结果

## 以字符串为单位的I/O函数(fputs,fgets)

[参考代码](./record.c)

## 以记录为单位的I/O函数

[fread参考代码](./record_read.c)

[fwrite参考代码](./record_write.c)

fread和fwrite用于读写记录,这里的记录是指一串固定长度的字节,比如一个int,一个结构体或者一个定长数组,参数size指出一条记录的长度, nmemb指出要读或写多少条记录,这些记录在ptr所指的内存空间中连续存放

