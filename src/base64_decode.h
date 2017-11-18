int encode_base64(char *i, char *o, int n);
int get_index(char c);
char get_char(int i);
unsigned char extract_front(unsigned char c);
unsigned char extract_mid_to_back(unsigned char c, unsigned char d);
unsigned char extract_back_to_mid(unsigned char c, unsigned char d);
unsigned char extract_back(unsigned char c);
int base64_num_bytes(int binary_num_bytes);
