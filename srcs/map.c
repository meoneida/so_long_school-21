/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meoneida <meoneida@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:00:37 by meoneida          #+#    #+#             */
/*   Updated: 2021/10/02 04:53:56 by meoneida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_char(t_vars *vars, char *line)
{
	if (*line != '1' || ft_strlen(line) != vars->col)
		return (0);
	while (*(++line))
	{
		if (!ft_strchr(VALID_CHARS, *line))
			return (0);
		if (*line == 'P')
		{
			if (vars->p_count != 0)
				return (0);
			else
				vars->p_count++;
		}
		if (*line == 'C')
			vars->c_count++;
		if (*line == 'E')
			vars->e_count++;
	}
	if (*(line - 1) != '1')
		return (0);
	return (1);
}

static int	is_wall(t_vars *vars)
{
	int	i;

	if (ft_strlen(vars->map[0]) != vars->col \
		|| ft_strlen(vars->map[vars->row - 1]) != vars->col)
		return (0);
	i = -1;
	while (++i < vars->col)
		if (vars->map[0][i] != '1' || vars->map[vars->row - 1][i] != '1')
			return (0);
	return (1);
}

int	map_parsing(int fd, t_vars *vars)
{
	int		i;

	if (!read_fd(fd, vars))
		return (0);
	i = 0;
	if (!is_wall(vars))
		return (0);
	while (i < vars->row - 1)
	{
		if (!valid_char(vars, vars->map[i]))
			return (0);
		i++;
	}
	return (1);
}

void	*sel_img(t_vars *vars, int j, int i)
{
	if (vars->map[j][i] == '1')
		return (vars->img1);
	else if (vars->map[j][i] == 'P')
	{
		vars->x = i;
		vars->y = j;
		return (vars->imgpr);
	}
	else if (vars->map[j][i] == 'C')
		return (vars->imgc);
	else if (vars->map[j][i] == 'U')
		return (vars->imgu);
	else if (vars->map[j][i] == 'E')
		return (vars->imge);
	else
		return (vars->img0);
}

void	draw_map(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vars->col)
	{
		j = -1;
		while (++j < vars->row)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img0,
				i * 32, j * 32);
			if (vars->map[j][i] != '0')
				mlx_put_image_to_window(vars->mlx, vars->win, \
					sel_img(vars, j, i), i * 32, j * 32);
		}
	}
}
