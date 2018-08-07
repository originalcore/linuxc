#ifndef _WRAP_H_
#define _WRAP_H_
int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);
void Bind(int fd, struct sockaddr *sa, socklen_t salen);
void Connect(int fd, struct sockaddr *sa, socklen_t salen);
void Listen(int fd, int backlog);
int Socket(int family, int type, int protocol);
ssize_t Read(int fd, void *ptr, size_t nbytes);
ssize_t Write(int fd, const void *ptr, size_t nbytes);
void Close(int fd);
ssize_t Readn(int fd, void *vptr, size_t nbytes);
ssize_t Writen(int fd, const void *vptr, size_t nbytes);
#endif
