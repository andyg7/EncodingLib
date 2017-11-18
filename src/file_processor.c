#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "base64_decode.h"

int base64_encode_file(char *input_file_name, char *output_file_name)
{
	FILE *fi = fopen(input_file_name, "r");	
	FILE *fo = fopen(output_file_name, "w+");	

	int INPUT_BUF_NUM_BYTES = 9;
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
		printf("**\n");
		printf("%s\n", input_buf);
		printf("%s %d\n", "bytes read", bytes_read);
		encode_n(input_buf, output_buf, bytes_read);
		int bytes_to_write = base64_num_bytes(bytes_read);
		printf("%s %d\n", "about to write", bytes_to_write);
		printf("%s\n", output_buf);
		printf("**\n");
		fwrite(output_buf, sizeof(char), bytes_to_write, fo);
	}

	fclose(fi);
	fclose(fo);
	return 0;
}
