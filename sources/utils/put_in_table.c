/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:35:41 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/08 15:00:44 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_gnl_error(char **map, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		free(map[i]);
	free(map);
}

char	**read_file(char **cub, int fd, int lines, int i)
{
	while (++i < lines - 1)
	{
		cub[i] = get_next_line(fd);
		if (!cub[i])
		{
			free_gnl_error(cub, i);
			err("cub3d: error while reading file\n");
			return (NULL);
		}
		if (cub[i][ft_strlen(cub[i]) - 1] == '\n')
			cub[i][ft_strlen(cub[i]) - 1] = 0;
	}
	cub[i] = NULL;
	close(fd);
	return (cub);
}

char	**put_in_table(char	*file)
{
	int		fd;
	int		lines;
	int		i;
	char	**cub;

	i = -1;
	lines = count_lines(file);
	if (lines <= 0)
		return (NULL);
	cub = (char **)malloc(sizeof(char *) * lines);
	if (!cub)
		return (perror("cub3d"), NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("cub3d"), NULL);
	return (read_file(cub, fd, lines, i));
}
