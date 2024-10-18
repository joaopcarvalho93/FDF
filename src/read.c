/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhorta-c <jhorta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:24:14 by jhorta-c          #+#    #+#             */
/*   Updated: 2024/10/18 19:17:09 by jhorta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static t_vertex	*fill_vector(char *line, t_map *map)
{
	t_vertex		*vector;
	char			**split;
	int				i;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	vector = malloc(sizeof(t_vertex) * i);
	if (!vector)
		ft_error("Memory allocation failed for vector");
	i = -1;
	while (split[++i])
	{
		vector[i].value = ft_atoi(split[i]);
		if (ft_atoi(split[i]) > map->z_max)
			map->z_max = ft_atoi(split[i]);
		if (ft_atoi(split[i]) < map->z_min)
			map->z_min = ft_atoi(split[i]);
		vector[i].color = calculate_color_based_on_value(vector[i].value, map);
	}
	if (map->x_max >= i || map->x_max == 0)
		map->x_max = i;
	ft_free_array(split);
	return (vector);
}

void	read_map(char *file, t_map *map, t_data *data, t_mlx *mlx)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		close_window_error(mlx, data);
	map->y_max = ft_filelen(file);
	map->matrix = (t_vertex **)malloc(sizeof(t_vertex *) * (map->y_max));
	if (!map->matrix)
		ft_error("Memory allocation failed for map->matrix");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->matrix[i] = fill_vector(line, map);
		if (!map->matrix[i])
			ft_error("Memory allocation failed for map->matrix[i]");
		free(line);
		i++;
	}
	map->y_max = i;
	close(fd);
}
