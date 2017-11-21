# EncodingLib

App for encoding and decoding binary files 

### Motivation
Often you'll want to work with binary files. However, binary files usually dont make much sense when we open them up in 
a text editor or want to view them with our own eyes. Encoding is a way for us to 
translate binary files into some sort of language we can better make sense of. It also reduces the chance of us 
corrupting files when we send them around (e.g. copy and paste)

### Schemes supported
- Base64 (https://en.wikipedia.org/wiki/Base64)
- Hex (https://en.wikipedia.org/wiki/Hexadecimal)

### Usage
./codeit "arg for encoding or decoding" "scheme" "input file" "output file"

e.g. ./codeit -e --base64 binary.txt output.txt

e.g. ./codeit -d --base64 output.txt test.txt

This will (or at least certainly should!) result in test.txt being identical to binary.txt

e.g. ./codeit -e --hex binary_hex.txt output_hex.txt

e.g. ./codeit -d --hex output_hex.txt test_hex.txt


### TODO
- Add other encoding schemes

### FAQ
- Should i use this app for encoding/decoding my files? Probably not. There are already libraries that will do this for you.
  Those libraries are better too.
- Then why did you write this code? For fun.
