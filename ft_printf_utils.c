/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:39:44 by sde-alva          #+#    #+#             */
/*   Updated: 2021/08/11 20:42:22 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_filler(int num, t_printf_flags flags)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (flags.zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
	}
	return (i);
}

int	ft_printf_put(char *str, t_printf_flags flags)
{
	int	i;
	int	str_len;

	i = 0;
	str_len = ft_strlen(str);
	if (flags.minus)
	{
		while (*str++)
		{
			write(1, str, 1);
			str++;
		}
		i = ft_filler(flags.before_dot - str_len, flags);
	}
	else
	{
		i = ft_filler(flags.before_dot - str_len, flags);
		while (*str++)
		{
			write(1, str, 1);
			str++;
		}
	}
	return (i + str_len);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*match;
	int		i;

	i = 0;
	match = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			match = (char *)s + i;
			break ;
		}
		i++;
	}
	if (c == '\0')
		match = (char *)s + i;
	return (match);
}

char	*ft_strjoin_mod(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*dst;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (dst)
	{
		while (i < s1_len || i < s2_len)
		{
			if (i < s1_len)
				dst[i] = s1[i];
			if (i < s2_len)
				dst[i + s1_len] = s2[i];
			i++;
		}
		dst[s1_len + s2_len] = '\0';
	}
	return (dst);
}
