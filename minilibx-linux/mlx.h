/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meoneida <meoneida@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:02:22 by meoneida          #+#    #+#             */
/*   Updated: 2021/09/28 01:08:25 by meoneida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_H
# define MLX_H

void	*mlx_init(void);
void	*mlx_new_window(void *mlx_ptr, int width, int height, \
			char *title);
void	*mlx_new_image(void *mlx_ptr, int width, int height);
int		*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
			int *size_line, int *endian);
int		mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y,
			int color);
int		mlx_hook(void *mlx, int x_event, int x_mask, \
			int (*funct)(), void *param);
int		mlx_loop(void *mlx_ptr);
int		mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);
int		mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int		mlx_clear_window(void *mlx_ptr, void *win_ptr);
int		mlx_get_screen_size(void *mlx, int *screen_res_x, int *screen_res_y);
int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr,
			void *img_ptr, int x, int y);
void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
			       int *width, int *height);
int		mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y,
			int color, char *string);
int		mlx_destroy_image(void *mlx_ptr, void *mlx_img);
int		mlx_destroy_window(void *mlx_ptr, void *win_ptr);

#endif
