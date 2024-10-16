/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpcarvalho <jpcarvalho@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:43:19 by jhorta-c          #+#    #+#             */
/*   Updated: 2024/10/16 15:16:15 by jpcarvalho       ###   ########.fr       */
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


