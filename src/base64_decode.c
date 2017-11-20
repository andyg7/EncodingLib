#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "base64_decode.h"
#include "bit_ops.h"

char base64_table[64] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', 'k'};

int MAX_STRING_LEN = 100;

int encode_base64(char *input, char *output, int num_bytes)
{
	int front = 0;
	int back = 2;
	int output_index = 0;
	while (back < num_bytes) {
		unsigned char char_0 = *(input + front);
		unsigned char char_1 = *(input + front + 1);
		unsigned char char_2 = *(input + front + 2);
		int val_bits_0 = extract_front(char_0);
		int val_bits_1 = extract_mid_to_back(char_0, char_1);
		int val_bits_2 = extract_back_to_mid(char_1, char_2);
		int val_bits_3 = extract_back(char_2);

		*(output + output_index) = get_char(val_bits_0);
		*(output + output_index + 1) = get_char(val_bits_1);
		*(output + output_index + 2) = get_char(val_bits_2);
		*(output + output_index + 3) = get_char(val_bits_3);
		front = front + 3;
		back = back + 3;
		output_index = output_index + 4;
	}
	if (num_bytes % 3 == 0) {
		return 0;
	}

	unsigned char char_0 = *(input + front);
	int val_bits_0 = extract_front(char_0);
	*(output + output_index) = get_char(val_bits_0);

	if (num_bytes % 3 == 1) {
		int val_bits_1 = extract_mid_to_back(char_0, 0);
		*(output + output_index + 1) = get_char(val_bits_1);
		*(output + output_index + 2) = '=';
		*(output + output_index + 3) = '=';
	} else {
		unsigned char char_1 = *(input + front + 1);
		int val_bits_1 = extract_mid_to_back(char_0, char_1);
		*(output + output_index + 1) = get_char(val_bits_1);
		int val_bits_2 = extract_back_to_mid(char_1, 0);
		*(output + output_index + 2) = get_char(val_bits_2);
		*(output + output_index + 3) = '=';

	}
	return 0;
}

int decode_base64(char *input, char *output, int num_bytes)
{
	char char_index = 0;
	int bit_index = 7;
	for (int i = 0; i < num_bytes; i++) {
		char curr = *(input + i);
		if (curr == '=') {
			break;
		}
		int val = get_index(curr);
		for (int j = 5; j >= 0; j--) {
			int b = get_bit((unsigned char) val, j);
			set_bit((unsigned char *) output + char_index, b, bit_index);
			bit_index--;
			if (bit_index < 0) {
				bit_index = 7;
				char_index++;
			}
		}
	}
	return 0;
}

int get_index(char c)
{
	int array_len = sizeof(base64_table) / sizeof(base64_table[0]);
	for (int i = 0; i < array_len; i++) {
		if (base64_table[i] == c) {
			return i;
		}
	}
	return -1;
}

char get_char(int i)
{
	return base64_table[i];
}

unsigned char extract_front(unsigned char c)
{
	unsigned char t = 0;	
	int t_next_index = 0;
	for (int i = 2; i < 8; i++) {
		int b = get_bit(c, i);
		set_bit(&t, b, t_next_index);
		t_next_index++;
	}
	return t;
}

unsigned char extract_mid_to_back(unsigned char c, unsigned char d)
{
	unsigned char t = 0;	
	int t_next_index = 0;
	for (int i = 4; i < 8; i++) {
		int b = get_bit(d, i);
		set_bit(&t, b, t_next_index);
		t_next_index++;
	}
	for (int i = 0; i < 2; i++) {
		int b = get_bit(c, i);
		set_bit(&t, b, t_next_index);
		t_next_index++;
	}
	return t;
}

unsigned char extract_back_to_mid(unsigned char c, unsigned char d)
{
	unsigned char t = 0;	
	int t_next_index = 0;
	for (int i = 6; i < 8; i++) {
		int b = get_bit(d, i);
		set_bit(&t, b, t_next_index);
		t_next_index++;
	}
	for (int i = 0; i < 4; i++) {
		int b = get_bit(c, i);
		set_bit(&t, b, t_next_index);
		t_next_index++;
	}
	return t;
}

unsigned char extract_back(unsigned char c)
{
	unsigned char t = 0;
	int t_next_index = 0;
	for (int i = 0; i < 6; i++) {
		int b = get_bit(c, i);
		set_bit(&t, b, t_next_index);
		t_next_index++;
	}
	return t;
}

int base64_num_bytes(int binary_num_bytes)
{
	int needed_bytes = 4 * (binary_num_bytes / 3);
	if (binary_num_bytes % 3 != 0) {
		needed_bytes += 4;
	}
	return needed_bytes;
}

int binary_num_bytes(char *base64_text, int base64_num_bytes)
{
	if (*(base64_text + base64_num_bytes - 1) != '=') {
		int num_bytes = (base64_num_bytes * 3) / 4;
		return num_bytes;
	}
	if (*(base64_text + base64_num_bytes - 2) == '=') {
		int num_bytes = (base64_num_bytes * 3) / 4;
		num_bytes = num_bytes - 2;
		return num_bytes;
	} else {
		int num_bytes = (base64_num_bytes * 3) / 4;
		num_bytes = num_bytes - 1;
		return num_bytes;
	}
}
