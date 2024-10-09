
#include "fdf.h"

int	handle_keypress(int keycode, t_all *all)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(all->mlx->mlx, all->mlx->win);
		exit(0);
	}
	if (keycode == UP)
		all->map->start_y -= 10;
	if (keycode == DOWN)
		all->map->start_y += 10;
	if (keycode == LEFT)
		all->map->start_x -= 10;
	if (keycode == RIGHT)
		all->map->start_x += 10;
	if (keycode == ZOOM_IN)
		all->map->zoom += 0.1;
	if (keycode == ZOOM_OUT)
		all->map->zoom -= 0.1;
	mlx_clear_window(all->mlx->mlx, all->mlx->win);
	draw_map(all->data, all->map);
	join_vertex(all->data, all->map);
	return (0);
}
