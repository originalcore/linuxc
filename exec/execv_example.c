#include <unistd.h>

int main(int argc, char *argv[])
{
	const char *path = "/bin/ls";
	char *const args[] = {"ls", "-al", "/etc/passwd", NULL};
	execv(path, args);

	return 0;
}
