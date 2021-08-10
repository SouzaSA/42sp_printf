/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:30:09 by sde-alva          #+#    #+#             */
/*   Updated: 2021/08/09 20:17:02 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_printf_flags
{
	int		before_dot;
	int		after_dot;
	char	minus;
	char	zeros;
	char	dot;
	char	sharp;
	char	space;
	char	plus;
}	t_printf_flags;

int	ft_printf(const char *str, ...);
#endif