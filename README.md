# EncodingLib

Library for encoding and decoding binary files

### Schemes supported
- Base64

### Usage
./codeit "arg for encoding or decoding" "input file" "output file"

e.g. ./codeit -e binary.txt output.txt

e.g. ./codeit -d output.txt test.txt

This will (or at least certainly should!) result in test.txt being identical to binary.txt

### TODO
- Add hex support
- Improve Makefile so we can have library code in lib/ and binaries in bin/ and objects in
  build/
