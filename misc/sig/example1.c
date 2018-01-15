#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

/*
 * 这里发送了两次SIGINT信号 可以看到, 屏蔽掉SIGINT后,
 * 信号无法递送, 解除屏蔽后, 才递送信号, 但只被递送一次,
 * 因为SIGINT是非可靠信号, 不支持排队.
 */

void sig_handler(int signum)
{
    printf("catch SIGINT\n");
}

int main(int argc, char *argv[])
{
    sigset_t block;
    struct sigaction action, old_action;

    /* 安装信号 */
    action.sa_handler = sig_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    sigaction(SIGINT, NULL, &old_action);
    if (old_action.sa_handler != SIG_IGN) {
        sigaction(SIGINT, &action, NULL);
    }

    /* 屏蔽信号 */
    sigemptyset(&block);
    sigaddset(&block, SIGINT);

    printf("block SIGINT\n");
    sigprocmask(SIG_BLOCK, &block, NULL);

    printf("--> send SIGINT -->\n");
    kill(getpid(), SIGINT);
    printf("--> send SIGINT -->\n");
    kill(getpid(), SIGINT);
    sleep(1);

    /*
	 * 解除信号后, 之前触发的信号将被递送,
     * 但SIGINT是非可靠信号, 只会递送一次
     */
    printf("unblock SIGINT\n");
    sigprocmask(SIG_UNBLOCK, &block, NULL);

    sleep(2);

    return 0;
}
