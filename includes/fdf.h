/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpcarvalho <jpcarvalho@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:37:42 by jhorta-c          #+#    #+#             */
/*   Updated: 2024/10/04 16:36:37 by jpcarvalho       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <limits.h>
# include "./lib/libft/libft.h"
# include "./lib/get_next_line/get_next_line.h"
# include "./lib/minilibx-linux/mlx.h"

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

typedef struct s_map
{
	int		x_max;
	int		y_max;
	int		z_max;
	int		z_min;
	int		line_width;
	int		line_height;
	int		**matrix;
	char	*map_name;
	int		start_x;
	int		start_y;
	float	zoom;
	float	rotation_x;
	float	rotation_y;

}	t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;


#endif