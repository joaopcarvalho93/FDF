/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhorta-c <jhorta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:24:14 by jhorta-c          #+#    #+#             */
/*   Updated: 2024/09/11 18:57:43 by jhorta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	read_map(char *file, int y_max)
{
	t_map	map;
	int		fd;
	int		i;
	char	*str;

	i = 0;
	map.z_max = 0;
	map.z_min = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ((t_map){NULL, -1, -1}); // verificar
	map.matrix = malloc(sizeof(int *) * y_max);
	while ((str = get_next_line(fd)) == NULL)
	{
		map.matrix[i] = 
	}
	
}