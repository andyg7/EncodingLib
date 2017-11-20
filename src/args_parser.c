#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char *HELP_ARG = "--help";
const char *ENCODE_ARG = "-e";
const char *DECODE_ARG = "-d";
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
