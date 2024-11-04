#include "printf.h" 

int ft_printf(char  *str, ...)
{
    int i;
    va_list arguments;

    va_arg(arguments, char *);
    i = 0;
    while (str[i])
    {
        if (str[i] == '%') 
        {
            if (str[1] == 'c')
                put_char(va_arg(arguments, char));
            else if (str[1] == 's')
                put_str(va_arg(arguments, char *));
            else if (str[1] == 'i')
                //
            else if (str[1] == 'u')
                //
            else if (str[1] == 'p')
                //
            else if (str[1] == 'x')
                //
            else if (str[1] == 'X')
                //
            if else(str[1] == '%')
            {
                write(1, "%%", 1);
                i++;
            }
        }
        else
        {
            write(1, &str[i], 1);
            i++;
        }
    }
    return (i);
}
