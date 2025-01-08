/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:14:59 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/08 15:00:14 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_lines(char *file)
{
	int		fd;
	int		nbchar;
	int		count;
	char	b[1];
	char	c;

	count = 1;
	nbchar = 0;
	c = '\0';
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (perror(file), -1);
	while (read(fd, b, 1))
	{
		if (b[0] == '\n')
			count++;
		c = b[0];
		nbchar++;
	}
	if (c != '\n')
		count++;
	if (!nbchar)
		return (write(2, "cub3d: the file in argument is empty\n", 37), -1);
	close(fd);
	return (count);
}
