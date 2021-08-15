/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:30:09 by sde-alva          #+#    #+#             */
/*   Updated: 2021/08/14 21:43:20 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_printf_flags
{
	int	min_size;
	int	precision;
	int	minus;
	int	zero;
	int	dot;
	int	sharp;
	int	space;
	int	plus;
}	t_printf_flags;

int		ft_printf_char(char c, t_printf_flags *flags);
int		ft_printf_str(char *str, t_printf_flags *flags);

char	*ft_add_precision(char *str, t_printf_flags *flags);

int		ft_func_selector(char const **str, va_list args);

int		ft_printf_pointer(unsigned long long paddr, t_printf_flags *flags);
int		ft_printf_id(int n, t_printf_flags *flags);
int		ft_printf_u(unsigned int un, t_printf_flags *flags);
int		ft_printf_xX(unsigned long n, t_printf_flags *flags, char upper);

char	*ft_lltoa_base(long long n, int base);
char	*ft_ulltoa_base(unsigned long long n, int base);
char	*ft_number_flag_apply(char *nstr, t_printf_flags *flags);

int		ft_filler(int num, t_printf_flags *flags);
int		ft_printf_put(char *str, t_printf_flags *flags);
size_t	ft_strlen(char const *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_mod(char const *s1, char const *s2);

int		ft_printf(char const *str, ...);
#endif
