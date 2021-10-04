/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meoneida <meoneida@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:17:53 by meoneida          #+#    #+#             */
/*   Updated: 2021/10/02 04:46:13 by meoneida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	revers(char *ptr, char *ptr1)
{
	char	tmp_char;

	while (ptr1 < ptr)
	{
		tmp_char = *ptr;
		*ptr-- = *ptr1;
		*ptr1++ = tmp_char;
	}
}

char	*ft_itoa(int value, char *result, int base)
{
	char	*ptr;
	char	*ptr1;
	int		tmp_value;

	ptr = result;
	ptr1 = result;
	while (value)
	{
		tmp_value = value;
		value /= base;
		*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789\
			abcdefghijklmnopqrstuvwxyz" \
			[35 + (tmp_value - value * base)];
	}
	if (tmp_value < 0)
		*ptr++ = '-';
	*ptr-- = '\0';
	revers(ptr, ptr1);
	return (result);
}

int	read_fd(int fd, t_vars *vars)
{
	int		i;
	int		j;
	int		res;
	char	ch;

	i = 0;
	ch = '\0';
	while (i < vars->row)
	{
		j = -1;
		while (++j < vars->col)
		{
			res = read(fd, &ch, 1);
			vars->map[i][j] = ch;
		}
		res = read(fd, &ch, 1);
		if (i < vars->row - 1 && ch != '\n')
			return (0);
		if (i == vars->row - 1 && res)
			return (0);
		vars->map[i][j] = '\0';
		i++;
	}
	return (1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if ((*s == '\0') && ((char)c != '\0'))
		return (0);
	return ((char *)s);
}
