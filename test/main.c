




#include <stdlib.h>
#include "../lib/mlx_linux/mlx.h"

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define ESC 65307

typedef struct s_map
{
	int				x_max; //The maximum number of columns in the matrix.
	int				y_max; //The maximum number of rows in the matrix.
	int				z_max; //The maximum z value in the matrix.
	int				z_min; //The minimum z value in the matrix.
	float			line_width; //The width of each line in the matrix.
	float			line_height; //The height of each line in the matrix.
	//t_vertex		**matrix; //The matrix of vertices.
	char			*map_name; //The name of the map file.
	int				start_x; //The x coordinate of the center of the screen.
	int				start_y; //The y coordinate of the center of the screen.
	float			zoom; //The zoom level of the map.
	float			rotation_x; //The rotation angle around the x axis.
	float			rotation_y; //The rotation angle around the y axis.
	float			z_axis; //The z axis value.

}	t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx -> mlx, mlx -> win);
	mlx_destroy_display(mlx -> mlx);
	free(mlx -> mlx);
	exit (0);
}

int	handle_keypress(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (0);
}

int main(void)
{
    t_mlx	mlx;

    mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
    mlx_hook(mlx.win, 17, 1L << 17, close_window, &mlx);
	mlx_hook(mlx.win, 2, 1L << 0, handle_keypress, &mlx);
	mlx_loop(mlx.mlx);
    free(mlx.mlx);
}