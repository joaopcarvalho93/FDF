/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpcarvalho <jpcarvalho@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:49:21 by jhorta-c          #+#    #+#             */
/*   Updated: 2024/10/16 16:17:06 by jpcarvalho       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_vars(t_map *map, t_mlx *mlx, t_data *data, t_all *all)
{
	map->start_x = SCREEN_WIDTH * 0.5;
	map->start_y = SCREEN_HEIGHT * 0.2;
	map->zoom = 1.0;
	map->rotation_x = 1.0472; // 60 degrees in radians 0.523599 30 degrees
	map->rotation_y = 1.0472; //60 degrees in radians 0.523599 30 degrees
	map->z_axis = 0.8;
	all->map = map;
	all->mlx = mlx;
	all->data = data;
	map->line_width = LINE_WIDTH;
	map->line_height = LINE_HEIGHT;
}
