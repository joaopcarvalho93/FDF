/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhorta-c <jhorta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:42:35 by jhorta-c          #+#    #+#             */
/*   Updated: 2024/10/10 16:42:38 by jhorta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fdf.h"

void	free_matrix(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->y_max)
	{
		free(map->matrix[i]);
		map->matrix[i] = NULL;
		i++;
	}
	free(map->matrix);
	map->matrix = NULL;
}