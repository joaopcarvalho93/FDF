/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhorta-c <jhorta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:47:07 by jhorta-c          #+#    #+#             */
/*   Updated: 2024/10/18 18:42:02 by jhorta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char *argv[])
{
	if (argc != 2 || file_checker(argv[1]) != 0)
	{
		ft_error("wrong arguments");
	}
	else
		fdf(argv[1]);
	return (0);
}
