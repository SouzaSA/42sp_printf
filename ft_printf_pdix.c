/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:12:09 by sde-alva          #+#    #+#             */
/*   Updated: 2021/08/11 14:41:31 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf_pointer(long long paddr, t_printf_flags flags)
{
	int		n_printed;
	char	*str_addr;
	char	*tmp;

	tmp = ft_lltoa_base(paddr, 16);
	str_addr = ft_strjoin_mod("0x", tmp);
	free(tmp);
	tmp = NULL;
	n_printed = ft_printf_put(str_addr, flags);
	free(str_addr);
	str_addr = NULL;
	return (n_printed);
}

int	ft_printf_id(int n, t_printf_flags flags)
{
	int		n_printed;
	char	*num;
	char	*tmp;

	tmp = ft_lltoa_base((long long)n, 10);
	num = ft_number_flag_apply(tmp, flags);
	free(tmp);
	tmp = NULL;
	n_printed = ft_printf_put(num, flags);
	free(num);
	num = NULL;
	return (n_printed);
}

int	ft_printf_u(unsigned int un, t_printf_flags flags)
{
	int		n_printed;
	char	*u_num;
	char	*tmp;

	tmp = ft_lltoa_base((long long)un, 10);
	u_num = ft_number_flag_apply(tmp, flags);
	free(tmp);
	tmp = NULL;
	n_printed = ft_printf_put(u_num, flags);
	free(num);
	num = NULL;
	return (n_printed);
}

int	ft_printf_xX(long long n, t_printf_flags flags, char upper)
{
	int		i;
	int		n_printed;
	char	*x_num;
	char	*tmp;

	i = 0;
	tmp = ft_lltoa_base((long long)un, 16);
	x_num = ft_number_flag_apply(tmp, flags);
	free(tmp);
	tmp = NULL;
	if (upper)
	{
		while (x_num[i] != '\0')
		{
			if (x_num[i] >= 'a' && x_num[i] <= 'f')
				x_num[i] -= 32;
		}
	}
	n_printed = ft_printf_put(x_num, flags);
	free(num);
	num = NULL;
	return (n_printed);
}
