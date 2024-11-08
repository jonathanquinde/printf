/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:38:57 by jquinde-          #+#    #+#             */
/*   Updated: 2024/11/08 12:27:12 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	conversion_specifiers(char word, va_list arguments);

int	ft_printf(char *str, ...)
{
	int		i;
	int		sum;
	va_list	arguments;

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

int	conversion_specifiers(char word, va_list arguments)
{
	size_t	sum;

	sum = 0;
	if (word == 'c')
		sum += put_char(va_arg(arguments, int));
	else if (word == 's')
		sum += put_str(va_arg(arguments, char *));
	else if (word == 'i' || word == 'd')
		sum += handle_negative(va_arg(arguments, int));
	else if (word == 'u')
		sum += put_nbr_base(va_arg(arguments, unsigned int), BASE_DEC, 10);
	else if (word == 'p')
		sum += put_pointer_adress(va_arg(arguments, void *));
	else if (word == 'x')
		sum += put_nbr_base(va_arg(arguments, unsigned int), BASE_HEX_MIN, 16);
	else if (word == 'X')
		sum += put_nbr_base(va_arg(arguments, unsigned int), BASE_HEX_MAY, 16);
	else if (word == '%')
		sum += write(1, "%%", 1);
	return (sum);
}

/*
int	main(void)
{
	int p_result;
	int u_result;

	//0 - Prueba normal
	printf("0 - Prueba normal");
	p_result = printf("hola\n");
	u_result = ft_printf("hola\n");
	printf("Printf: %d, ft_printf: %d\n", p_result, u_result);

	//1 - Prueba con char
	printf("1 - Prueba con char");
	char    c = 'a';
	int     c1 = 255;
	long    c2 = 9218490128491248109;
	p_result = printf("%c\n", c);
	u_result = printf("%c\n", c);

	p_result = printf("%c\n", c1);
	u_result = printf("%c1\n", c1);

	p_result = printf("%c\n", c2);
	u_result = printf("%c\n", c2);

	//2 - Prueba con strings
	char *str = "quack";
	printf("2 - Prueba con strings");
	p_result = printf("%s\n", str);
	u_result = printf("%s\n", str);
	printf("Printf: %d, ft_printf: %d\n", p_result, u_result);

	str = "";
	p_result = printf("%s\n", str);
	u_result = printf("%s\n", str);
	printf("Printf: %d, ft_printf: %d\n", p_result, u_result);
}
*/
