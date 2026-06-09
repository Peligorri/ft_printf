#include "ft_printf.h"

void	print_percentage(int *i, int *argn)
{
	write(1, "%", 1);
	*i = *i + 2;
	(*argn)++;
}

void	print_integer(int *i, int *argn, va_list arguments)
{
	int		tempn;
	char	*temp;

	tempn = va_arg(arguments, int);
	temp = ft_itoa(tempn);
	write(1, temp, ft_strlen(temp));
	*i = *i + 2;
	(*argn) = (*argn) + ft_strlen(temp);
}

void	print_string(int *i, int *argn, va_list arguments)
{
	char	*temp;

	temp = va_arg(arguments, char *);
	write(1, temp, ft_strlen(temp));
	*i = *i + 2;
	(*argn) = (*argn) + ft_strlen(temp);
}

void	print_character(int *i, int *argn, va_list arguments)
{
	char	character;

	character = (char)va_arg(arguments, int);
	write(1, &character, 1);
	*i = *i + 2;
	(*argn)++;
}

void	print_unsigned_int(int *i, int *argn, va_list arguments)
{
	unsigned int		temp;

	temp = va_arg(arguments, unsigned int);
	print_unsigned(temp, argn);
	*i = *i + 2;
}
