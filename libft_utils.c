/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 11:38:16 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/11 11:38:20 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_setdigitnum(long temp)
{
	int	digit_num;

	digit_num = 0;
	if (temp <= 0)
		digit_num++;
	while (temp)
	{
		temp /= 10;
		digit_num++;
	}
	return (digit_num);
}

void	ft_setnum(long temp, int i, char *num)
{
	while (temp > 0)
	{
		num[i] = (temp % 10) + '0';
		temp /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*num;
	long	temp;
	int		digit_num;
	int		i;

	temp = n;
	digit_num = ft_setdigitnum(temp);
	num = malloc(sizeof(char) * (digit_num + 1));
	if (!num)
		return (NULL);
	num[digit_num] = '\0';
	if (n == 0)
	{
		num[0] = '0';
		return (num);
	}
	temp = n;
	if (temp < 0)
	{
		num[0] = '-';
		temp = -temp;
	}
	i = digit_num - 1;
	ft_setnum(temp, i, num);
	return (num);
}

size_t	ft_strlen(const char *s)
{
	size_t	num;
	size_t	i;

	num = 0;
	i = 0;
	while (s[i] != '\0')
	{
		num++;
		i++;
	}
	return (num);
}
