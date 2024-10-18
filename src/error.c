/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhorta-c <jhorta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:43:19 by jhorta-c          #+#    #+#             */
/*   Updated: 2024/10/17 16:18:11 by jhorta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fdf.h"

void	check_mlx_int(void *mlx)
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

int	file_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	i -= 4;
	return (ft_strcmp(&(str[i]), ".fdf"));
}

void	close_window_error(t_mlx *mlx, t_data *data)
{
	mlx_destroy_image(mlx -> mlx, data -> img);
	mlx_destroy_window(mlx -> mlx, mlx -> win);
	mlx_destroy_display(mlx -> mlx);
	free(mlx -> mlx);
	exit (1);
}

