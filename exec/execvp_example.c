#include <unistd.h>

int main(int argc, char *argv[])
{
	const char *path = "ls";
	char *const args[] = {"ls", "-al", "/etc/passwd", NULL};
	execvp(path, args);

	return 0;
}
