#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		argn;
	va_list arguments;

	i = 0;
	argn = 0;
	va_start(arguments, str);
	while(str[i])
	{
		if(str[i] == '%' && str[i + 1] == '%')
			print_percentage(&i, &argn);
		else if(str[i] == '%' && (str[i + 1] == 'i' || str[i + 1] == 'd'))
			print_integer(&i, &argn, arguments);
		else if (str[i] == '%' && str[i + 1] == 's')
			print_string(&i, &argn, arguments);
		else if (str[i] == '%' && str[i + 1] == 'c')
			print_character(&i, &argn, arguments);
		else if (str[i] == '%' && (str[i + 1] == 'x' || str[i + 1] == 'p'))
			print_hexadecimal(&i, &argn, arguments, str);
		else if(str[i] == '%' && str[i + 1] == 'u')
			print_unsigned_int(&i, &argn, arguments);
		else if (str[i] == '%' && str[i + 1] == 'X')
			print_hexa_upper(&i, &argn, arguments);

		write(1, &str[i], 1);
		i++;
	}
	va_end(arguments);
	return (argn);
}

int	main(void)
{
	int n = 42;

	ft_printf("Caracter: %c, cadena: %s, puntero: %p, decimal: %d, entero: %i, sin signo: %u, hexadecimal min: %x, hexadecimal may: %X y porcentaje: %%.\n\n\n", 'A', "Hola mundo", &n, -12345, 67890, -42U, 305441741, 305441741);
	printf("Caracter: %c, cadena: %s, puntero: %p, decimal: %d, entero: %i, sin signo: %u, hexadecimal min: %x, hexadecimal may: %X y porcentaje: %%.\n", 'A', "Hola mundo", &n, -12345, 67890, -42U, 305441741, 305441741);
	return (0);
}