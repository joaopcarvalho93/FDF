/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpcarvalho <jpcarvalho@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:18:15 by jhorta-c          #+#    #+#             */
/*   Updated: 2024/10/02 16:28:17 by jpcarvalho       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	int_window(t_map *map, char *filename)
{
	t_mlx	mlx;
	t_data	data;

	map->map_name = filename;
	mlx.mlx = mlx_init();
	check_connection(mlx.mlx);
	mlx.win = mlx_new_window(mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			map->map_name);
	check_window(&mlx);
	data.img = mlx_new_image(mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	check_image(&mlx, data.img);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	mlx_loop(mlx.mlx);
}

void	fdf(char *file)
{
	int		y_max;
	t_map	map;

	y_max = ft_filelen(file);
	map = read_map(file, y_max);
	int_window(&map, file);
	
}
