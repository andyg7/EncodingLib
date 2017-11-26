#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "base64_decode.h"
#include "hex_decode.h"
#include "binary_decode.h"

int base64_encode_file(char *input_file_name, char *output_file_name)
{
	FILE *fi = fopen(input_file_name, "r");	
	FILE *fo = fopen(output_file_name, "w+");	

	int INPUT_BUF_NUM_BYTES = 12;
	char input_buf[INPUT_BUF_NUM_BYTES + 1];
	input_buf[INPUT_BUF_NUM_BYTES] = '\0';

	int OUTPUT_BUF_NUM_BYTES = base64_num_bytes(INPUT_BUF_NUM_BYTES);
	char output_buf[OUTPUT_BUF_NUM_BYTES + 1];
	output_buf[OUTPUT_BUF_NUM_BYTES] = '\0';

	int eof = 0;
	while (eof == 0) {
		memset(input_buf, 0, INPUT_BUF_NUM_BYTES);
		memset(output_buf, 0, OUTPUT_BUF_NUM_BYTES);

		int bytes_read = fread(input_buf, sizeof(char), INPUT_BUF_NUM_BYTES, fi);
		if (bytes_read < INPUT_BUF_NUM_BYTES) {
			eof = 1;
		}
		encode_base64(input_buf, output_buf, bytes_read);
		int bytes_to_write = base64_num_bytes(bytes_read);
		fwrite(output_buf, sizeof(char), bytes_to_write, fo);
	}

	fclose(fi);
	fclose(fo);
	return 0;
}

int base64_decode_file(char *input_file_name, char *output_file_name)
{
	FILE *fi = fopen(input_file_name, "r");	
	FILE *fo = fopen(output_file_name, "w+");	

	int INPUT_BUF_NUM_BYTES = 12;
	char input_buf[INPUT_BUF_NUM_BYTES + 1];
	input_buf[INPUT_BUF_NUM_BYTES] = '\0';

	int OUTPUT_BUF_NUM_BYTES = INPUT_BUF_NUM_BYTES;
	char output_buf[OUTPUT_BUF_NUM_BYTES + 1];
	output_buf[OUTPUT_BUF_NUM_BYTES] = '\0';

	int eof = 0;
	while (eof == 0) {
		memset(input_buf, 0, INPUT_BUF_NUM_BYTES);
		memset(output_buf, 0, OUTPUT_BUF_NUM_BYTES);

		int bytes_read = fread(input_buf, sizeof(char), INPUT_BUF_NUM_BYTES, fi);
		if (bytes_read < INPUT_BUF_NUM_BYTES) {
			eof = 1;
		}
		decode_base64(input_buf, output_buf, bytes_read);
		int bytes_to_write = binary_num_bytes(input_buf, strnlen(input_buf, 1000));
		fwrite(output_buf, sizeof(char), bytes_to_write, fo);
	}

	fclose(fi);
	fclose(fo);
	return 0;

	return 0;
}

int hex_encode_file(char *input_file_name, char *output_file_name)
{
	FILE *fi = fopen(input_file_name, "r");	
	FILE *fo = fopen(output_file_name, "w+");	

	int INPUT_BUF_NUM_BYTES = 12;
	char input_buf[INPUT_BUF_NUM_BYTES + 1];
	input_buf[INPUT_BUF_NUM_BYTES] = '\0';

	int OUTPUT_BUF_NUM_BYTES = (INPUT_BUF_NUM_BYTES * 2) + 1;
	char output_buf[OUTPUT_BUF_NUM_BYTES + 1];
	output_buf[OUTPUT_BUF_NUM_BYTES] = '\0';

	int eof = 0;
	while (eof == 0) {
		memset(input_buf, 0, INPUT_BUF_NUM_BYTES);
		memset(output_buf, 0, OUTPUT_BUF_NUM_BYTES);

		int bytes_read = fread(input_buf, sizeof(char), INPUT_BUF_NUM_BYTES, fi);
		if (bytes_read < INPUT_BUF_NUM_BYTES) {
			eof = 1;
		}
		encode_hex(input_buf, output_buf, bytes_read);
		int bytes_to_write = bytes_read * 2;
		fwrite(output_buf, sizeof(char), bytes_to_write, fo);
	}

	fclose(fi);
	fclose(fo);
	return 0;
}

