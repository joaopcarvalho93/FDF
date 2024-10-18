/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhorta-c <jhorta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:49:21 by jhorta-c          #+#    #+#             */
/*   Updated: 2024/10/17 16:50:36 by jhorta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_vars(t_map *map, t_mlx *mlx, t_data *data, t_all *all)
{
	map->start_x = SCREEN_WIDTH * 0.5;
	map->start_y = SCREEN_HEIGHT * 0.2;
	map->zoom = 1.0;
	map->rotation_x = DEGREE_60;
	map->rotation_y = DEGREE_60;
	map->z_axis = 0.5;
	all->map = map;
	all->mlx = mlx;
	all->data = data;
	map->line_width = LINE_WIDTH;
	map->line_height = LINE_HEIGHT;
}
