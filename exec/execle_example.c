#include <unistd.h>

int main(int argc, char *argv[])
{
	char *const envp[] ={"PATH=/bin:/usr/bin", "EDITOR=emacs", NULL};
	execle("/usr/bin/env", "env", NULL, envp);

	return 0;
}
