/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pdix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:12:09 by sde-alva          #+#    #+#             */
/*   Updated: 2021/08/18 15:01:59 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_upper_str(char *str);

int	ft_printf_pointer(unsigned long paddr, t_printf_flags *flags)
{
	int		n_printed;
	char	*str_addr;
	char	*tmp;

	tmp = ft_ulltoa_base(paddr, 16);
	str_addr = ft_add_precision(tmp, flags);
	free(tmp);
	if (!flags->zero)
	{
		tmp = ft_strjoin_mod("0x", str_addr);
		free (str_addr);
		str_addr = tmp;
	}
	tmp = ft_add_minlen(str_addr, flags);
	free(str_addr);
	str_addr = tmp;
	if (flags->zero)
	{
		str_addr = ft_strjoin_mod("0x", tmp);
		free(tmp);
	}
	n_printed = ft_printf_put(str_addr, flags);
	free(str_addr);
	return (n_printed);
}

int	ft_printf_id(int n, t_printf_flags *flags)
{
	int		n_printed;
	char	*num;
	char	*tmp;

	tmp = ft_lltoa_base((long long)n, 10);
	num = ft_add_precision(tmp, flags);
	free(tmp);
	tmp = ft_flag_plus_apply(num, flags);
	free(num);
	num = ft_add_minlen(tmp, flags);
	free(tmp);
	n_printed = ft_printf_put(num, flags);
	free(num);
	return (n_printed);
}

int	ft_printf_u(unsigned int un, t_printf_flags *flags)
{
	int		n_printed;
	char	*u_num;
	char	*tmp;

	tmp = ft_ulltoa_base((unsigned long)un, 10);
	u_num = ft_add_precision(tmp, flags);
	free (tmp);
	tmp = ft_flag_plus_apply(u_num, flags);
	free(u_num);
	u_num = ft_add_minlen(tmp, flags);
	free(tmp);
	n_printed = ft_printf_put(u_num, flags);
	free(u_num);
	u_num = NULL;
	return (n_printed);
}

int	ft_printf_xX(unsigned int n, t_printf_flags *flags, char upper)
{
	int		n_printed;
	char	*x_num;
	char	*tmp;

	tmp = ft_ulltoa_base((unsigned long long)n, 16);
	x_num = ft_add_precision(tmp, flags);
	free(tmp);
	tmp = ft_flag_plus_apply(x_num, flags);
	free(x_num);
	x_num = ft_add_minlen(tmp, flags);
	free(tmp);
	tmp = x_num;
	if (flags->sharp && n != 0)
	{
		x_num = ft_strjoin_mod("0x", tmp);
		free(tmp);
	}
	if (upper)
		ft_upper_str(x_num);
	n_printed = ft_printf_put(x_num, flags);
	free(x_num);
	x_num = NULL;
	return (n_printed);
}

static void	ft_upper_str(char *str)
{
	while (str && *str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}
