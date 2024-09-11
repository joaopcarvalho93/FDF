/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhorta-c <jhorta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:37:42 by jhorta-c          #+#    #+#             */
/*   Updated: 2024/09/11 18:54:44 by jhorta-c         ###   ########.fr       */
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
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"



typedef struct s_map
{
	int	x_max;
	int	y_max;
	int	z_max;
	int	z_min;
	int	line_width;
	int	line_height;
	int	**matrix;
	
}		t_map;


#endif