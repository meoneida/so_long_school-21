/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meoneida <meoneida@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 23:13:02 by meoneida          #+#    #+#             */
/*   Updated: 2021/10/03 23:13:10 by meoneida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	img_call(t_vars *vars, void *img)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img0, vars->x * 32, vars->y * 32);
	mlx_put_image_to_window(vars->mlx, vars->win,
		img, vars->x * 32, vars->y * 32 );
}

int	loop_hook(t_vars *vars)
{
	vars->frames++;
	if (vars->frames == 500000)
		img_call(vars, vars->imgpr);
	if (vars->frames == 1000000)
	{
		img_call(vars, vars->imgpl);
		vars->frames = 0;
	}
	return (1);
}
