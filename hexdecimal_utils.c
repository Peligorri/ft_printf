#include "ft_printf.h"

void    ft_puthex(unsigned long long n)
{
    char *base = "0123456789abcdef";

    if (n >= 16)
        ft_puthex(n / 16);
    write(1, &base[n % 16], 1);
}

void    ft_puthex_upper(unsigned long long n)
{
    char *base = "0123456789ABCDEF";

    if (n >= 16)
        ft_puthex_upper(n / 16);
    write(1, &base[n % 16], 1);
}


void    print_unsigned(unsigned int n)
{
    if (n >= 10)
        print_unsigned(n / 10);
    char c = (n % 10) + '0';
    write(1, &c, 1);
}

void    print_hexadecimal(int *i, int *argn, va_list arguments, const char *str)
{
    void    *pointer;

    pointer = va_arg(arguments, void *);
    if (str[*i + 1] == 'p')
        write(1, "0x", 2);
    ft_puthex((unsigned long long)pointer);
    *i = *i + 2;
    (*argn)++;
}

void    print_hexa_upper(int *i, int *argn, va_list arguments)
{
    unsigned int        temp;

    temp = va_arg(arguments, unsigned int);
    ft_puthex_upper((unsigned int)temp);
    *i = *i + 2;
    (*argn)++;
}