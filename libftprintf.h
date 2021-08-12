/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:30:09 by sde-alva          #+#    #+#             */
/*   Updated: 2021/08/11 14:16:00 by sde-alva         ###   ########.fr       */
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

int		ft_printf(const char *str, ...);

int		ft_filler(int num, t_printf_flags flags);
size_t	ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);

int		ft_printf_char(char c, t_printf_flags flags);
int		ft_printf_str(char *str, t_printf_flags flags);
#endif
