/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utiln.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:42:12 by sde-alva          #+#    #+#             */
/*   Updated: 2021/08/13 13:18:45 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	number_of_digits(long long n, long long base);
static int	ft_atoi_err(int signal);

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

char	*ft_number_flag_apply(char *nstr, t_printf_flags flags)
{
	char	*num;

	if (flags.plus && nstr[0] != "-" && nstr[0] != "0")
	{
		num = ft_strjoin_mod("+", nstr);
	}
	else if (flags.space && nstr[0] != "-" && nstr[0] != "0")
	{
		num = ft_strjoin_mod(" ", nstr);
	}
	else
	{
		num = ft_strjoin_mod("", nstr);
	}
	return (num);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		signal;
	long	result;
	long	prev;

	i = 0;
	signal = -1;
	result = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13 && nptr[i] != '\0'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			signal = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i] != '\0')
	{
		prev = result;
		result = result * 10 - (nptr[i] - '0');
		if (prev < result)
			return (ft_atoi_err(signal));
		i++;
	}
	return (signal * result);
}

static int	ft_atoi_err(int signal)
{
	int	err_val;

	err_val = 0;
	if (signal < 0)
		err_val = -1;
	return (err_val);
}
