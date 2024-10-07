/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpcarvalho <jpcarvalho@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:42:02 by jhorta-c          #+#    #+#             */
/*   Updated: 2024/10/03 17:58:24 by jpcarvalho       ###   ########.fr       */
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
		return (0);
	i = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		free(str);
		i++;
		str = get_next_line(fd);
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
