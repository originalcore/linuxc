#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

/*
 * No restart flag
 * 在read 等待数据期间, 按下ctrl + c, 触发 SIGINT 信号,
 * handler 返回后, read 被中断, 返回 -1
 *
 * define restart flag
 * handler 返回后, read 系统调用被恢复执行, 继续等待数据.
 */
void sig_handler(int signum)
{
    printf("in handler\n");
    sleep(1);
    printf("handler return\n");
}

int main(int argc, char **argv)
{
    char buf[100];
    int ret;
    struct sigaction action, old_action;

    action.sa_handler = sig_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    /*
	 * 版本1:不设置SA_RESTART属性
     * 版本2:设置SA_RESTART属性
	 */
#ifdef RESTART_FLAG
    action.sa_flags |= SA_RESTART;
#endif

    sigaction(SIGINT, NULL, &old_action);
    if (old_action.sa_handler != SIG_IGN) {
        sigaction(SIGINT, &action, NULL);
    }

    bzero(buf, 100);

    ret = read(0, buf, 100);
    if (ret == -1) {
        perror("read");
    }

    printf("read %d bytes:\n", ret);
    printf("%s\n", buf);

    return 0;
}
