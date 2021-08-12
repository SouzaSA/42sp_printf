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
	char	zero;
	char	dot;
	char	sharp;
	char	space;
	char	plus;
}	t_printf_flags;

int		ft_printf_char(char c, t_printf_flags flags);
int		ft_printf_str(char *str, t_printf_flags flags);

int		ft_func_selector(char const **str, va_list args);

int		ft_printf_pointer(long long paddr, t_printf_flags flags);
int		ft_printf_id(int n, t_printf_flags flags);
int		ft_printf_u(unsigned int un, t_printf_flags flags);
int		ft_printf_xX(long long n, t_printf_flags flags, char upper);

char	*ft_lltoa_base(long long n, int base);
char	*ft_number_flag_apply(char *nstr, t_printf_flags flags);

int		ft_filler(int num, t_printf_flags flags);
int		ft_printf_put(char *str, t_printf_flags flags);
size_t	ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_mod(char const *s1, char const *s2);

int		ft_printf(char const *str, ...);
#endif
