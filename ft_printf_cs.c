/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 19:28:11 by sde-alva          #+#    #+#             */
/*   Updated: 2021/08/13 15:40:18 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf_char(char c, t_printf_flags flags)
{
	int	i;

	i = 0;
	if (flags.minus)
	{
		write(1, &c, 1);
		i = ft_filler(flags.before_dot - 1, flags);
	}
	else
	{
		i = ft_filler(flags.before_dot - 1, flags);
		write(1, &c, 1);
	}
	return (i + 1);
}

int	ft_printf_str(char *str, t_printf_flags flags)
{
	int	i;

	if (str)
		i = ft_printf_put(str, flags);
	if (!str)
		i = ft_printf_put("(null)", flags);
	return (i);
}
