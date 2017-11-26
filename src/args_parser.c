#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char *HELP_ARG = "--help";
const char *ENCODE_ARG = "-e";
const char *DECODE_ARG = "-d";
const char *HEX_ARG = "--hex";
const char *PRETTY_PRINT_ARG = "-p";
const char *BASE64_ARG = "--base64";
const char *BINARY_ARG = "--binary";
const char *help_string = "format: a.out <binaryfile> <outputfile>";

int valid_args(int argc, const char *argv[])
{
	if (argc == 1) {
		printf("%s\n", help_string);
		return 0;
	}

	const char *arg1 = argv[1];
	if (strncmp(arg1, HELP_ARG, strnlen(HELP_ARG, 1000)) == 0) {
		printf("%s\n", help_string);
		return 0;
	}
	int has_encoding_decoding_flag = 0;
	if (strncmp(argv[1], ENCODE_ARG, strnlen(ENCODE_ARG, 1000)) == 0) {
		has_encoding_decoding_flag = 1;
	}
	if (strncmp(argv[1], DECODE_ARG, strnlen(DECODE_ARG, 1000)) == 0) {
		has_encoding_decoding_flag = 1;
	}
	if (!has_encoding_decoding_flag) {
		printf("%s\n", "Must provide either -e (for encoding) or -d (for decoding)");
		return 0;
	}
	return 1;
}

int should_encode(int argc, const char *argv[])
{
	int should_encode = 0;
	if (strncmp(argv[1], ENCODE_ARG, strnlen(ENCODE_ARG, 1000)) == 0) {
		should_encode = 1;
	}
	return should_encode;
}

int should_decode(int argc, const char *argv[])
{
	int should_decode = 0;
	if (strncmp(argv[1], DECODE_ARG, strnlen(DECODE_ARG, 1000)) == 0) {
		should_decode = 1;
	}
	return should_decode;
}

int hex_arg(int argc, const char *argv[])
{
	int is_hex = 0;
	if (strncmp(argv[2], HEX_ARG, strnlen(HEX_ARG, 1000)) == 0) {
		is_hex = 1;
	}
	return is_hex;
}

int base64_arg(int argc, const char *argv[])
{
	int is_base64 = 0;
	if (strncmp(argv[2], BASE64_ARG, strnlen(BASE64_ARG, 1000)) == 0) {
		is_base64 = 1;
	}
	return is_base64;
}

int binary_arg(int argc, const char *argv[])
{
	int is_base64 = 0;
	if (strncmp(argv[2], BINARY_ARG, strnlen(BINARY_ARG, 1000)) == 0) {
		is_base64 = 1;
	}
	return is_base64;
}

int pretty_arg(int argc, const char *argv[])
{
	int is_pretty_print = 0;
	for (int i = 0; i < argc; i++) {
		if (strncmp(argv[3], PRETTY_PRINT_ARG, strnlen(HEX_ARG, 1000)) == 0) {
			is_pretty_print = 1;
		}
	}
	return is_pretty_print;
}

int get_input_file_arg_index(int argc, const char *argv[])
{
	for (int i = 1; i < argc; i++) {
		const char *t = argv[i];		
		if (strncmp(t, "-", 1) != 0) {
			return i;			
		}
	}
	return -1;
}

int get_output_file_arg_index(int argc, const char *argv[])
{
	int input_index = get_input_file_arg_index(argc, argv);
	if (input_index + 1 >= argc) {
		return -1;
	}
	return input_index + 1;
}
