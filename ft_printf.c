/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 11:37:32 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/11 11:37:36 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	print_hexa_lower(int *argn, va_list arguments)
{
	unsigned int	temp;

	temp = va_arg(arguments, unsigned int);
	ft_puthex((unsigned int)temp, argn);
	//*i = *i + 2;
}

void	select_prints(const char *str, int *i, int *argn, va_list arguments)
{
	if (str[*i + 1] == '%')
		print_percentage(argn);
	else if ((str[*i + 1] == 'i' || str[*i + 1] == 'd'))
		print_integer(argn, arguments);
	else if (str[*i + 1] == 's')
		print_string(argn, arguments);
	else if (str[*i + 1] == 'c')
		print_character(argn, arguments);
	else if (str[*i + 1] == 'p')
		print_hexadecimal(i, argn, arguments, str);
	else if (str[*i + 1] == 'u')
		print_unsigned_int(argn, arguments);
	else if (str[*i + 1] == 'x')
		print_hexa_lower(argn, arguments);
	else if (str[*i + 1] == 'X')
		print_hexa_upper(argn, arguments);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		argn;
	va_list	arguments;

	i = 0;
	argn = 0;
	va_start(arguments, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			select_prints(str, &i, &argn, arguments);
			if (str[i + 2] != '\0')
				i = i + 2;
			else
			{
				va_end(arguments);
				return (argn);
			}
		}
		if (str[i] == '%')
			i--;
		else
		{
			write(1, &str[i], 1);
			argn++;
		}
		i++;
	}
	va_end(arguments);
	return (argn);
}

/*int	main(void)
{
	int n = 42;
	int chars;
	int realchars;

	chars = ft_printf("Caracter: %c, cadena: %s, puntero: %p, decimal: %d, entero: %i, sin signo: %u, hexadecimal min: %x, hexadecimal may: %X y porcentaje: %%.\n", '0' - 256, "Hola mundo", &n, -12345, 67890, -42U, 305441741, 305441741);
	realchars = printf("Caracter: %c, cadena: %s, puntero: %p, decimal: %d, entero: %i, sin signo: %u, hexadecimal min: %x, hexadecimal may: %X y porcentaje: %%.\n", '0' - 256, "Hola mundo", &n, -12345, 67890, -42U, 305441741, 305441741);
	ft_printf("\n\nSe han impreso %i carácteres\n", chars);
	printf("Se han impreso %i carácteres\n", realchars);
	return (0);
}*/

