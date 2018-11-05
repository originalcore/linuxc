#include <unistd.h>

int main(int argc, char *argv[])
{
	const char *path = "/usr/bin/env";
	char *const envp[] ={"PATH=/bin:/usr/bin", "EDITOR=emacs", NULL};
	char *const args[] = {"env", NULL};

	execve(path, args, envp);

	return 0;
}
