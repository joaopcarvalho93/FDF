
#include "../includes/fdf.h"

void	check_connection(void *mlx)
{
	if (!mlx)
	{
		ft_putstr_fd("Error\nConnection to the graphical server failed\n", 2);
		exit(1);
	}
}

void	check_window(t_mlx *mlx)
{
	if (!mlx->win)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		ft_putstr_fd("Error\nWindow creation failed\n", 2);
		exit(1);
	}
}

void	check_image(t_mlx *mlx, void *img)
{
	if (!img)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		ft_putstr_fd("Error\nImage creation failed\n", 2);
		exit(1);
	}
}
