/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:19:03 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/30 17:05:20 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_rest_empty(char **map, int *i)
{
	int	j;

	while (map[*i])
	{
		j = 0;
		if (map[*i][0] == ' ')
		{
			while (map[*i][j] == ' ')
				j++;
		}
		if (map[*i][j] != '\0')
			return ;
		(*i)++;
	}
}

char	*get_actual_line(char **cub, int start, int i)
{
	int		j;
	int		nb_spaces;
	char	*spaces;
	char	*line;

	nb_spaces = bigger_line(cub, start) - ft_strlen(cub[i]);
	spaces = (char *)malloc(sizeof(char) * (nb_spaces + 1));
	if (!spaces)
		return (NULL);
	j = 0;
	while (j < nb_spaces)
		spaces[j++] = ' ';
	spaces[j] = '\0';
	line = ft_strjoin(cub[i++], spaces);
	free(spaces);
	if (!line)
		return (NULL);
	return (line);
}

static char	**copy_map(char **cub, int i)
{
	int		j;
	int		start;
	char	**map;

	j = 0;
	while (cub[j])
		j++;
	map = ft_calloc((j - i + 1), sizeof(char *));
	if (!map)
	{
		perror("cub3d");
		return (NULL);
	}
	j = 0;
	start = i;
	while (cub[i])
	{
		map[j] = get_actual_line(cub, start, i);
		if (!map[j])
			return (free_previous_lines(map, j));
		j++;
		i++;
	}
	return (map);
}

void	check_defines(char **cub, int *all_good, int j, int i)
{
	if (!ft_strncmp(cub[i] + j, "NO ", 3))
		all_good[0] = 1;
	else if (!ft_strncmp(cub[i] + j, "SO ", 3))
		all_good[1] = 1;
	else if (!ft_strncmp(cub[i] + j, "WE ", 3))
		all_good[2] = 1;
	else if (!ft_strncmp(cub[i] + j, "EA ", 3))
		all_good[3] = 1;
	else if (!ft_strncmp(cub[i] + j, "F ", 2))
		all_good[4] = 1;
	else if (!ft_strncmp(cub[i] + j, "C ", 2))
		all_good[5] = 1;
}

static int	find_map(char **cub)
{
	int	i;
	int	j;
	int	all_good[6];

	i = 0;
	ft_bzero_int(all_good, 6);
	while (cub[i] && (!all_good[0] || !all_good[1] || !all_good[2] \
		|| !all_good[3] || !all_good[4] || !all_good[5]))
	{
		j = 0;
		while (cub[i][j] == ' ' || cub[i][j] == '\t')
			j++;
		check_defines(cub, all_good, j, i);
		i++;
	}
	check_rest_empty(cub, &i);
	return (i);
}

char	**get_map(char **cub)
{
	int		i;
	char	**map;

	i = find_map(cub);
	map = copy_map(cub, i);
	return (map);
}
