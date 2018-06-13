#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

/*
 * optind is the index of the next element to be processed in argv
 */

/*
 * Usage:
 * optstring a::b:c:d
 *
 * 看字符右边是否有":"
 * 字符右边无冒号,无参数
 * 字符右边有一个冒号,必须有参数
 * 字符右边有二个冒号,参数可有可无
 *
 * optstring 中的每一个字符都表示一个option
 * 每一个可带参数的option后面的参数叫做option argument(optarg)
 * 可带参数的选项参数保存在optarg中
 *
 * 单个字符d			表示选项d没有参数         格式:	-d即可,不加参数
 * 单字符加冒号b:		表示选项b有且必须加参数   格式:	-b 100 或 -b100,但-b=100错
 * 单字符加冒号c:		表示选项c有且必须加参数   格式:	-c 100 或 -c100,但-c=100错
 * 单字符加2冒号a::		表示选项a可以有,也可以无  格式:	-a 或 -a200
 */

/*
 * optarg 指向当前选项参数(如果有)的指针
 * optind 再次调用 getopt() 时的下一个argv指针的索引
 * optopt 最后一个未知选项
 * opterr 如果不希望getopt()打印出错信息,则只要将全域变量opterr设为0即可
 */
int main(int argc, char *argv[])
{
    int opt;
    char *string = "a::b:c:d";

    while ( (opt = getopt(argc, argv, string)) != -1 )
    {
        printf("opt = %c\t\t", opt);
        printf("optarg = %s\t\t", optarg);
        printf("optind = %d\t\t", optind);
        printf("argv[optind] = %s\n", argv[optind]);
    }

	return 0;
}
