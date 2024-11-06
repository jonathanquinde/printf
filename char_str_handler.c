#include "printf.h"

int put_char(char c)
{
    return(write(1, &c, 1));
}

int put_str(char *str)
{
    int i;

    if (str == NULL)
        return (write(1, "(null)", 6));
    i = 0;
    while (*str)
        i += write(1, str, 1);
    return (i);
}