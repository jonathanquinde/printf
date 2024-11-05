#include "printf.h" 

int ft_printf(char  *str, ...)
{
    int i;
    int sum;
    va_list arguments;

    va_start(arguments, str);
    sum = 0;
    i = 0;
    while (str[i])
    {
        if (str[i++] == '%') 
            sum += conversion_specifiers(str[1], arguments);
        else
            write(1, &str[i], 1);
        i++;
    }
    return (i);
}

int conversion_specifiers(char  word, va_list arguments)
{
    size_t  sum;
    
    sum = 0;
    if (word == 'c')
        sum += put_char(va_arg(arguments, char));
    else if (word == 's')
        sum += put_str(va_arg(arguments, char *));
    else if (word = 'i')
        //
    else if (word == 'u')
        //
    else if (word == 'p')
        //
    else if (word == 'x')
        //
    else if (word == 'X')
        //
    else if (word == '%')
        sum += write(1, "%%", 1);
    return (sum);
}
