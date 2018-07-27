#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int cnt = 0;

void cnt_reset(void)
{
	pthread_mutex_lock(&mutex);
	cnt = 0;
	pthread_mutex_unlock(&mutex);
}

void *start_routine(void *arg)
{
	while (1)
	{
		pthread_mutex_lock(&mutex);
		if (cnt > 2)
			cnt_reset();
		else
			cnt++;
		pthread_mutex_unlock(&mutex);

		printf("cnt = %d\n", cnt);
		sleep(1);
	}
}

int main(int argc, char *argv[])
{
	pthread_t tid;

	pthread_create(&tid, NULL, start_routine, NULL);
	pthread_join(tid, NULL);

	return EXIT_SUCCESS;
}

