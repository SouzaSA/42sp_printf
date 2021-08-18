/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utiln.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:42:12 by sde-alva          #+#    #+#             */
/*   Updated: 2021/08/18 14:54:30 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	number_of_digits_unsigned(unsigned long n, long base);
static int	number_of_digits(long long n, long long base);

char	*ft_ulltoa_base(unsigned long n, int base)
{
	int		len;
	char	*base_str;
	char	*str;

	n = (unsigned int)n;
	len = number_of_digits_unsigned(n, (long)base);
	base_str = "0123456789abcdef";
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str)
	{
		str[len] = '\0';
		if (n == 0)
			str[0] = '0';
		while (n > 0)
		{
			str[--len] = base_str[n % base];
			n /= (unsigned long)base;
		}
	}
	return (str);
}

static int	number_of_digits_unsigned(unsigned long n, long base)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_lltoa_base(long long n, int base)
{
	int		len;
	char	*base_str;
	char	*str;

	len = number_of_digits(n, (long long)base);
	base_str = "0123456789abcdef";
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str)
	{
		str[len] = '\0';
		if (n == 0)
			str[0] = '0';
		if (n < 0)
		{
			str[0] = '-';
			str[--len] = base_str[-1 * (n % base)];
			n /= -(long long)base;
		}
		while (n > 0)
		{
			str[--len] = base_str[n % base];
			n /= (long long)base;
		}
	}
	return (str);
}

static int	number_of_digits(long long n, long long base)
{
	int	len;

	len = 0;
	if (n < 0 || n == 0)
		len++;
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}
