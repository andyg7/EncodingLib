CC=gcc
OBJS=main.o base64_decode.o bit_ops.o file_processor.o args_parser.o hex_decode.o binary_decode.o
HEADERS=base64_decode.h bit_ops.h file_processor.h args_parser.h hex_decode.h binary_decode.h
PROG_NAME=codeit

$(PROG_NAME): $(OBJS)
	$(CC) -o $(PROG_NAME) $(OBJS) 

main.o: main.c
	$(CC) -c main.c

base64_decode.o: base64_decode.c $(HEADERS)
	$(CC) -c base64_decode.c

bit_ops.o: bit_ops.c $(HEADERS)
	$(CC) -c bit_ops.c

file_processor.o: file_processor.c $(HEADERS)
	$(CC) -c file_processor.c

args_parser.o: args_parser.c $(HEADERS)
	$(CC) -c args_parser.c

hex_decode.o: hex_decode.c $(HEADERS)
	$(CC) -c hex_decode.c

binary_decode.o: binary_decode.c $(HEADERS)
	$(CC) -c binary_decode.c

.PHONY: clean

clean:
	rm -rf $(OBJS)

all: clean $(PROG_NAME)
