#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int put_char(char c);
int put_str(char *str);
int put_nbr_base(unsigned int num, char *base, size_t len);
int put_pointer_adress(void *ptr);
int handle_negative(int num);