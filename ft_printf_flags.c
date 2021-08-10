/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:48:13 by sde-alva          #+#    #+#             */
/*   Updated: 2021/08/09 21:23:57 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void ft_init_t_flag(t_printf_flags *flags);

int	 ft_func_selector(char *str)
{
	int				i;
	char			*identifiers;
	t_printf_flags	flags;

	i = 0;
	identifiers = "cspdiuxX-0.# +";
	ft_init_t_flag(&flags);
	while ()
}

static void ft_init_t_flag(t_printf_flags *flags)
{
	flags->before_dot = 0;
	flags->after_dot = 0;
	flags->minus = 0;
	flags->zeros = 0;
	flags->dot = 0;
	flags->sharp = 0;
	flags->space = 0;
	flags->plus = 0;
}
