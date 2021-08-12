/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:29:42 by sde-alva          #+#    #+#             */
/*   Updated: 2021/08/11 20:06:48 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		printed;

	va_start(args, str);
	printed = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			printed += ft_func_selector(&str, args);
		}
		else
		{
			write(1, str, 1);
			printed++;
		}
		str++;
	}
	va_end(args);
	return (printed);
}
