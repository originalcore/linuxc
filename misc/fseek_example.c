#include <stdio.h>
#include <stdlib.h>

/*
 * 创建一个4个字节大小的文件内容为"5678"
 * echo '5678' > textfile
 *
 * 使用od查看文件内容
 * od -tx1 -tc -Ax textfile
 *
 * -tx1 输出按一个字节排列
 * -tc 输出字符
 * -Ax 输出地址
 */
int main(int argc, char *argv[])
{
	FILE *fp;

	if ( (fp = fopen("textfile", "r+")) == NULL)
	{
		perror("Open textfile error");
		printf("try echo '5678' > textfile\n");
		exit(1);
	}

	/*
	 * 将文件指针设置到第10个字节
	 * 因为是从0开始数,所以是第11个字节
	 * 这也textfile的文件大小就变大了
	 */
	if (fseek(fp, 10, SEEK_SET) != 0)
	{
		perror("Fseek textfile error");
		exit(1);
	}

	/* 在第11给字节的地方写字符'K' */
	fputc('K', fp);
	fclose(fp);

	return 0;
}
