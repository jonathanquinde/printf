#include "printf.h"

int put_char(char c)
{
    return(write(1, &c, 1));
}

int put_str(char *str)
{
    int sum;

    if (str == NULL)
        return (write(1, "(null)", 6));
    sum = 0;
    while (*str)
        sum += write(1, str++, 1);
    return (sum);
}