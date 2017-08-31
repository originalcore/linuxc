#include <stdio.h>
#include <string.h>
#include "base64.h"

int main(int argc, char *argv[])
{
	const unsigned char input[] = "Yep.this_is_a_secret!!";
	unsigned char en_output[1024];
	unsigned char de_output[1024];
	int ret;

	/* print out the raw code */
	printf("raw code : %s\n", input);

	/* base64 encoding */
	ret = base64encode(input, strlen(input), en_output, sizeof(en_output));
	en_output[ret] = '\0';
	printf("encoding : %s\n", en_output);

	/* base64 decoding */
	ret = base64decode(en_output, strlen(en_output), de_output, sizeof(de_output));
	de_output[strlen(en_output)] = '\0';
	printf("decoding : %s\n", de_output);

	return 0;
}
