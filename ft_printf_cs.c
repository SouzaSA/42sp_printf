/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 19:28:11 by sde-alva          #+#    #+#             */
/*   Updated: 2021/08/15 15:45:38 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf_char(char c, t_printf_flags *flags)
{
	int	i;

	i = 0;
	if (flags->minus)
	{
		write(1, &c, 1);
		i = ft_filler(flags->min_size - 1, flags);
	}
	else
	{
		i = ft_filler(flags->min_size - 1, flags);
		write(1, &c, 1);
	}
	return (i + 1);
}

int	ft_printf_str(char *str, t_printf_flags *flags)
{
	int		i;
	int 	len;
	char	*prt;

	if (str)
		prt = ft_strjoin_mod("", str);
	if( !str)
		prt = ft_strjoin_mod("", "(null)");
	len = ft_strlen(prt);
	if (flags->dot && flags->precision < len)
	{
		prt[flags->precision] = '\0';
	}
	i = ft_printf_put(prt, flags);
	free(prt);
	return (i);
}
