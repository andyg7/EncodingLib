#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base64_decode.h"
#include "bit_ops.h"
#include "args_parser.h"
#include "file_processor.h"

int main(int argc, const char *argv[])
{
	if (valid_args(argc, argv) == 0) {
		return 0;
	} 

	int encoded = base64_encode_file((char *) argv[1], (char *) argv[2]);
	/*
	const char *input_file_name = argv[1];
	printf("%s\n", input_file_name);
	const char *output_file_name = argv[2];
	printf("%s\n", output_file_name);

	char *a = "any carnal pleasure.\0";
	int a_len = strnlen(a, 100);
	int b_len = 4 * (a_len / 3);
	if (a_len % 3 != 0) {
		b_len += 4;
	}

	char b[b_len + 1];
	b[b_len] = '\0';
	printf("%s\n", a);
	encode(a, b);
	printf("%s\n", b);
	*/
	return 0;
}
