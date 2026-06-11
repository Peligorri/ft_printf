/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 11:38:45 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/11 11:38:47 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percentage(int *argn)
{
	write(1, "%", 1);
	//*i = *i + 2;
	(*argn)++;
}

void	print_integer(int *argn, va_list arguments)
{
	int		tempn;
	char	*temp;

	tempn = va_arg(arguments, int);
	temp = ft_itoa(tempn);
	write(1, temp, ft_strlen(temp));
	//*i = *i + 2;
	(*argn) = (*argn) + ft_strlen(temp);
}

void	print_string(int *argn, va_list arguments)
{
	char	*temp;

	temp = va_arg(arguments, char *);
	if (temp == NULL)
	{
		write(1, "(null)", 6);
		(*argn) = (*argn) + 6;
	}
	else
	{
		write(1, temp, ft_strlen(temp));
		(*argn) = (*argn) + ft_strlen(temp);
	}
	//*i = *i + 2;
	
}

void	print_character(int *argn, va_list arguments)
{
	char	character;

	character = (char)va_arg(arguments, int);
	write(1, &character, 1);
	//*i = *i + 2;
	(*argn)++;
}

void	print_unsigned_int(int *argn, va_list arguments)
{
	unsigned int		temp;

	temp = va_arg(arguments, unsigned int);
	print_unsigned(temp, argn);
	//*i = *i + 2;
}
