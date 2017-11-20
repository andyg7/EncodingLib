#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base64_decode.h"
#include "bit_ops.h"
#include "args_parser.h"
#include "file_processor.h"

int main(int argc, const char *argv[])
{
	int valid_args_provided = valid_args(argc, argv);
	if (!valid_args_provided) {
		return 0;
	}
	char *input_file_name = (char *) argv[2];
	char *output_file_name = (char *) argv[3];
	int encode = should_encode(argc, argv);
	if (encode) {
		base64_encode_file(input_file_name, output_file_name);
	} else {
		base64_decode_file(input_file_name, output_file_name);
	}
	return 0;
}
