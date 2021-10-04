/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meoneida <meoneida@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 00:44:59 by meoneida          #+#    #+#             */
/*   Updated: 2021/10/03 21:54:45 by meoneida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_rows(int fd, t_vars *vars)
{
	int		i;
	int		j;
	int		ret;
	char	tmp;

	i = 0;
	j = 0;
	tmp = 'a';
	ret = -1;
	while (ret)
	{
		ret = read(fd, &tmp, 1);
		if (ret == -1)
			return (0);
		if (tmp == '\n')
			i++;
		if (!i)
			j++;
	}
	vars->row = i + 1;
	vars->col = j;
	close(fd);
	return (1);
}

int	check_ext(char *av)
{
	ssize_t	len;

	len = ft_strlen(av);
	if (len < 5)
		return (0);
	if (av[len - 4] != '.' || av[len - 3] != 'b'\
	 || av[len - 2] != 'e' || av[len - 1] != 'r')
		return (0);
	else
		return (1);
}

int	ft_error(int flag, t_vars *vars)
{
	int	i;

	if (flag == 0)
		write(1, "Error\nwrong number of args\n", 27);
	if (flag == 1)
	{
		i = -1;
		while (++i < vars->row && vars->map[i])
		{
			free(vars->map[i]);
			vars->map[i] = NULL;
		}
		free(vars->map);
		vars->map = NULL;
		write(1, "Error\nmap_is_not_valid\n", 23);
	}
	if (flag == 2)
		write(1, "Error\nbad_extention\n", 20);
	return (0);
}

int	cls(int keycode, t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->row && vars->map[i])
	{
		free(vars->map[i]);
		vars->map[i] = NULL;
	}
	free(vars->map);
	vars->map = NULL;
	mlx_destroy_image(vars->mlx, vars->img0);
	mlx_destroy_image(vars->mlx, vars->img1);
	mlx_destroy_image(vars->mlx, vars->imgpr);
	mlx_destroy_image(vars->mlx, vars->imgpl);
	mlx_destroy_image(vars->mlx, vars->imgpup);
	mlx_destroy_image(vars->mlx, vars->imgpdwn);
	mlx_destroy_image(vars->mlx, vars->imgc);
	mlx_destroy_image(vars->mlx, vars->imge);
	mlx_destroy_image(vars->mlx, vars->imgu);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	(void)keycode;
	exit(0);
	return (0);
}

int	cls_red(int keycode, t_vars *vars)
{
	(void)vars;
	(void)keycode;
	exit(0);
	return (0);
}
