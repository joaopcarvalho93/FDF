
#include "fdf.h"

void	init_vars(t_map *map, t_mlx *mlx, t_data *data, t_all *all)
{
	map->start_x = SCREEN_WIDTH / 2;
	map->start_y = SCREEN_HEIGHT / 2;
	map->zoom = 1;
	map->rotation_x = 0.523599; // 30 degrees in radians
	map->rotation_y = 0.523599; // 30 degrees in radians
	map->z_axis = 0.8;
	all->map = map;
	all->mlx = mlx;
	all->data = data;
	map->line_width = LINE_WIDTH;
	map->line_height = LINE_HEIGHT;
}
