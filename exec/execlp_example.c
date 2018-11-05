#include <unistd.h>

int main(int argc, char *argv[])
{
	execlp("ls", "ls", "-al", "/etc/passwd", NULL);

	return 0;
}
