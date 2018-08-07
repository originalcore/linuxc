#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include "wrap.h"

void perr_exit(const char *s)
{
	perror(s);
	exit(1);
}

int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
	int afd;

again:
	if ( (afd= accept(fd, sa, salenptr)) < 0)
	{
		if ( (errno == ECONNABORTED) || (errno == EINTR) )
			goto again;
		else
			perr_exit("accept error");
	}

	return afd;
}

void Bind(int fd, struct sockaddr *sa, socklen_t salen)
{
	if (bind(fd, sa, salen) < 0)
		perr_exit("Bind error");
}

void Connect(int fd, struct sockaddr *sa, socklen_t salen)
{
	if (connect(fd, sa, salen) < 0)
		perr_exit("Connect error");
}

void Listen(int fd, int backlog)
{
	if (listen(fd, backlog) < 0)
		perr_exit("Listen error");
}

int Socket(int family, int type, int protocol)
{
	int ret;

	if ( (ret = socket(family, type, protocol)) < 0 )
		perr_exit("Socket error");

	return ret;
}

ssize_t Read(int fd, void *ptr, size_t nbytes)
{
	ssize_t bytes;
again:
	if ( (bytes = read(fd, ptr, nbytes)) == -1)
	{
		if (errno == EINTR)
			goto again;
		else
			return bytes;
	}

	return bytes;
}

ssize_t Write(int fd, const void *ptr, size_t nbytes)
{
again:
	if ( (nbytes = write(fd, ptr, nbytes)) == -1)
	{
		if (errno == EINTR)
			goto again;
		else
			return nbytes;
	}

	return nbytes;
}

void Close(int fd)
{
	if (close(fd) == -1)
		perr_exit("Close error");
}

/* 读固定长度 */
ssize_t Readn(int fd, void *vptr, size_t nbytes)
{
	size_t nleft;
	ssize_t nread;
	char *ptr;

	ptr = vptr;
	nleft = nbytes;

	while (nleft > 0)
	{
		if ( (nread = read(fd, ptr, nleft)) < 0)
		{
			if (errno == EINTR)
				nread = 0;
			else
				return -1;
		}

		nleft -= nread;
		ptr += nread;
	}

	return nbytes - nleft;
}

ssize_t Writen(int fd, const void *vptr, size_t nbytes)
{
	size_t nleft;
	ssize_t nwritten;
	const char *ptr;

	ptr = vptr;
	nleft = nbytes;

	while (nleft > 0)
	{
		if ( (nwritten = write(fd, ptr, nleft)) <= 0)
		{
			if (nwritten < 0 && errno == EINTR)
				nwritten = 0;
			else
				return -1;
		}

		nleft -= nwritten;
		ptr += nwritten;
	}

	return nbytes;
}
