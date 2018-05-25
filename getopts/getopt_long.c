#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

#if 0
struct option {
	const char  *name;       /* 参数名称 */
	int          has_arg;    /* 指明是否带有参数 */
	int          *flag;      /* flag=NULL时,返回value;不为空时,*flag=val,返回0 */
	int          val;        /* 用于指定函数找到选项的返回值或flag非空时指定*flag的值 */
};
#endif

/*
 * Usage:
 * optstring r:o::n
 *
 * 看字符右边是否有":"
 * optstring 中的每一个字符都表示一个option
 * 每一个可带参数的option后面的参数叫做option argument(optarg)
 * 可带参数的选项参数保存在optarg中
 *
 * 单个字符n			表示选项n没有参数         格式:	-n即可,不加参数
 * 单字符加冒号r:		表示选项r有且必须加参数   格式:	-r 100 或 -r100,但-r=100错
 * 单字符加2冒号o::		表示选项o可以有,也可以无  格式:	-o 或 -o200
 */

/*
 * Usage:
 *
 * gopt_long --reqarg=100
 * gopt_long --reqarg 100
 * gopt_long -r100
 * gopt_long -r 100
 *
 * gopt_long -o
 * gopt_long --optarg
 * gopt_long -o200
 * gopt_long --optarg=200
 *
 * gopt_long -n
 * gopt_long --noarg
 */
int main(int argc, char *argv[])
{
    int opt;
    int option_index = 0;
    char *string = "r:o::n";

#if 0//marco in getopt.h
no_argument			(or 0) if the option does not take an argument,
required_argument	(or 1) if the option requires an argument,
optional_argument 	(or 2) if the option takes an optional argument.
#endif
    static struct option long_options[] =
    {
        {"reqarg", required_argument, NULL, 'r'},
        {"optarg", optional_argument, NULL, 'o'},
        {"noarg", no_argument,         NULL,'n'},
        {NULL,     0,                      NULL, 0},
    };

#ifdef LONG_ONLY
    while ( (opt = getopt_long_only(argc, argv, string, long_options, &option_index)) != -1 )
#else
    while ( (opt = getopt_long(argc, argv, string, long_options, &option_index)) != -1 )
#endif
    {
        printf("opt = %c\t\t", opt);
        printf("optarg = %s\t\t", optarg);
        printf("optind = %d\t\t", optind);
        printf("argv[optind] =%s\t\t", argv[optind]);
        printf("option_index = %d\n", option_index);
    }

	return 0;
}
