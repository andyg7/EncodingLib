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
	int input_file_index = get_input_file_arg_index(argc, argv);
	int output_file_index = get_output_file_arg_index(argc, argv);
	char *input_file_name = (char *) argv[input_file_index];
	char *output_file_name = (char *) argv[output_file_index];

	int encode = should_encode(argc, argv);
	int hex_func = hex_arg(argc, argv);
	int base64_func = base64_arg(argc, argv);
	int binary_func = binary_arg(argc, argv);
	int pretty_p_arg = pretty_arg(argc, argv);

	if (encode) {
		if (hex_func) {
			if (pretty_p_arg) {
				hex_encode_file_pretty(input_file_name, output_file_name);
			} else {
				hex_encode_file(input_file_name, output_file_name);
			}
		} else if (base64_func) {
			if (pretty_p_arg) {
				base64_encode_file_pretty(input_file_name, output_file_name);
			} else {
				base64_encode_file(input_file_name, output_file_name);
			}
		} else if (binary_func) {
			if (pretty_p_arg) {
				binary_encode_file_pretty(input_file_name, output_file_name);
			} else {
				binary_encode_file(input_file_name, output_file_name);
			}
		}

	} else {
		if (hex_func) {
			hex_decode_file(input_file_name, output_file_name);
		} else if (base64_func) {
			base64_decode_file(input_file_name, output_file_name);
		} else if (binary_func) {
			binary_decode_file(input_file_name, output_file_name);
		}

	}
	return 0;
}
