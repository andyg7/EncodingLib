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

int decode_binary(char *input, char *output, int num_bytes)
{
	if (num_bytes % 8 != 0) {
		printf("%d %s\n", num_bytes, " is not a multiple of 8. Can't decode binary file");
		return -1;
	}
	int curr_output_char_index = 0; 
	char *curr_output_char = output + curr_output_char_index;
	for (int i = 0; i < num_bytes; i++) {
		char t = *(input + i);
		if (t == '0') {
			set_bit((unsigned char *) curr_output_char, 0, i % 8);
		} else {
			set_bit((unsigned char *) curr_output_char, 1, i % 8);
		}
		if (i == 7) {
			curr_output_char_index++;
			curr_output_char = output + curr_output_char_index;
		}
	}
	return 0;
}
