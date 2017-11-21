#include <stdio.h>
#include <stdlib.h>
#include "hex_decode.h"
#include "bit_ops.h"

char hex_table[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int encode_hex(char *input, char *output, int num_bytes)
{
	for (int i = 0; i < num_bytes; i++) {
		char curr_char = *(input + i);
		char first_hex_char = get_most_sig_half(curr_char);
		char second_hex_char = get_least_sig_half(curr_char);
		int first_hex_index = i * 2;
		int second_hex_index = (i * 2) + 1;
		*(output + first_hex_index) = first_hex_char;
		*(output + second_hex_index) = second_hex_char;
	}
	return 0;
}

int decode_hex(char *input, char *output, int num_bytes)
{
	for (int i = 0; i < num_bytes; i++) {
		char curr_char = *(input + i);
		unsigned char val = (unsigned char) get_decimal_value(curr_char);
		int char_index = i / 2;
		if (i % 2 == 0) {
			set_most_sig_half((unsigned char *) output + char_index, val);
		} else {
			set_least_sig_half((unsigned char *) output + char_index, val);
		}
	}
	return 0;
}

int get_most_sig_half(char c)
{
	unsigned char t = 0;
	int t_index = 0;
	for (int i = 4; i < 8; i++) {
		int b = get_bit(c, i);
		set_bit(&t, b, t_index);
		t_index++;
	}
	return hex_table[t];
}

int get_least_sig_half(char c)
{
	unsigned char t = 0;
	int t_index = 0;
	for (int i = 0; i < 4; i++) {
		int b = get_bit(c, i);
		set_bit(&t, b, t_index);
		t_index++;
	}
	return hex_table[t];
}

int get_decimal_value(char c)
{
	int hex_table_len = sizeof(hex_table) / sizeof(char);
	for (int i = 0; i < hex_table_len; i++) {
		if (hex_table[i] == c) {
			return i;
		}
	}
	return -1;
}

int set_most_sig_half(unsigned char *c, unsigned char v)
{
	int c_index = 4;
	for (int i = 0; i < 4; i++) {
		int b = get_bit(v, i);
		set_bit(c, b, c_index);
		c_index++;
	}
	return 0;
}

int set_least_sig_half(unsigned char *c, unsigned char v)
{
	int c_index = 0;
	for (int i = 0; i < 4; i++) {
		int b = get_bit(v, i);
		set_bit(c, b, c_index);
		c_index++;
	}
	return 0;
}
