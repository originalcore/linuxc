# inotify and epoll

![dir and base name](../pngs/base_dir_name.png)

inotify test

	mkdir tmp
	./inotify tmp &
	echo > tmp/1
	echo > tmp/2
	rm tmp/1 tmp/2

epoll test

	mkdir tmp
	mkfifo tmp/1 tmp/2 tmp/3
	./epoll tmp/1 tmp/2 tmp/3 &
	echo aaa > tmp/1
	echo bbb > tmp/2

inotify and epoll test

	mkdir tmp
	./inotify_epoll tmp/ &
	mkfifo tmp/1 tmp/2 tmp/3
	echo aaa > tmp/1
	echo bbb > tmp/2
	rm tmp/3

inotify_example /tmp /home/user/temp

	Press enter key to terminate.
	Listening for events.
	IN_OPEN: /home/user/temp/foo [file]
	IN_CLOSE_WRITE: /home/user/temp/foo [file]
	IN_OPEN: /tmp/ [directory]
	IN_CLOSE_NOWRITE: /tmp/ [directory]

	Listening for events stopped.
