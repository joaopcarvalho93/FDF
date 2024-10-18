/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhorta-c <jhorta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:49:21 by jhorta-c          #+#    #+#             */
/*   Updated: 2024/10/18 15:46:58 by jhorta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_vars(t_map *map, t_mlx *mlx, t_data *data, t_all *all)
{
	map->z_max = INT_MIN;
	map->z_min = INT_MAX;
	map->x_max = 0;
	map->y_max = 0;
	map->start_x = SCREEN_WIDTH * 0.5;
	map->start_y = SCREEN_HEIGHT * 0.2;
	map->zoom = 0.8;
	map->rotation_x = DEGREE_60;
	map->rotation_y = DEGREE_60;
	map->z_axis = 0.6;
	all->map = map;
	all->mlx = mlx;
	all->data = data;
	map->tile_width = TILE_WIDTH;
	map->tile_height = TILE_HEIGHT;
}
