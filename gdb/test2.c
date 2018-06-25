#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 2

void error_maker(void)
{
	char *str = NULL;

	printf("Oops..., something terriable will happen!!\n");

	*str = 'x';
}

void *start_routine(void *args)
{
	int cnt;

	cnt = *(int *)args;

	while (1)
	{
		sleep(4);
		printf("pid %d, cnt = %d\n", getpid(), cnt);

		if (NUM_THREADS == cnt)
			error_maker();
	}
}

int main(int argc, char *argv[])
{
	int i, ret;
	int value;

    pthread_t tids[NUM_THREADS];

    for (i = 0; i < NUM_THREADS; i++)
    {
		printf("i = %d\n", i);
		value = i + 1;
        ret = pthread_create(&tids[i], NULL, start_routine, &value);
        if (ret != 0)
        {
			perror("create thread error\n");
			return -1;
        }
    }

    //pthread_exit( NULL );
	for (i = 0; i < NUM_THREADS; i++)
		pthread_join(tids[i], NULL);
}
