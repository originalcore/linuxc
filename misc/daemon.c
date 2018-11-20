#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/*
 * 创建一个daemon的核心
 * 调用fork,父进程退出,子进程调用setsid
 */
void daemonize(void)
{
	int fd;
	pid_t pid;

	/*
	 * Became a session leader to lose controlling TTY
	 */
	if ( (pid = fork()) < 0)
	{
		perror("fork");
		exit(1);
	}
	else if (pid != 0) /* parent */
		exit(0);

	/* Children call setsid */
	setsid();

	/*
	 * Change the curren working directory to the root
	 */
	if (chdir("/") < 0)
	{
		perror("chdir");
		exit(1);
	}

	/*
	 * Attach file descriptors 0, 1, 2 to /dev/null
	 * Every output goes to /dev/null
	 */
	close(0);
	if ((fd = open("/dev/null", O_RDWR)) != -1)
	{
        dup2(fd, STDIN_FILENO);
        dup2(fd, STDOUT_FILENO);
        dup2(fd, STDERR_FILENO);
        if (fd > STDERR_FILENO)
			close(fd);
	}
}

int main(int argc, char *argv[])
{
	daemonize();
	while (1);
}
