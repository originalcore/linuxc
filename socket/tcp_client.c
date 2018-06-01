#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 80
#define SERVER_PORT 8000

int main(int argc, char *argv[])
{
	struct sockaddr_in dest_addr;
	char buf[MAXLINE];
	int sock_fd;
	int bytes;
	char *str;
	char *target_ip;

	if (argc != 3)
	{
		printf("Usage : %s <target ip> <message>\n", argv[0]);
		exit(1);
	}

	str = argv[2];
	target_ip = argv[1];

	sock_fd = socket(AF_INET, SOCK_STREAM, 0);

	/* destination address */
	bzero(&dest_addr, sizeof(dest_addr));
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons(SERVER_PORT);
	inet_pton(AF_INET, target_ip, &dest_addr.sin_addr);

	/* connect server */
	connect(sock_fd, (struct sockaddr *)&dest_addr, sizeof(dest_addr));

#ifdef USE_RW
	/* send request to server */
	bytes = write(sock_fd, str, strlen(str));

	/* recv the answer from server */
	bytes = read(sock_fd, buf, MAXLINE);
#else
	/* send request to server */
	bytes = sendto(sock_fd, str, strlen(str), 0, (struct sockaddr*)&dest_addr, sizeof(dest_addr));

	/* recv the answer from server */
	struct sockaddr_in recv_addr;
	socklen_t addrlen = sizeof(recv_addr);
	bzero(&recv_addr, sizeof(recv_addr));

	bytes = recvfrom(sock_fd, buf, MAXLINE, 0, (struct sockaddr*)&recv_addr, &addrlen);
#endif
	buf[bytes] = '\0';
	printf("Response from serve %s\n", buf);

	close(sock_fd);

	return 0;
}
