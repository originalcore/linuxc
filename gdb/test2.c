#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

int count = 0;

/* how can't gdb backtrace printout this functino? */
void just_printout_msg(void)
{
	int i, j;

	/* do a dummy thing, don't care */
	for (i = 0; i < 10; i++)
		j = i;

	printf("Oops..., something terriable will happen!!\n");
}

void *error_maker(void *args)
{
	char *str = NULL;

    while (1)
    {
        sleep(1);

        if (NUM_THREADS == count)
        {
			just_printout_msg();
            *str = 'x';
        }
    }
}

int main(int argc, char *argv[])
{
	int i, ret;

    pthread_t tids[NUM_THREADS];

    for (i = 0; i < NUM_THREADS; ++i)
    {
        count = i + 1;
        ret = pthread_create(&tids[i], NULL, error_maker, NULL);
        if(ret != 0)
        {
			perror("create thread error\n");
			return -1;
        }
    }

    pthread_exit( NULL );
}
