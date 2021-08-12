/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utiln.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:42:12 by sde-alva          #+#    #+#             */
/*   Updated: 2021/08/11 15:01:19 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static int	ft_itoa_base_aux(long long n, int base, char *str);
static int	ft_atoi_err(int signal);

char	*ft_lltoa_base(long long n, int base)
{
	int			len;
	long long	tmp;
	char		*rtn;

	len = 0;
	tmp = n;
	rtn = NULL;
	while (tmp != 0)
	{
		tmp /= base;
		len++;
	}
	if (n < 0)
		len++;
	rtn = (char *)malloc((len + 1) * sizeof(char));
	if (rtn)
	{
		ft_lltoa_base_aux(n, base, rtn);
		rtn[len] = '\0';
	}
	return (rtn);
}

static int	ft_lltoa_base_aux(long long n, int base, char *str)
{
	int		i;
	int		signal;
	char	*base_val;

	i = 0;
	signal = 1;
	base_val = "0123456789abcdef";
	if (n < 0)
	{
		str[0] = '-';
		signal = -1;
		i++;
	}
	if (n == 0)
		return (1);
	if (n != 0)
	{
		i += ft_lltoa_base_aux(n / base, base, str) - 1;
		s[i] = base_val[signal * (n % base)];
		return (i);
	}
}

char	*ft_number_flag_apply(char *nstr, t_printf_flags flags)
{
	int		n_printed;
	char	*num;
	char	*tmp;

	tmp = *nstr;
	if (flags.plus)
	{
		num = ft_strjoin_mod("+", tmp);
	}
	else if (flags.space)
	{
		num = ft_strjoin_mod(" ", tmp);
	}
	else
	{
		num = tmp;
	}
	free(tmp);
	tmp = NULL;
	return (nstr);
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
