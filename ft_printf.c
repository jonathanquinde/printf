#include "printf.h" 

int conversion_specifiers(char  word, va_list arguments);

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
        if (str[i] == '%') 
            sum += conversion_specifiers(str[++i], arguments);
        else
            sum += write(1, &str[i], 1);
        i++;
    }
    va_end(arguments);
    return (sum);
}

int conversion_specifiers(char  word, va_list arguments)
{
    size_t  sum;
    
    sum = 0;
    if (word == 'c')
        sum += put_char(va_arg(arguments, int));
    else if (word == 's')
        sum += put_str(va_arg(arguments, char *));
    else if (word == 'i' || word == 'd')
        sum += handle_negative(va_arg(arguments, int));
    else if (word == 'u')
        sum += put_nbr_base(va_arg(arguments, unsigned int), "0123456789", 10);
    else if (word == 'p')
        sum += put_pointer_adress(va_arg(arguments, void *));
    else if (word == 'x')
        sum += put_nbr_base(va_arg(arguments, unsigned int), "0123456789abcdef", 16);
    else if (word == 'X')
        sum += put_nbr_base(va_arg(arguments, unsigned int), "0123456789ABCDEF", 16);
    else if (word == '%')
        sum += write(1, "%%", 1);
    return (sum);
}

int main(void)
{
    int p_result;
    int u_result;

    p_result = printf("hola\n");
    u_result = ft_printf("hola\n");
    printf("Printf: %d, ft_printf: %d\n", p_result, u_result);

    p_result = printf("%u\n", 0);
    u_result = ft_printf("%u\n", 0);
    printf("Printf: %d, ft_printf: %d\n", p_result, u_result);

    p_result = printf("%u\n", 1);
    u_result = ft_printf("%u\n", 1);
    printf("Printf: %d, ft_printf: %d\n", p_result, u_result);

    p_result = printf("%u\n", -1);
    u_result = ft_printf("%u\n", -1);
    printf("Printf: %d, ft_printf: %d\n", p_result, u_result);
/*
    p_result = printf("%u\n", 4294967294);
    u_result = ft_printf("%u\n", 4294967295);
    printf("Printf: %d, ft_printf: %d\n", p_result, u_result);

    //p_result = printf("%i\n", 4294967296);
    u_result = ft_printf("%i\n", 4294967296);
    printf("Printf: %d, ft_printf: %d\n", p_result, u_result);
*/
}