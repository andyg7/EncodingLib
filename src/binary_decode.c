#include <stdio.h>
#include <stdlib.h>
#include "bit_ops.h"

int encode_binary(char *input, char *output, int num_bytes)
{
	for (int i = 0; i < num_bytes; i++) {
		char curr_char = *(input + i);
		for (int j = 0; j < 8; j++) {
			int output_index = (i * 8) + j;
			int b = get_bit(curr_char, j);
			if (b == 0) {
				*(output + output_index) = '0';
			} else if (b == 1) {
				*(output + output_index) = '1';
			} else {
				return -1;
			}
		}
	}
	return 0;
}
