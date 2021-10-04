/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meoneida <meoneida@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:01:15 by meoneida          #+#    #+#             */
/*   Updated: 2021/10/03 23:15:42 by meoneida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_vars(int fd, t_vars *vars)
{
	int	i;

	vars->map = NULL;
	if (!get_rows(fd, vars))
		return (0);
	vars->map = (char **)malloc(sizeof(char *) * vars->row);
	if (!vars->map)
		return (0);
	i = -1;
	while (++i < vars->row)
	{
		vars->map[i] = NULL;
		vars->map[i] = (char *)malloc(sizeof(char) * (vars->col + 1));
		if (!vars->map[i])
			return (0);
	}
	vars->p_count = 0;
	vars->c_count = 0;
	vars->e_count = 0;
	vars->moves = 0;
	vars->x = 0;
	vars->y = 0;
	vars->exit = 0;
	vars->frames = 0;
	return (1);
}

int	make_step(t_vars *vars, int x, int y, void *img_out)
{
	void	*img_in;
	char	s[11];

	if (vars->exit == 0)
		img_in = vars->img0;
	else if (vars->exit == 1)
		img_in = vars->imge;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img0,
		vars->x * 32, vars->y * 32);
	mlx_put_image_to_window(vars->mlx, vars->win, img_in,
		vars->x * 32, vars->y * 32);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img0,
		vars->x * 32 + x * 32, vars->y * 32 + y * 32);
	mlx_put_image_to_window(vars->mlx, vars->win, img_out,
		vars->x * 32 + x * 32, vars->y * 32 + y * 32);
	vars->x += x;
	vars->y += y;
	vars->moves++;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img0, 0, 0);
	mlx_string_put(vars->mlx, vars->win, 10, 20, 0, \
		ft_itoa(vars->moves, s, 10));
	printf("moves - %d, collect - %d \n", vars->moves, vars->c_count);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (vars->map[vars->y][vars->x] == 'E' && vars->c_count)
		vars->exit = 1;
	else
		vars->exit = 0;
	if (keycode == 'a' && vars->map[vars->y][vars->x - 1] != '1')
		make_step(vars, -1, 0, vars->imgpl);
	if (keycode == 'd' && vars->map[vars->y][vars->x + 1] != '1')
		make_step(vars, 1, 0, vars->imgpr);
	if (keycode == 'w' && vars->map[vars->y - 1][vars->x] != '1')
		make_step(vars, 0, -1, vars->imgpup);
	if (keycode == 's' && vars->map[vars->y + 1][vars->x] != '1')
		make_step(vars, 0, 1, vars->imgpdwn);
	if (vars->map[vars->y][vars->x] == 'C')
	{
		vars->c_count--;
		vars->map[vars->y][vars->x] = '0';
	}
	if (keycode == 65307 || keycode == 'q' || keycode == 'Q'\
		|| (vars->map[vars->y][vars->x] == 'E' && !vars->c_count) \
		|| (vars->map[vars->y][vars->x] == 'U'))
		cls(keycode, vars);
	return (0);
}

void	game_loop(t_vars vars)
{
	int		h;
	int		w;

	vars.img0 = mlx_xpm_file_to_image(vars.mlx, "imgs/img0.xpm", &w, &h);
	vars.img1 = mlx_xpm_file_to_image(vars.mlx, "imgs/img1.xpm", &w, &h);
	vars.imgpr = mlx_xpm_file_to_image(vars.mlx, "imgs/imgpr.xpm", &w, &h);
	vars.imgpl = mlx_xpm_file_to_image(vars.mlx, "imgs/imgpl.xpm", &w, &h);
	vars.imgpup = mlx_xpm_file_to_image(vars.mlx, "imgs/imgpup.xpm", &w, &h);
	vars.imgpdwn = mlx_xpm_file_to_image(vars.mlx, "imgs/imgpdwn.xpm", &w, &h);
	vars.imgc = mlx_xpm_file_to_image(vars.mlx, "imgs/imgc.xpm", &w, &h);
	vars.imge = mlx_xpm_file_to_image(vars.mlx, "imgs/imge.xpm", &w, &h);
	vars.imgu = mlx_xpm_file_to_image(vars.mlx, "imgs/imgu.xpm", &w, &h);
	draw_map(&vars);
	mlx_loop_hook(vars.mlx, loop_hook, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 17, cls_red, &vars);
	mlx_loop(vars.mlx);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_vars	vars;

	if (argc != 2)
		return (ft_error(0, NULL));
	if (!check_ext(argv[1]))
		return (ft_error(2, NULL));
	fd = open(*(argv + 1), O_RDONLY);
	if (!init_vars(fd, &vars))
		return (0);
	fd = open(*(argv + 1), O_RDONLY);
	if (!map_parsing(fd, &vars) || !vars.p_count || !vars.e_count)
		return (ft_error(1, &vars));
	vars.mlx = NULL;
	vars.win = NULL;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx,
			vars.col * 32, vars.row * 32, "so_long");
	close(fd);
	game_loop(vars);
}
