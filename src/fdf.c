/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpcarvalho <jpcarvalho@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:18:15 by jhorta-c          #+#    #+#             */
/*   Updated: 2024/10/09 18:40:42 by jpcarvalho       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	int_window(t_map *map, t_mlx *mlx, char *filename)
{
	t_data	data;

	map->map_name = filename;
	check_connection(mlx->mlx);
	mlx->win = mlx_new_window(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			map->map_name);
	check_window(&mlx);
	data.img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	check_image(&mlx, data.img);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
}

void	fdf(char *file)
{
	int		y_max;
	t_map	map;
	t_mlx	mlx;
	t_all	all;
	t_data	data;
	
	mlx.mlx = mlx_init();
	y_max = ft_filelen(file);
	read_map(file, y_max, &map);
	init_vars(&map, &mlx, &data, &all);
	int_window(&map, &mlx, file);
	draw_map(&data, &map);
	join_vertex(&data, &map);
	free_matrix(&map);
	mlx_hook(mlx.win, 17, 1L << 17, close_window, &all);
	mlx_hook(mlx.win, 2, 1L << 0, handle_keypress, &all);
	mlx_loop(mlx.mlx);
	
}
