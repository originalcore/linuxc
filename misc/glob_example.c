#include <stdio.h>
#include <glob.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int i;
	glob_t globbuf;

	/* 匹配当前目录下所有c文件,结果保存在globbuf中 */
	glob("*.c", GLOB_NOSORT, NULL, &globbuf);

	/* gl_pathc保存匹配成功的个数 */
	for (i = 0; i < globbuf.gl_pathc; i++)
		printf("%s\n", globbuf.gl_pathv[i]);

	// 下面C代码等同于在shell中执行如下代码
	// ls -l *.c ../*.c
	/* 将结果预留两个位置来保存给execv调用的参数 */
	globbuf.gl_offs = 2;
	glob("*.c", GLOB_DOOFFS, NULL, &globbuf);
	glob("../*.c", GLOB_DOOFFS | GLOB_APPEND, NULL, &globbuf);

	/* 设置execv 调用的参数 */
	globbuf.gl_pathv[0] = "ls";
	globbuf.gl_pathv[1] = "-l";

	/* 因为使用了offset,所以结果也要相应的偏移 */
	for (i = globbuf.gl_offs; i < globbuf.gl_pathc + globbuf.gl_offs; i++)
		printf("%s\n", globbuf.gl_pathv[i]);

	/* 巧妙的运行用之前设置的参数,这里调用exec来查看下结果 */
	execvp("ls", &globbuf.gl_pathv[0]);

	globfree(&globbuf);

	return 0;
}
