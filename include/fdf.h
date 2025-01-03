/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhorta-c <jhorta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:37:42 by jhorta-c          #+#    #+#             */
/*   Updated: 2024/10/18 19:15:59 by jhorta-c         ###   ########.fr       */
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
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>
# include "../lib/libft/libft.h"
# include "../lib/mlx_linux/mlx.h"

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ZOOM_IN 61
# define ZOOM_OUT 45
# define ROTATE_X_UP 119
# define ROTATE_X_DOWN 115
# define ROTATE_Y_UP 100
# define ROTATE_Y_DOWN 97
# define Z_AXIS_UP 113
# define Z_AXIS_DOWN 101
# define RESET 114
# define TILE_WIDTH 15
# define TILE_HEIGHT 15
# define DEGREE_30 0.523599
# define DEGREE_60 1.0472
# define M_PI 3.14159265358979323846

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_data
{
	void	*img; //The image data.
	char	*addr; //The address of the image data.
	int		bits_per_pixel; //The number of bits per pixel.
	int		line_length; //The size of each line in bytes.
	int		endian; //The endianess of the image.
}	t_data;

typedef struct s_rgb
{
	int	red; //The red value of the color.
	int	green; //The green value of the color.
	int	blue; //The blue value of the color.
}	t_rgb;

typedef struct s_vertex
{
	float			x; //The x coordinate of the vertex.
	float			y; //The y coordinate of the vertex.
	int				value; //The z coordinate of the vertex.
	unsigned int	color; //The color of the vertex.
	t_rgb			rgb; //The red, green, and blue values of the vertex.
}	t_vertex;

typedef struct s_map
{
	int				x_max; //The maximum number of columns in the matrix.
	int				y_max; //The maximum number of rows in the matrix.
	int				z_max; //The maximum z value in the matrix.
	int				z_min; //The minimum z value in the matrix.
	int				tile_width; //The width of each line in the matrix.
	int				tile_height; //The height of each line in the matrix.
	t_vertex		**matrix; //The matrix of vertices.
	char			*map_name; //The name of the map file.
	int				start_x; //The x coordinate of the center of the screen.
	int				start_y; //The y coordinate of the center of the screen.
	float			zoom; //The zoom level of the map.
	float			rotation_x; //The rotation angle around the x axis.
	float			rotation_y; //The rotation angle around the y axis.
	float			z_axis; //The z axis value.
	int				edge;
	int				width;
}	t_map;

typedef struct s_all
{
	t_map	*map;
	t_mlx	*mlx;
	t_data	*data;
}	t_all;

//draw

int				is_inside_frame(t_vertex vertex);
void			my_mlx_pixel_put(t_data *data, t_vertex vertex);
void			draw_line(t_data *data, t_vertex vertex1, t_vertex vertex2);
void			draw_map(t_data *data, t_map *map);
void			join_vertex(t_data *data, t_map *map);
unsigned int	calculate_color_based_on_value(int value, t_map *map);
void			adjust_map_to_screen(t_map *map);

//free

void			free_matrix(t_map *map);

//map

void			read_map(char *file, t_map *map, t_data *data, t_mlx *mlx);

//init

void			fdf(char *file);
void			int_window(t_map *map, t_mlx *mlx, t_data *data,
					char *filename);
void			init_vars(t_map *map, t_mlx *mlx, t_data *data, t_all *all);

//error

void			check_mlx_int(void *mlx);
void			check_window(t_mlx *mlx);
void			check_image(t_mlx *mlx, void *img);
int				file_checker(char *arg);
void			close_window_error(t_mlx *mlx, t_data *data);

//keys

int				close_window(t_all *all);
int				handle_keypress(int keycode, t_all *all);

#endif