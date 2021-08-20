/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_filler_num.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:32:35 by sde-alva          #+#    #+#             */
/*   Updated: 2021/08/20 18:25:40 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_printf_pres_fill_size(char *str, t_printf_flags *flags);
static char	*ft_fill_minlen(char *str, char *tmp, int n, t_printf_flags *flags);

char	*ft_add_precision(char *str, t_printf_flags *flags)
{
	int		i;
	int		size;
	char	*dst;
	char	*tmp;

	if (str[0] == '0' && flags->dot && flags->precision == 0)
		return (ft_strjoin_mod("", ""));
	i = 0;
	dst = NULL;
	size = ft_printf_pres_fill_size(str, flags);
	tmp = (char *)malloc((size + 1) * sizeof(char));
	if (tmp)
	{
		while (i < size)
			tmp[i++] = '0';
		tmp[size] = '\0';
		if (str && str[0] == '-')
		{
			tmp[0] = '-';
			str++;
		}
		dst = ft_strjoin_mod(tmp, str);
		free (tmp);
	}
	return (dst);
}

static int	ft_printf_pres_fill_size(char *str, t_printf_flags *flags)
{
	int		sign;
	int		size;

	sign = 0;
	if (str && str[0] == '-')
		sign = 1;
	size = ft_strlen(str) - sign;
	if (flags->precision > size)
		size = flags->precision - size;
	if (flags->precision <= size)
		size = 0;
	return (size + sign);
}

char	*ft_flag_plus_apply(char *nstr, t_printf_flags *flags)
{
	char	*num;

	if (flags->plus && nstr[0] != '-')
	{
		num = ft_strjoin_mod("+", nstr);
	}
	else if (flags->space && nstr[0] != '-')
	{
		num = ft_strjoin_mod(" ", nstr);
	}
	else
	{
		num = ft_strjoin_mod("", nstr);
	}
	return (num);
}

char	*ft_add_minlen(char *nstr, t_printf_flags *flags)
{
	int		len;
	int		fill_size;
	char	*dst;
	char	*tmp;

	len = ft_strlen(nstr);
	fill_size = 0;
	if (flags->min_size > len)
		fill_size = flags->min_size - len;
	tmp = (char *)malloc((fill_size + 1 ) * sizeof(char));
	tmp = ft_fill_minlen(nstr, tmp, fill_size, flags);
	if (!flags->minus)
		dst = ft_strjoin_mod(tmp, nstr);
	if (flags->minus)
		dst = ft_strjoin_mod(nstr, tmp);
	if (dst[fill_size + 1] == 'x' && flags->zero)
	{
		dst[fill_size + 1] = '0';
		dst[1] = 'x';
	}
	free(tmp);
	return (dst);
}

static char	*ft_fill_minlen(char *str, char *tmp, int n, t_printf_flags *flags)
{
	int		i;

	i = 0;
	while (i < n)
	{
		tmp[i] = ' ';
		if (flags->zero && !flags->minus && !flags->dot)
		{
			tmp[i] = '0';
			if (str[0] == '-')
			{
				str[0] = '0';
				tmp[0] = '-';
			}
		}
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
