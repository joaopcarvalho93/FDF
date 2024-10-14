
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
