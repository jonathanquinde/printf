#include "printf.h"

int char_handler(char c)
{
    write(1, &c, 1);
    return (1);
}

int str_handler(char *str)
{
    int i;

    i = 0;
    while (*str)
    {
        i++;
        write(1, str, 1);
    }
    return (i);
}