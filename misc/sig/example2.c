#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

/*
 * 收到SIGINT后, 进入sig_handler,此时发送SIGTERM信号将被屏蔽,
 * 等sig_handler返回后, 才收到SIGTERM信号, 然后退出程序
 */
void sig_handler(int signum)
{
    printf("in handle, SIGTERM is blocked\n");
    /* 在此handler内将屏蔽掉SIGTERM, 直到此handler返回 */
    printf("--> send SIGTERM -->\n");
    kill(getpid(), SIGTERM);
    sleep(5);
    printf("handle done\n");
}

void handle_term(int signum)
{
    printf("catch sigterm and exit..\n");
    exit(0);
}

int main(int argc, char **argv)
{
    struct sigaction action, old_action;

    /* 设置SIGINT */
    action.sa_handler = sig_handler;
    sigemptyset(&action.sa_mask);

    /*
	 * 安装handler的时候, 设置在handler
     * 执行期间, 屏蔽掉SIGTERM信号
	 */
    sigaddset(&action.sa_mask, SIGTERM);
    action.sa_flags = 0;

    sigaction(SIGINT, NULL, &old_action);
    if (old_action.sa_handler != SIG_IGN) {
        sigaction(SIGINT, &action, NULL);
    }

    /* 设置SIGTERM */
    action.sa_handler = handle_term;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    sigaction(SIGTERM, NULL, &old_action);
    if (old_action.sa_handler != SIG_IGN) {
        sigaction(SIGTERM, &action, NULL);
    }

    printf("--> send SIGINT -->\n");
    kill(getpid(), SIGINT);

    while (1) {
        sleep(1);
    }

    return 0;
}
