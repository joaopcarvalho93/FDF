
#include "../include/fdf.h"

unsigned int	calculate_color_based_on_value(int z_value, t_map *map)
{
	float	normalized_value;
	t_rgb	rgb;

	if (z_value == map->z_min)
		return (0x0000FF); // Blue for the base level

	if (map->z_max == map->z_min)
		return (0x00FF); // Return white if all heights are the same

	normalized_value = (float)(z_value - map->z_min) / (map->z_max - map->z_min);

	// Define a gradient from blue (low) to green (medium) to red (high)
	if (normalized_value < 0.5)
	{
		// Gradient from blue (0x0000FF) to green (0x00FF00)
		rgb.red = 0;
		rgb.green = (int)(normalized_value * 2 * 255); // Double the normalized value for green
		rgb.blue = 255 - rgb.green; // Inverse for blue
	}
	else
	{
		// Gradient from green (0x00FF00) to red (0xFF0000)
		rgb.red = (int)((normalized_value - 0.5) * 2 * 255);
		rgb.green = 255 - rgb.red;
		rgb.blue = 0;
	}

	// Combine RGB into an unsigned int color (0xRRGGBB)
	return (rgb.red << 16 | rgb.green << 8 | rgb.blue);
}


int	is_inside_frame(t_vertex vertex)
{
	//printf("vertex.x: %f, vertex.y: %f\n", vertex.x, vertex.y); //teste

	if (vertex.x >= 0 && vertex.x < SCREEN_WIDTH
		&& vertex.y >= 0 && vertex.y < SCREEN_HEIGHT)
		return (1);
	return (0);
}



void	my_mlx_pixel_put(t_data *data, t_vertex vertex)
{
	char	*address;

//	printf("vertex.x: %f, vertex.y: %f\n", vertex.x, vertex.y); //teste
//	printf("line_length: %d, bits_per_pixel: %d\n", data->line_length, data->bits_per_pixel); //teste

	address = data->addr + ((int)round(vertex.y) * data->line_length
			+ (int)round(vertex.x) * (data->bits_per_pixel / 8));
	*(unsigned int *)address = vertex.color;
	//printf("passou\n"); //teste
}


// void adjust_map_to_screen(t_map *map) 
// {
//     float max_x_size;
//     float max_y_size;
// 	float zoom_x;
// 	float zoom_y;
// 	int	min_tile_size;
// 	int tile_size1;
// 	int tile_size2;

// 	max_x_size = map->x_max * map->line_width;
// 	max_y_size = map->y_max * map->line_height;
//     zoom_x = SCREEN_WIDTH / max_x_size;
//     zoom_y = SCREEN_HEIGHT / max_y_size;
//     map->zoom = fmin(1, fmin(zoom_x, zoom_y));

//     map->line_width = map->line_width * map->zoom;
//     map->line_height = map->line_height * map->zoom;
// 	tile_size1 = (SCREEN_WIDTH * 0.5) / (map->x_max - 1);
//     tile_size2 = (SCREEN_HEIGHT * 0.5) / (map->y_max - 1);
// 	min_tile_size = 5;
//     map->edge = fmax(min_tile_size, fmin(tile_size1, tile_size2));

// 	map->line_width = map->edge * map->zoom;
// 	map->line_height = map->edge * map->zoom;

// 	// map->start_x = (SCREEN_WIDTH - (map->x_max * map->line_width)) / 2;
//     // map->start_y = (SCREEN_HEIGHT - (map->y_max * map->line_height)) / 2;
// }

void adjust_map_to_screen(t_map *map)
{
	while((map->x_max * map->line_width) > (SCREEN_WIDTH - map->start_x))
	{
		map->line_width /= 2;
		//map->z_axis -= 0.2;
	}
	while (((map->y_max * map->line_height)) > (SCREEN_HEIGHT - map->start_y))
	{
		map->line_height /= 2;
	}
	// map->start_x = (SCREEN_WIDTH - (map->x_max * map->line_width)) / 2;
	// map->start_y = (SCREEN_HEIGHT - (map->y_max * map->line_height)) / 2;
}
