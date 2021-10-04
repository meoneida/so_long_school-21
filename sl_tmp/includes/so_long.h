/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meoneida <meoneida@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:04:46 by meoneida          #+#    #+#             */
/*   Updated: 2021/10/03 23:06:46 by meoneida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h> 
# include "mlx.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img0;
	void	*img1;
	void	*imgpr;
	void	*imgpl;
	void	*imgpup;
	void	*imgpdwn;
	void	*imgc;
	void	*imge;
	void	*imgu;
	int		col;
	int		row;
	int		p_count;
	int		c_count;
	int		e_count;
	int		x;
	int		y;
	int		exit;
	int		moves;
	int		frames;
}				t_vars;

# define BUFFER_SIZE 1
# define VALID_CHARS "01PCEU"

int		read_fd(int fd, t_vars *vars);
int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_itoa(int value, char *result, int base);
int		check_ext(char *av);
int		get_rows(int fd, t_vars *vars);
int		init_vars(int fd, t_vars *vars);
int		map_parsing(int fd, t_vars *vars);
void	*sel_img(t_vars *vars, int j, int i);
void	draw_map(t_vars *vars);
void	game_loop(t_vars vars);
int		key_hook(int keycode, t_vars *vars);
int		key_hook_bonus(t_vars *vars);
int		cls(int keycode, t_vars *vars);
int		cls_red(int keycode, t_vars *vars);
int		make_step(t_vars *vars, int x, int y, void *img);
int		ft_error(int flag, t_vars *vars);
int		loop_hook(t_vars *vars);

#endif
