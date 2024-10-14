
#include "../include/fdf.h"


int	is_inside_frame(t_vertex vertex)
{
	printf("vertex.x: %f, vertex.y: %f\n", vertex.x, vertex.y); //teste

	if (vertex.x >= 0 && vertex.x < SCREEN_WIDTH
		&& vertex.y >= 0 && vertex.y < SCREEN_HEIGHT)
		return (1);
	return (0);
}


void	my_mlx_pixel_put(t_data *data, t_vertex vertex)
{
	char	*address;

	printf("vertex.x: %f, vertex.y: %f\n", vertex.x, vertex.y); //teste
	printf("line_length: %d, bits_per_pixel: %d\n", data->line_length, data->bits_per_pixel); //teste

	address = data->addr + ((int)round(vertex.y) * data->line_length
			+ (int)round(vertex.x) * (data->bits_per_pixel / 8));
	*(unsigned int *)address = vertex.color;
	printf("passou\n"); //teste
}
