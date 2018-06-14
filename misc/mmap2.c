#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int print_usage(const char *name)
{
	printf("%s <text_file>\n", name);
	return -1;
}

/*
 * touch test
 * echo "abcd" >> test
 * or echo abcd > test
 * ./a.out test
 * or create a file which size is
 * larger than the context size
 */
int main(int argc, char *argv[])
{
	int len;
	int i;
	int fd;
	char *mapped_mem;
	size_t map_len = 1024;
	void *start_addr = 0;

	/* 被映射的文件大小一定要大于将要写入的数据大小 */
	const char* context = "this is map file writting\n";
	struct stat st;

	fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd < 0)
	{
		perror("open file error\n");
		exit(-1);
	}

	fstat(fd, &st);
	printf("filesize = %d\n", st.st_size);

#ifdef IGNORE_ORIGIN_FILE_SIZE
	/* 在文件最后添加一个空字符,以便mmap能够map操作正常 */
	/*
	 * 一定要有这部操作,否则会发现只能写部分内容到文件中
	 * 因为执行了lseek后文件大小变了
	 * 也就是说mmap不能改变原文件大小
	 * 在使用mmap后向文件中写入数据不能超过原文件大小
	 */
	/*
	 * 可以使用gdb调试
	 * gcc -g mmap2.c
	 * gdb调试带参数的程序
	 * gdb -tui a.out
	 * (gdb) set args -c test
	 * 其中需要修改下代码,因为在gdb中argv[2]才是传入的参数test
	 */
	map_len = lseek(fd, map_len, SEEK_END);
	write(fd, "\0", 1);
	lseek(fd, 0, SEEK_SET);

	fstat(fd, &st);
	printf("filesize = %d\n", st.st_size);
#endif

	/* read write, private */
	mapped_mem = mmap(start_addr, map_len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	/* now, file can be close safety */
	close(fd);

	/* read from map */
	printf("read from map << %s\n", mapped_mem);

	len = strlen(context);

	/* compare the file size and context ready for writting */
	if (len > st.st_size)
		printf("WARNNING : context should be truncked\n");

	printf("write context to file\n");
	/* write the map */
	for (i = 0; i < len; i++)
		mapped_mem[i] = context[i];

	/* read from map again */
	printf("read from map for check<< %s\n", mapped_mem);

	/* unmape the file */
	munmap(mapped_mem, map_len);

	return 0;
}
