/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhorta-c <jhorta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:18:15 by jhorta-c          #+#    #+#             */
/*   Updated: 2024/10/18 18:39:54 by jhorta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	int_window(t_map *map, t_mlx *mlx, t_data *data, char *filename)
{
	map->map_name = filename;
	mlx->win = mlx_new_window(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			map->map_name);
	check_window(mlx);
	data->img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	check_image(mlx, data->img);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (!data->addr)
		ft_error("Failed to get image data address");
}

void	fdf(char *file)
{
	t_map	map;
	t_mlx	mlx;
	t_all	all;
	t_data	data;

	mlx.mlx = mlx_init();
	check_mlx_int(mlx.mlx);
	int_window(&map, &mlx, &data, file);
	init_vars(&map, &mlx, &data, &all);
	read_map(file, &map, &data, &mlx);
	adjust_map_to_screen(&map);
	draw_map(&data, &map);
	join_vertex(&data, &map);
	free_matrix(&map);
	mlx_hook(mlx.win, 17, 1L << 17, close_window, &all);
	mlx_hook(mlx.win, 2, 1L << 0, handle_keypress, &all);
	mlx_put_image_to_window(mlx.mlx, mlx.win, data.img, 0, 0);
	mlx_loop(mlx.mlx);
}
