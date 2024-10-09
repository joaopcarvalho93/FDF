/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpcarvalho <jpcarvalho@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:24:14 by jhorta-c          #+#    #+#             */
/*   Updated: 2024/10/08 17:36:19 by jpcarvalho       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static int	*fill_vector(char *line, t_map *map)
{
	int		*vector;
	char	**split;
	int		i;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	map->x_max = i;
	vector = malloc(sizeof(int) * i);
	i = 0;
	while (split[i])
	{
		vector[i] = ft_atoi(split[i]);
		if (vector[i] > map->z_max)
			map->z_max = vector[i];
		if (vector[i] < map->z_min)
			map->z_min = vector[i];
		i++;
	}
	ft_free_array(split);
	return (vector);
}

void	read_map(char *file, int y_max, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	map->z_max = INT_MIN;
	map->z_min = INT_MAX;
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Error opening file");
	map->matrix = malloc(sizeof(int *) * (y_max));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->matrix[i] = fill_vector(line, &map);
		free(line);
		i++;
	}
	map->y_max = i;
	close(fd);
}

