/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhorta-c <jhorta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:44:59 by jhorta-c          #+#    #+#             */
/*   Updated: 2024/10/18 18:40:50 by jhorta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	handle_keypress(int keycode, t_all *all)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(all -> mlx -> mlx, all -> data ->img);
		mlx_destroy_window(all -> mlx -> mlx, all -> mlx -> win);
		mlx_destroy_display(all -> mlx -> mlx);
		free(all -> mlx -> mlx);
		exit (0);
	}
	return (0);
}

int	close_window(t_all *all)
{
	mlx_destroy_image(all -> mlx -> mlx, all -> data ->img);
	mlx_destroy_window(all -> mlx -> mlx, all -> mlx -> win);
	mlx_destroy_display(all -> mlx -> mlx);
	free(all -> mlx -> mlx);
	exit (0);
}