int hex_decode_file(char *input_file_name, char *output_file_name)
{
	FILE *fi = fopen(input_file_name, "r");	
	FILE *fo = fopen(output_file_name, "w+");	

	int INPUT_BUF_NUM_BYTES = 12;
	char input_buf[INPUT_BUF_NUM_BYTES + 1];
	input_buf[INPUT_BUF_NUM_BYTES] = '\0';

	int OUTPUT_BUF_NUM_BYTES = INPUT_BUF_NUM_BYTES;
	char output_buf[OUTPUT_BUF_NUM_BYTES + 1];
	output_buf[OUTPUT_BUF_NUM_BYTES] = '\0';

	int eof = 0;
	while (eof == 0) {
		memset(input_buf, 0, INPUT_BUF_NUM_BYTES);
		memset(output_buf, 0, OUTPUT_BUF_NUM_BYTES);

		int bytes_read = fread(input_buf, sizeof(char), INPUT_BUF_NUM_BYTES, fi);
		if (bytes_read < INPUT_BUF_NUM_BYTES) {
			eof = 1;
		}
		decode_hex(input_buf, output_buf, bytes_read);
		int bytes_to_write = bytes_read / 2;
		fwrite(output_buf, sizeof(char), bytes_to_write, fo);
	}

	fclose(fi);
	fclose(fo);
	return 0;

	return 0;
}

int binary_encode_file(char *input_file_name, char *output_file_name)
{
	FILE *fi = fopen(input_file_name, "r");	
	FILE *fo = fopen(output_file_name, "w+");	

	int INPUT_BUF_NUM_BYTES = 1;
	char input_buf[INPUT_BUF_NUM_BYTES + 1];
	input_buf[INPUT_BUF_NUM_BYTES] = '\0';

	int OUTPUT_BUF_NUM_BYTES = (INPUT_BUF_NUM_BYTES * 8);
	char output_buf[OUTPUT_BUF_NUM_BYTES + 1];
	output_buf[OUTPUT_BUF_NUM_BYTES] = '\0';

	char space[2] = {' ', '\0'};
	int eof = 0;
	int interation = 0;
	while (eof == 0) {
		memset(input_buf, 0, INPUT_BUF_NUM_BYTES);
		memset(output_buf, 0, OUTPUT_BUF_NUM_BYTES);

		int bytes_read = fread(input_buf, sizeof(char), INPUT_BUF_NUM_BYTES, fi);
		if (bytes_read < INPUT_BUF_NUM_BYTES) {
			eof = 1;
		}
		encode_binary(input_buf, output_buf, bytes_read);
		int bytes_to_write = bytes_read * 8;
		fwrite(output_buf, sizeof(char), bytes_to_write, fo);
		interation++;
	}

	fclose(fi);
	fclose(fo);
	return 0;
}

int binary_decode_file(char *input_file_name, char *output_file_name)
{
	FILE *fi = fopen(input_file_name, "r");	
	FILE *fo = fopen(output_file_name, "w+");	

	int INPUT_BUF_NUM_BYTES = 8;
	char input_buf[INPUT_BUF_NUM_BYTES + 1];
	input_buf[INPUT_BUF_NUM_BYTES] = '\0';

	int OUTPUT_BUF_NUM_BYTES = INPUT_BUF_NUM_BYTES;
	char output_buf[OUTPUT_BUF_NUM_BYTES + 1];
	output_buf[OUTPUT_BUF_NUM_BYTES] = '\0';

	int eof = 0;
	while (eof == 0) {
		memset(input_buf, 0, INPUT_BUF_NUM_BYTES);
		memset(output_buf, 0, OUTPUT_BUF_NUM_BYTES);

		int bytes_read = fread(input_buf, sizeof(char), INPUT_BUF_NUM_BYTES, fi);
		if (bytes_read < INPUT_BUF_NUM_BYTES) {
			eof = 1;
		}
		decode_binary(input_buf, output_buf, bytes_read);
		int bytes_to_write = binary_num_bytes(input_buf, strnlen(input_buf, 1000));
		fwrite(output_buf, sizeof(char), bytes_to_write, fo);
	}

	fclose(fi);
	fclose(fo);
	return 0;
}
