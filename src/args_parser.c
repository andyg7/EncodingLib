#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char *HELP_ARG = "--help";
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
	return 1;
	if (argc < 3) {
		return 0;
	}
	return 1;
}
