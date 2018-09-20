#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include "base64.h"

#define ENCODE_BUFFER_LEN 1024

int main(int argc, char *argv[])
{
	unsigned char en_output[ENCODE_BUFFER_LEN];
	int len_input; /* length of input string */
	int len_output; /* output length should equal to or longer than input length */
	int len_encode; /* length of encode string */
	int len_decode; /* length of decode string */
	unsigned char *de_output;

	if (argc < 2)
	{
		printf("%s <string>\n", argv[0]);
		return -1;
	}

	/* print out the raw code */
	printf("raw code : %s\n", argv[1]);

	/* encode will longer the stirng */
	/* each 3 bytes encode to 4 bytes */
	assert(strlen((const char *)argv[1]) < ENCODE_BUFFER_LEN * 4 / 3);
	len_input = strlen((const char *)argv[1]);

	/* base64 encoding */
	len_encode = base64encode((const unsigned char *)argv[1], len_input, en_output, sizeof(en_output));
	en_output[len_encode] = '\0';
	printf("encoding : %s\n", en_output);

	/* malloc buffer for output string */
	if (len_input < len_encode * 4 / 3)
		len_output = len_encode * 4 / 3;
	else
		len_output = len_input;

	de_output = malloc(len_output * sizeof(char) + 1);
	if (NULL == de_output)
	{
		perror("Malloc error");
		return -2;
	}

	/* base64 decoding */
	len_decode = base64decode(en_output, strlen((const char *)en_output), de_output, len_output);
	de_output[len_decode] = '\0';
	printf("decoding : %s\n", de_output);

	free(de_output);

	return 0;
}
