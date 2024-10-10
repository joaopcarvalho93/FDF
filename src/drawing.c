
#include "../includes/fdf.h"

//The purpose of this function is to check if a vertex is inside the frame of the screen.
//The function takes a vertex as an argument.
//The function returns 1 if the vertex is inside the frame of the screen and 0 if it is not.

int	is_inside_frame(t_vertex vertex)
{
	if (vertex.x >= 0 && vertex.x < SCREEN_WIDTH
		&& vertex.y >= 0 && vertex.y < SCREEN_HEIGHT)
		return (1);
	return (0);
}

//The purpose of this function is to render a vertex on the screen.
//The function takes a pointer to the data structure and a vertex as arguments.
//The function calculates the address of the pixel on the screen using the formula:
//address = data->addr + (vertex.y * data->line_length + vertex.x * (data->bits_per_pixel / 8))
//The function then sets the color of the pixel to the color of the vertex using the formula:
//*(unsigned int *)address = vertex.color

void	my_mlx_pixel_put(t_data *data, t_vertex vertex)
{
	char	*address;

	address = data->addr + ((int)round(vertex.y) * data->line_length
			+ (int)round(vertex.x) * (data->bits_per_pixel / 8));
	*(unsigned int *)address = vertex.color;
}

//The purpose of this function is to calculate the new color of a pixel on the screen.
//The function takes the base color, the end color, the number of steps, and the position as arguments.
//The function calculates the incrementor for each color channel using the formula:
//incrementor = (end_color - base_color) / steps
//The function then calculates the new red, green, and blue values using the formula:
//new_red = base_color.red + (incrementor.red * pos)
//new_green = base_color.green + (incrementor.green * pos)
//new_blue = base_color.blue + (incrementor.blue * pos)
//The function returns the new color as an unsigned integer.

static unsigned int	new_color(int base_color, int end_color, int steps, int pos)
{
	unsigned int	color;
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
//The purpose of this function is to draw a line between two points on the screen.
//The function takes a pointer to the data structure and two vertices as arguments.
//The function calculates the number of steps needed to draw the line using the formula:
//steps = max(abs(vertex2.x - vertex1.x), abs(vertex2.y - vertex1.y))
//The function then calculates the x and y increments using the formula:
//x_increment = (vertex2.x - vertex1.x) / steps
//y_increment = (vertex2.y - vertex1.y) / steps
//The function then calculates the base color of the line using the color of the first vertex.
//The function then iterates over the number of steps and calculates the x and y coordinates of each point on the line using the formula:
//x = vertex1.x + (i * x_increment)
//y = vertex1.y + (i * y_increment)
//The function then calculates the new color of the point using the new_color function.
//The function then renders the point on the screen using the my_mlx_pixel_put function.
//The function does not return a value.

void	draw_line(t_data *data, t_vertex vertex1, t_vertex vertex2)
{
	int		base_color;
	int		steps;
	float	x_increment;
	float	y_increment;
	int		i;

	if (abs(vertex2.x - vertex1.x) > abs(vertex2.y - vertex1.y))
		steps = abs(vertex2.x - vertex1.x);
	else
		steps = abs(vertex2.y - vertex1.y);
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

//The purpose of this function is to draw the map on the screen.
//The function takes a pointer to the data structure and a pointer to the map structure as arguments.
//The function iterates over all the vertices in the matrix and renders each vertex on the screen using the my_mlx_pixel_put function.
//The function does not return a value.

void	draw_map(t_data *data, t_map *map)
{
	int		row;
	int		col;
	float	x_increment;
	float	y_increment;

	x_increment = map->line_width / 2;
	y_increment = map->line_height / 2;
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
			if (is_inside_frame(map-> map[row][col]))
				my_mlx_pixel_put(data, map->matrix[row][col]);
			col++;
		}
		row++;
	}
}
//The purpose of this function is to draw lines between the vertices in the matrix to form a grid.
//The function takes a pointer to the data structure and a pointer to the map structure as arguments.
//The function iterates over all the vertices in the matrix and draws lines between adjacent vertices.
//The function calls the draw_line function to draw lines between the vertices.
//The function does not return a value.

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
