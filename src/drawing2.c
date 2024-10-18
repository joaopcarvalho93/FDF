/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhorta-c <jhorta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:36:39 by jhorta-c          #+#    #+#             */
/*   Updated: 2024/10/18 19:11:13 by jhorta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

unsigned int	calculate_color_based_on_value(int z_value, t_map *map)
{
	float	normalized_value;
	t_rgb	rgb;

	if (z_value == map->z_min)
		return (0x0000FF);
	if (map->z_max == map->z_min)
		return (0x00FF);
	normalized_value = (float)(z_value - map->z_min)
		/ (map->z_max - map->z_min);
	if (normalized_value < 0.5)
	{
		rgb.red = 0;
		rgb.green = (int)(normalized_value * 2 * 255);
		rgb.blue = 255 - rgb.green;
	}
	else
	{
		rgb.red = (int)((normalized_value - 0.5) * 2 * 255);
		rgb.green = 255 - rgb.red;
		rgb.blue = 0;
	}
	return (rgb.red << 16 | rgb.green << 8 | rgb.blue);
}

int	is_inside_frame(t_vertex vertex)
{
	if (vertex.x >= 0 && vertex.x < SCREEN_WIDTH
		&& vertex.y >= 0 && vertex.y < SCREEN_HEIGHT)
		return (1);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, t_vertex vertex)
{
	char	*address;

	address = data->addr + ((int)round(vertex.y) * data->line_length
			+ (int)round(vertex.x) * (data->bits_per_pixel / 8));
	*(unsigned int *)address = vertex.color;
}

void	adjust_map_to_screen(t_map *map)
{
	int	tile_1;
	int	tile_2;

	map->width = SCREEN_WIDTH * map->zoom;
	tile_1 = map -> width * 0.5 / cos(DEGREE_30) / map->x_max;
	tile_2 = map -> width * 0.5 / cos(DEGREE_30) / map->y_max;
	map->edge = fmin(tile_1, tile_2);
	map->tile_height = (int)roundf((cos(map->rotation_y) * map->edge) * 2);
	map->tile_width = (int)roundf((sin(map->rotation_x) * map->edge) * 2);
}
// while((map->x_max * map->tile_width) > (SCREEN_WIDTH - map->start_x))
	// {
	// 	map->tile_width = map->tile_width * 0.2;
	// }
	// while (((map->y_max * map->tile_height))
	// > (SCREEN_HEIGHT - map->start_y))
	// {
	// 	map->tile_height = map->tile_height * 0.2;
	// }