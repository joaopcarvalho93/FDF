/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpcarvalho <jpcarvalho@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:24:14 by jhorta-c          #+#    #+#             */
/*   Updated: 2024/10/14 15:56:16 by jpcarvalho       ###   ########.fr       */
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
	i = 0;
	while (split[i])
	{
		vector[i].value = ft_atoi(split[i]);
		if (vector[i].value > map->z_max)
			map->z_max = vector[i].value;
		if (vector[i].value < map->z_min)
			map->z_min = vector[i].value;
		vector[i].color = 0x00FFFFFF;
		i++;
	}
	map->x_max = i;
	ft_free_array(split);
	return (vector);
}

t_map	read_map(char *file, int y_max)
{
	int		fd;
	char	*line;
	int		i;
	t_map	map;

	map.z_max = INT_MIN;
	map.z_min = INT_MAX;
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Error opening file");
	map.matrix = malloc(sizeof(t_vertex *) * (y_max));
	if (!map.matrix)
		ft_error("Memory allocation failed for map->matrix");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map.matrix[i] = fill_vector(line, &map);
		if (!map.matrix[i])
            ft_error("Memory allocation failed for map->matrix[i]");
		free(line);
		i++;
	}
	map.y_max = i;
	close(fd);
	return (map);
}

