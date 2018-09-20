#include <sys/wait.h>
#include "apue.h"

int main(int argc, char *argv[])
{
	char line[MAXLINE];
	FILE *fpin;

	/*
	 * popen调用fork创建两个进程
	 * 子进程调用exec来执行传给popen的cmdstring
	 * 当type 是r时子进程将执行结果输出到主进程的fp
	 * fp就是popen的返回值
	 */
	if ( (fpin = popen("./myuclc", "r")) == NULL )
		err_sys("popen error");

	for (;;)
	{
		fputs("prompt> ", stdout);
		fflush(stdout);

		/*
		 * 从标准输入获取数据,传给myuclc处理后
		 * myuclc将结果输出给fpin
		 * fgets将fpin中的数据拷贝到line中
		 */
		if (fgets(line, MAXLINE, fpin) == NULL)
			break;

		if (fputs(line, stdout) == EOF)
			err_sys("fputs error to pipe");
	}

	if (pclose(fpin) == -1)
		err_sys("pclose error");

	putchar('\n');
	exit(0);
}