/*int	main(void)
{
	char 			c = 'A';
	char 			*str = "Hello World";
	void 			*ptr = &str;
	int 			dec_1 = -42424242;
	int 			dec_2 = 0;
	int 			dec_3 = 42424242;
	int				i_1 = 42;
	int				i_2 = 052;
	int				i_3 = 0x2A;
	unsigned int	u_1 = -42;		// <----- Bad value to test both functions
	unsigned int	u_2= 0;
	unsigned int	u_3 = 4242424242;
	int				count = 0;
	int				my_count = 0;

	//char
	count = printf("With original function, char is: %c\n", c);
	my_count = ft_printf("With my implementation, char is: %c\n", c);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");
	
	count = printf("With original function, char is: %c\n", '\0');
	my_count = ft_printf("With my implementation, char is: %c\n", '\0');
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");

	printf("\n");
	printf("\n");
	printf("\n");

	//string
	count = printf("With original function, string is: %s\n", str);
	my_count = ft_printf("With my implementation, string is: %s\n", str);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");

	count = printf("With original function, empty string is: %s\n", "");
	my_count = ft_printf("With my implementation, empty string is: %s\n", "");
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");

	printf("\n");
	printf("\n");
	printf("\n");

	//pointer
	count = printf("With original function, address is: %p\n", ptr);
	my_count = ft_printf("With my implementation, address is: %p\n", ptr);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");
	
	count = printf("With original function, null address is: %p\n", NULL);
	my_count = ft_printf("With my implementation, null address is: %p\n", NULL);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");
	
	printf("\n");
	printf("\n");
	printf("\n");

	//decimal	
	count = printf("With original function, decimal is: %d\n", dec_1);
	my_count = ft_printf("With my implementation, decimal is: %d\n", dec_1);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");
	
	count = printf("With original function, decimal is: %d\n", dec_2);
	my_count = ft_printf("With my implementation, decimal is: %d\n", dec_2);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");
	
	count = printf("With original function, decimal is: %d\n", dec_3);
	my_count = ft_printf("With my implementation, decimal is: %d\n", dec_3);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");

	count = printf("Original function, interpreting dec. is: %d\n", i_1);
	my_count = ft_printf("My implementation, interpreting dec. is: %d\n", i_1);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");

	count = printf("With original function, interpreting octal is: %d\n", i_2);
	my_count = ft_printf("With my implementation, interpreting octal is: 
%d\n", i_2);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");

	count = printf("With original function, interpreting hexadecimal is: 
%d\n", i_3);
	my_count = ft_printf("With my implementation, interpreting hexadecimal 
is: %d\n", i_3);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");

	printf("\n");
	printf("\n");
	printf("\n");

	//integer
	count = printf("With original function, integer is: %i\n", dec_1);
	my_count = ft_printf("With my implementation, integer is: %i\n", dec_1);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");
	
	count = printf("With original function, integer is: %i\n", dec_2);
	my_count = ft_printf("With my implementation, integer is: %i\n", dec_2);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");
	
	count = printf("With original function, integer is: %i\n", dec_3);
	my_count = ft_printf("With my implementation, integer is: %i\n", 
dec_3);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");

	count = printf("With original function, interpreting decimal is: %i\n",
 i_1);
	my_count = ft_printf("With my implementation, interpreting decimal is:
 %i\n", i_1);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");
	
	count = printf("With original function, interpreting octal is: %i\n",
 i_2);
	my_count = ft_printf("With my implementation, interpreting octal is:
 %i\n", i_2);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");
	
	count = printf("With original function, interpreting hexadecimal is: 
%i\n", i_3);
	my_count = ft_printf("With my implementation, interpreting hexadecimal 
is: %i\n", i_3);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");

	printf("\n");
	printf("\n");
	printf("\n");

	//unsigned decimal
	count = printf("With original function, unsigned decimal is: %u\n", u_1);
	my_count = ft_printf("With my implementation, unsigned decimal is: 
%u\n", u_1);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");
	
	count = printf("With original function, unsigned decimal is: %u\n", u_2);
	my_count = ft_printf("With my implementation, unsigned decimal is: 
%u\n", u_2);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");
	
	count = printf("With original function, unsigned decimal is: %u\n", u_3);
	my_count = ft_printf("With my implementation, unsigned decimal is: 
%u\n", u_3);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");

	printf("\n");
	printf("\n");
	printf("\n");

	//lowercase hexadecimal
	count = printf("With original function, in lowercase hexadecimal 
is: %x\n", dec_1);
	my_count = ft_printf("With my implementation, in lowercase hexadecimal 
is: %x\n", dec_1);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");

	count = printf("With original function, in lowercase hexadecimal 
is: %x\n", dec_3);
	my_count = ft_printf("With my implementation, in lowercase hexadecimal 
is: %x\n", dec_3);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");

	count = printf("With original function, in lowercase hexadecimal 
is: %x\n", i_2);
	my_count = ft_printf("With my implementation, in lowercase hexadecimal 
is: %x\n", i_2);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");
	
	count = printf("With original function, in lowercase hexadecimal 
is: %x\n", i_3);
	my_count = ft_printf("With my implementation, in lowercase hexadecimal 
is: %x\n", i_3);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");
	
	count = printf("With original function, in lowercase hexadecimal 
is: %x\n", u_3);
	my_count = ft_printf("With my implementation, in lowercase hexadecimal 
is: %x\n", u_3);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");

	printf("\n");
	printf("\n");
	printf("\n");
	
	//uppercase hexadecimal	
	count = printf("With original function, in uppercase hexadecimal 
is: %X\n", dec_1);
	my_count = ft_printf("With my implementation, in uppercase hexadecimal 
is: %X\n", dec_1);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");

	count = printf("With original function, in uppercase hexadecimal 
is: %X\n", dec_3);
	my_count = ft_printf("With my implementation, in uppercase hexadecimal 
is: %X\n", dec_3);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");

	count = printf("With original function, in uppercase hexadecimal 
is: %X\n", i_2);
	my_count = ft_printf("With my implementation, in uppercase hexadecimal 
is: %X\n", i_2);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");
	
	count = printf("With original function, in uppercase hexadecimal 
is: %X\n", i_3);
	my_count = ft_printf("With my implementation, in uppercase hexadecimal 
is: %X\n", i_3);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");

	count = printf("With original function, in uppercase hexadecimal 
is: %X\n", u_3);
	my_count = ft_printf("With my implementation, 
in uppercase hexadecimal is: %X\n", u_3);
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");

	printf("\n");
	printf("\n");
	printf("\n");

	//percent sign
	count = printf("With original function, percent sign is: %%\n");
	my_count = ft_printf("With my implementation, percent sign is: %%\n");
	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");

	printf("\n");
	printf("\n");
	printf("\n");	

	//---------------------------------------------------------

	//testing mixed format specifiers
	count = printf("With original function:\nWe have to implement this function 
testing many conversions like:\n char (%c),\n string (%s),\n pointer address 
(%p),\n decimal (%d),\n integer (%i),\n unsigned decimal (%u),\n lowercase 
hexadecimal number (%x),\n uppercase hexadecimal number (%X),\n the percent 
sign (%%) \n\n", c, str, ptr, dec_1, i_1, u_3, u_3, u_3);

	printf("\n");

	my_count = ft_printf("With my implementation:\nWe have to implement this 
function testing many conversions like:\n char (%c),\n string (%s),\n pointer 
address (%p),\n decimal (%d),\n integer (%i),\n unsigned decimal (%u),\n 
lowercase hexadecimal number (%x),\n uppercase hexadecimal number (%X),\n the 
percent sign (%%) \n\n", c, str, ptr, dec_1, i_1, u_3, u_3, u_3);

	printf("\n");

	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");


	printf("\n");
	printf("\n");
	printf("\n");
	

	//testing duplicated format specifiers
	count = printf("With original function:\nWe have to implement this function 
testing many conversions like:\n char (%c%c),\n string (%s%s),\n pointer 
address (%p%p),\n decimal (%d%d),\n integer (%i%i),\n unsigned decimal (%u%u),\n 
lowercase hexadecimal number (%x%x),\n uppercase hexadecimal number (%X%X),\n 
the percent sign (%%%%) \n\n", c, c, str, str, ptr, ptr, dec_1, dec_1, i_1, 
i_1, u_3, u_3, u_3, u_3, u_3, u_3);

	printf("\n");

	my_count = ft_printf("With my implementation:\nWe have to implement this 
function testing many conversions like:\n char (%c%c),\n string (%s%s),\n 
pointer address (%p%p),\n decimal (%d%d),\n integer (%i%i),\n unsigned decimal 
(%u%u),\n lowercase hexadecimal number (%x%x),\n uppercase hexadecimal number 
(%X%X),\n the percent sign (%%%%) \n\n", 
c, c, str, str, ptr, ptr, dec_1, dec_1, i_1, i_1, u_3, u_3, u_3, u_3, u_3, u_3);

	printf("\n");

	printf("Value returned from original function is: %d\n", count);
	ft_printf("Value returned from my function is: %d\n", my_count);
	printf("\n");


	return (0);
}*/
