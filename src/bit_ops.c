#include <stdio.h>
#include <stdlib.h>
#include "bit_ops.h"

int get_bit(unsigned char c, int p)
{
	if (p < 0 || p > 7) {
		return -1;
	}
	unsigned char mask = 1 << p;
	unsigned char masked = c & mask;
	if (masked == 0) {
		return 0;
	} else {
		return 1;
	}
}

int set_bit(unsigned char *c, int b, int p)
{
	if (b != 1 && b != 0) {
		return -1;
	}
	if (p < 0 || p > 7) {
		return -1;
	}

	unsigned char mask = ~(1 << p);
	unsigned char c_zero_in_bit = (*c) & mask;
	unsigned char b_pushed = b << p;
	*c = (c_zero_in_bit | b_pushed);
	return 0;
}

void print_binary(unsigned char c)
{
	unsigned char s[9];
	for (int i = 0; i < 8; i++) {
		s[i] = '0';
	}
	s[8] = '\0';
	for (int i = 0; i < 8; i++) {
		int b = get_bit(c, i);
		if (b == 1) {
			s[7 - i] = '1';
		} else {
			s[7 - i] = '0';
		}
	}
	printf("%s\n", s);
}

int get_value(unsigned char *c)
{
	int sum_so_far = 0;
	for (int i = 0; i < 8; i++) {
		char curr_char = *(c + i);
		int b = get_bit(curr_char, i);
		if (b == 1) {
			sum_so_far = sum_so_far + (2 ^ i);
		}
	}
	return sum_so_far;
}
