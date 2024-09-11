/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhorta-c <jhorta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:42:02 by jhorta-c          #+#    #+#             */
/*   Updated: 2024/09/11 19:15:02 by jhorta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_filelen(char *file)
{
	int		i;
	int		fd;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	i = 0;
	while ((str = get_next_line(fd)) != NULL)
	{
		free(str);
		i++;
	}
	close(fd);
	return (i);
}

int long	ft_arraylen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
