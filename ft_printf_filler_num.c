/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_filler_num.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:32:35 by sde-alva          #+#    #+#             */
/*   Updated: 2021/08/14 20:07:57 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_printf_pres_fill_size(char *str, t_printf_flags *flags);

char	*ft_add_precision(char *str, t_printf_flags *flags)
{
	int		i;
	int		size;
	char	*dst;
	char	*tmp;

	i = 0;
	dst = str;
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
		size = 1;
	return (size);
}
