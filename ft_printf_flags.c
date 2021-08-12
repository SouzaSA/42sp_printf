/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:48:13 by sde-alva          #+#    #+#             */
/*   Updated: 2021/08/11 21:12:16 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_init_t_flag(t_printf_flags *flags);
static void	ft_get_flags(t_printf_flags *flags, char **str);
static void	ft_set_flags(t_printf_flags *flags, char c);

int	ft_func_selector(char **str, va_list args)
{
	int				i;
	t_printf_flags	flags;

	i = 0;
	ft_init_flags(&flags);
	ft_get_flags(&flags, &str);
	if (*str == 'c')
		i = ft_printf_char(va_arg(args, char), flags);
	if (*str == 's')
		i = ft_printf_str(va_arg(args, (char *)), flags);
	if (*str == 'p')
		i = ft_printf_pointer(va_arg(args, long long), flags);
	if (*str == 'd' || *str == 'i')
		i = ft_printf_id(iva_arg(args, int), flags);
	if (*str == 'u')
		i = ft_printf_u(va_arg(args, unsigned int), flags);
	if (*str == 'x')
		i = ft_printf_xX(va_arg(args, long long), flags, 0);
	if (*str == 'X')
		i = ft_printf_xX(va_arg(args, long long), flags, 1);
	if (*str == '%')
		i = ft_printf_put(char *str, flags);
	return (i);
}

static void	ft_init_flags(t_printf_flags *flags)
{
	flags->before_dot = 0;
	flags->after_dot = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->sharp = 0;
	flags->space = 0;
	flags->plus = 0;
}

static void	ft_get_flags(t_printf_flags *flags, char **str)
{
	int		i;
	char	*flags;
	char	*descriptors;

	i = 0;
	flags = "0123456789-0.# +";
	descriptors = "cspdiuxX";
	while (ft_strchr(flags, str[i]) && ft_strchr(descriptors, str[i]))
	{
		ft_set_flags(flags, c);
		i++;
	}
}

static void	ft_set_flags(t_printf_flags *flags, char c)
{
	if (c > '0' && c <= '9' && !flags->dot)
		flags->before_dot = flags->before_dot * 10 + c - '0';
	if (c > '0' && c <= '9' && flags->dot)
		flags->after_dot = flags->after_dot * 10 + c - '0';
	if (c == '-')
		flags->minus++;
	if (c == '0')
		flags->zero++;
	if (c == '.')
		flags->dot++;
	if (c == '#')
		flags->sharp++;
	if (c == ' ')
		flags->space++;
	if (c == '+')
		flags->plus++;
}
