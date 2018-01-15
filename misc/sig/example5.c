#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <setjmp.h>

void sig_alrm(int signum);
void sig_usr1(int signum);
void print_mask(const char *str);

static sigjmp_buf jmpbuf;
static volatile sig_atomic_t canjmp;
static int sigalrm_appear;

int main(int argc, char **argv)
{
    struct sigaction action, old_action;

    /* 设置SIGUSR1 */
    action.sa_handler = sig_usr1;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    sigaction(SIGUSR1, NULL, &old_action);
    if (old_action.sa_handler != SIG_IGN) {
        sigaction(SIGUSR1, &action, NULL);
    }

    /* 设置SIGALRM */
    action.sa_handler = sig_alrm;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    sigaction(SIGALRM, NULL, &old_action);
    if (old_action.sa_handler != SIG_IGN) {
        sigaction(SIGALRM, &action, NULL);
    }

    print_mask("starting main:");

    if (sigsetjmp(jmpbuf, 1) != 0) {
        print_mask("exiting main:");
    } else {
        printf("sigsetjmp return directly\n");
        canjmp = 1;
        while (1) {
            sleep(1);
        }
    }

    return 0;
}

void sig_usr1(int signum)
{
    time_t starttime;
    if (canjmp == 0) {
        printf("please set jmp first\n");
        return;
    }

    print_mask("in sig_usr1:");

    alarm(1);
    while (!sigalrm_appear);
    canjmp = 0;
    siglongjmp(jmpbuf, 1);
}

void sig_alrm(int signum)
{
    print_mask("in sig_alrm:");
    sigalrm_appear = 1;

    return;
}

void print_mask(const char *str)
{
    sigset_t sigset;
    int i, errno_save, flag = 0;

    errno_save = errno;

    if (sigprocmask(0, NULL, &sigset) < 0) {
        printf("sigprocmask error\n");
        exit(0);
    }

    printf("%s\n", str);
    fflush(stdout);

    for (i = 1; i < NSIG; i++) {
        if (sigismember(&sigset, i)) {
            flag = 1;
            psignal(i, "a blocked signal");
        }
    }

    if (!flag) {
        printf("no blocked signal\n");
    }

    printf("\n");
    errno = errno_save;
}
