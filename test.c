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