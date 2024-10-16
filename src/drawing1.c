/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpcarvalho <jpcarvalho@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:50:25 by jhorta-c          #+#    #+#             */
/*   Updated: 2024/10/16 10:10:09 by jpcarvalho       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"


static unsigned int	new_color(int base_color, int end_color, int steps, int pos)
{
	float			incrementor[3];
	int				new_red;
	int				new_green;
	int				new_blue;

	incrementor[0] = ((end_color >> 16) - (base_color >> 16)) / (float)steps;
	incrementor[1] = ((end_color >> 8 & 0xFF) - (base_color >> 8 & 0xFF))
		/ (float)steps;
	incrementor[2] = ((end_color & 0xFF) - (base_color & 0xFF)) / (float)steps;
	new_red = (base_color >> 16) + ((int)roundf(incrementor[0] * pos));
	new_green = (base_color >> 8 & 0xFF) + ((int)roundf(incrementor[1] * pos));
	new_blue = (base_color & 0xFF) + ((int)roundf(incrementor[2] * pos));
	return (new_red << 16 | new_green << 8 | new_blue);
}

void	draw_line(t_data *data, t_vertex vertex1, t_vertex vertex2)
{
	int		base_color;
	int		steps;
	float	x_increment;
	float	y_increment;
	int		i;

	if (fabsf(vertex2.x - vertex1.x) > fabsf(vertex2.y - vertex1.y))
		steps = fabsf(vertex2.x - vertex1.x);
	else
		steps = fabsf(vertex2.y - vertex1.y);
	if (steps <= 0)
		return ;
	x_increment = ((float)vertex2.x - vertex1.x) / (float)steps;
	y_increment = ((float)vertex2.y - vertex1.y) / (float)steps;
	base_color = vertex1.color;
	i = -1;
	while (++i <= steps)
	{
		if (vertex1.x <= SCREEN_WIDTH && vertex1.x >= 0
			&& vertex1.y <= SCREEN_HEIGHT && vertex1.y >= 0)
			my_mlx_pixel_put(data, vertex1);
		vertex1.color = new_color(base_color, vertex2.color, steps, i);
		vertex1.x += x_increment;
		vertex1.y += y_increment;
	}
}


void	draw_map(t_data *data, t_map *map)
{
	int		row;
	int		col;
	float	x_increment;
	float	y_increment;

	x_increment = (map->line_width / 2) * map->zoom;
	y_increment = (map->line_height / 2) * map->zoom;
	row = 0;
	while (row < map -> y_max)
	{
		col = 0;
		while (col < map-> x_max)
		{
			map->matrix[row][col].x = map->start_x + (col * x_increment)
				- (row * x_increment);
			map->matrix[row][col].y = map->start_y + (col * y_increment)
				+ (row * y_increment) - (map->matrix[row][col].value
					* (map->line_height * map-> z_axis));
			if (is_inside_frame(map->matrix[row][col]))
				my_mlx_pixel_put(data, map->matrix[row][col]);
			//else
			//{
				// Optional: Print a message if the vertex is outside the frame
              //  printf("Vertex at row %d, col %d is outside the frame: (%f, %f)\n", row, col, map->matrix[row][col].x, map->matrix[row][col].y);
			//}
			col++;
		}
		row++;
	}
}

void	join_vertex(t_data *data, t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->y_max)
	{
		col = 0;
		while (col < map->x_max)
		{
			if (col + 1 < map->x_max)
				draw_line(data, map->matrix[row][col],
					map->matrix[row][col + 1]);
			if (row + 1 < map->y_max)
				draw_line(data, map->matrix[row][col],
					map->matrix[row + 1][col]);
			col++;
		}
		row++;
	}
}


