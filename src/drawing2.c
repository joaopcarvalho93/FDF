
#include "../include/fdf.h"

//The purpose of this function is to check if a
// vertex is inside the frame of the screen.
//The function takes a vertex as an argument.
//The function returns 1 if the vertex is inside 
//the frame of the screen and 0 if it is not.

int	is_inside_frame(t_vertex vertex)
{
	if (vertex.x >= 0 && vertex.x < SCREEN_WIDTH
		&& vertex.y >= 0 && vertex.y < SCREEN_HEIGHT)
		return (1);
	return (0);
}

//The purpose of this function is to render a vertex on the screen.
//The function takes a pointer to the data structure and a vertex as arguments.
//The function calculates the address of the pixel on 
//the screen using the formula:
//address = data->addr + (vertex.y * data->line_length + 
//vertex.x * (data->bits_per_pixel / 8))
//The function then sets the color of the pixel to the color
// of the vertex using the formula:
//*(unsigned int *)address = vertex.color

void	my_mlx_pixel_put(t_data *data, t_vertex vertex)
{
	char	*address;

	address = data->addr + ((int)round(vertex.y) * data->line_length
			+ (int)round(vertex.x) * (data->bits_per_pixel / 8));
	*(unsigned int *)address = vertex.color;
}

//The purpose of this function is to calculate the
// new color of a pixel on the screen.
//The function takes the base color, the end color, the
// number of steps, and the position as arguments.
//The function calculates the incrementor for each color
// channel using the formula:
//incrementor = (end_color - base_color) / steps
//The function then calculates the new red, green, and 
//blue values using the formula:
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