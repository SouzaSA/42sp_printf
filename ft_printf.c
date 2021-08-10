/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:29:42 by sde-alva          #+#    #+#             */
/*   Updated: 2021/08/09 21:24:00 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		printed;
	int		i;

	va_start(args, str);
	printed = 0;
	i = 0;
	while (*str != '\0')
	{
		if (*str == '%')

	}
	return (printed);
}
