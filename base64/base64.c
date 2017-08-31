#include "base64.h"

/*
 * divide input raw code into 6bit per group, a 6bit groub encoding to a visible char
 * raw input 000000	000000	000000	000000 ...
 * encode     a       a        a      a
 */
int base64encode(const unsigned char *input, int input_length, unsigned char *output, int output_length)
{
	int	i = 0, j = 0;
	int	pad;

	if(output_length < (input_length * 4 / 3))
		return 0;

	while (i < input_length)
	{
		pad = 3 - (input_length - i);
		if (pad == 2)
		{
			output[j  ] = basis_64[input[i]>>2];
			output[j+1] = basis_64[(input[i] & 0x03) << 4];
			output[j+2] = '=';
			output[j+3] = '=';
		}
		else if (pad == 1)
		{
			output[j  ] = basis_64[input[i]>>2];
			output[j+1] = basis_64[((input[i] & 0x03) << 4) | ((input[i+1] & 0xf0) >> 4)];
			output[j+2] = basis_64[(input[i+1] & 0x0f) << 2];
			output[j+3] = '=';
		}
		else
		{
			output[j  ] = basis_64[input[i]>>2];
			output[j+1] = basis_64[((input[i] & 0x03) << 4) | ((input[i+1] & 0xf0) >> 4)];
			output[j+2] = basis_64[((input[i+1] & 0x0f) << 2) | ((input[i+2] & 0xc0) >> 6)];
			output[j+3] = basis_64[input[i+2] & 0x3f];
		}

		i += 3;
		j += 4;
	}

	return j;
}

int base64decode(const unsigned char *input, int input_length, unsigned char *output, int output_length)
{
	int i = 0, j = 0, pad;
	unsigned char c[4];

	if (!(output_length >= (input_length * 3 / 4)) || !((input_length % 4) == 0))
		return -1;

	while ((i + 3) < input_length)
	{
		pad  = 0;
		c[0] = char64(input[i  ]); pad += (c[0] == 0xff);
		c[1] = char64(input[i+1]); pad += (c[1] == 0xff);
		c[2] = char64(input[i+2]); pad += (c[2] == 0xff);
		c[3] = char64(input[i+3]); pad += (c[3] == 0xff);
		if (pad == 2)
		{
			output[j++] = (c[0] << 2) | ((c[1] & 0x30) >> 4);
			output[j]   = (c[1] & 0x0f) << 4;
		}
		else if (pad == 1)
		{
			output[j++] = (c[0] << 2) | ((c[1] & 0x30) >> 4);
			output[j++] = ((c[1] & 0x0f) << 4) | ((c[2] & 0x3c) >> 2);
			output[j]   = (c[2] & 0x03) << 6;
		}
		else
		{
			output[j++] = (c[0] << 2) | ((c[1] & 0x30) >> 4);
			output[j++] = ((c[1] & 0x0f) << 4) | ((c[2] & 0x3c) >> 2);
			output[j++] = ((c[2] & 0x03) << 6) | (c[3] & 0x3f);
		}
		i += 4;
	}

	return j;
}
