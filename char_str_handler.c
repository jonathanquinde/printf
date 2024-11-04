#include "printf.h"

int put_char(char c)
{
    retur(write(1, &c, 1));
}

int put_str(char *str)
{
    int i;

    if (str == NULL)
        return (write(1, "(nil)", 5));
    i = 0;
    while (*str)
        i += write(1, str, 1);
    return (i);
}