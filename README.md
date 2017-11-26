# EncodingLib

App for encoding and decoding binary files 

### Motivation
Often you'll want to work with binary files. However, binary files usually don't make much sense when we open them up in 
a text editor or want to view them with our own eyes. e.g. encrypted files, or binary programs. Encoding is a way for us to 
translate binary files into some sort of language we can better make sense of. It also reduces the chance of us 
corrupting files when we send them around (e.g. copy and paste). We don't lose the original
contents of the binary file, we simply translate it into text that is easier for us humans to
look at and manipulate. Of course, with encoding comes decoding. Decoding is simply the process
of translating the encoded file back to it's true original contents.

### Schemes supported
- Base64 (https://en.wikipedia.org/wiki/Base64)
- Hex (https://en.wikipedia.org/wiki/Hexadecimal)
- Binary aka the file will end up with '1's and '0's

### Usage
./codeit "arg for encoding or decoding" "scheme" <pretty_print>"input file" "output file"

To encode some file in base64:
./codeit -e --base64 binary.txt output.txt

To decode some file in base64:
./codeit -d --base64 output.txt test.txt

This will (or at least certainly should!) result in test.txt being identical to binary.txt

To encode some file in hex:
./codeit -e --hex binary_hex.txt output_hex.txt

To decode some file in hex:
./codeit -d --hex output_hex.txt test_hex.txt

This will (or at least certainly should!) result in test.txt being identical to binary.txt

To encode some file in 1s and 0s:
./codeit -e --binary binary_hex.txt output_hex.txt

To decode some file in 1s and 0s:
./codeit -d --binary output_hex.txt test_hex.txt

Add '-p' if, when encoding, you want it to print to a file in a nicer format. Currently, the
decoder can't understand files when they're printed in the nicer format. Thus, one can't encode
in pretty print format, and decode back to the original.

e.g.  ./codeit -e --base64 -p binary_hex.txt output_hex.txt
e.g.  ./codeit -e --hex -p binary_hex.txt output_hex.txt
e.g.  ./codeit -e --binary -p binary_hex.txt output_hex.txt


### TODO
- Add some unit tests along with an automated testing suite.
- Improve the pretty print functionality. e.g. make it prettier, add addresses like xxd does
- Get the decoders to understand the pretty print functionality.

### FAQ
- Should I use this app for encoding/decoding my files? Probably not. There are already libraries that will do this for you.
  Those libraries are better too.
- Then why did you write this code? For fun.
- Can I contribute? Sure! Feel free to fork and submit a pull request with any sort of
  changes/additions/bug fixes etc. Take a look at the TODO section for some ideas. An easy one
  right now would be to add an automated testing suite.
