#include <unistd.h>

int main(int argc, char *argv[])
{
	execl("/bin/ls", "ls", "-al", "/etc/passwd", NULL);

	return 0;
}
