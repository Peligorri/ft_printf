#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int		ft_printf(const char *str, ...);
void	print_percentage(int *i, int *argn);
void	print_integer(int *i, int *argn, va_list arguments);
void	print_string(int *i, int *argn, va_list arguments);
void	print_character(int *i, int *argn, va_list arguments);
void	print_unsigned_int(int *i, int *argn, va_list arguments);
void    print_hexa_upper(int *i, int *argn, va_list arguments);
void    print_hexadecimal(int *i, int *argn, va_list arguments, const char *str);
void	print_unsigned(unsigned int n);
void    ft_puthex_upper(unsigned long long n);
void    ft_puthex(unsigned long long n);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
void	ft_setnum(long temp, int i, char *num);
int		ft_setdigitnum(long temp);

#endif