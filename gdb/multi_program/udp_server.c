#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>

#include "wrap.h"

#define MAXLINE 80
#define SERVER_PORT 8000

void do_something_for_client(char *buf, int bytes)
{
	int i;
	for (i = 0; i < bytes; i++)
	{
#ifdef DEBUG
		printf("%c\t", buf[i]);
#endif
		buf[i] = toupper(buf[i]);
	}
	fflush(stdout);
}

int main(int argc, char *argv[])
{
	struct sockaddr_in server_addr, client_addr;
	socklen_t client_addr_len;
	char buf[MAXLINE];
	char str[INET_ADDRSTRLEN];
	int bytes;
	int sock_fd;

	/*
	 * AF_INET for IPv4
	 * SOCK_DGRAM for UDP
	 * protocol : 0
	 */
	sock_fd = Socket(AF_INET, SOCK_DGRAM, 0);

	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(SERVER_PORT);

	/* bind fd and address (fixed address) */
	Bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

	printf("Accepting connecting...\n");
	while (1)
	{
		/* recv client requst */
		client_addr_len = sizeof(client_addr);
		bytes = recvfrom(sock_fd, buf, MAXLINE, 0, (struct sockaddr*)&client_addr, &client_addr_len);
		if (bytes == -1)
			perror("recvform error");
		printf("recv %d bytes from %s at port %d\n", bytes, inet_ntop(AF_INET, &client_addr.sin_addr, str, sizeof(str)), ntohs(client_addr.sin_port));

		/* do something for client */
		do_something_for_client(buf, bytes);

		/* answer client request */
		bytes = sendto(sock_fd, buf, bytes, 0, (struct sockaddr*)&client_addr, sizeof(client_addr));
		if (bytes == -1)
			perror("Send to error");
	}

	return 0;
}
