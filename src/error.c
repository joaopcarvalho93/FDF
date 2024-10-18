/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhorta-c <jhorta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:43:19 by jhorta-c          #+#    #+#             */
/*   Updated: 2024/10/18 19:13:56 by jhorta-c         ###   ########.fr       */
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
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			count++;
		i++;
	}
	if (count != 2)
		return (-1);
	i -= 4;
	return (ft_strcmp(&(str[i]), ".fdf"));
}

void	close_window_error(t_mlx *mlx, t_data *data)
{
	printf("Error opening file");
	mlx_destroy_image(mlx -> mlx, data -> img);
	mlx_destroy_window(mlx -> mlx, mlx -> win);
	mlx_destroy_display(mlx -> mlx);
	free(mlx -> mlx);
	exit (1);
}
