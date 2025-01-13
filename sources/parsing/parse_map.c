/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:13:43 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/13 21:10:32 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_rest_empty(char **map, int i)
{
	int	j;

	while (map[i])
	{
		j = 0;
		if (map[i][0] == ' ')
		{
			while (map[i][j] == ' ')
				j++;
		}
		if (map[i][j] != '\0')
			return (true);
		i++;
	}
	return (false);
}

static bool	check_empty_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == '\0')
		{
			if (check_rest_empty(map, i))
				return (true);
			else
			{
				map[i] = NULL;
				return (false);
			}
		}
		i++;
	}
	return (false);
}

static bool	check_sides(char **map, int i, int j)
{
	if (i == 0 || j == 0 || \
		(size_t)j == ft_strlen(map[i]) - 1 || (size_t)i == ft_tablen(map) - 1)
		return (true);
	if (j > 0 && map[i][j - 1] == ' ')
		return (true);
	if (i > 0 && map[i - 1][j] == ' ')
		return (true);
	if (map[i][j + 1] && (map[i][j + 1] == ' ' || map[i][j + 1] == '\0'))
		return (true);
	if (map[i + 1] && map[i + 1][j] == ' ')
		return (true);
	return (false);
}

bool	check_char(t_game *game, int *count_spawn, int i, int j)
{
	if (game->map[i][j] == 'N' || game->map[i][j] == 'S' \
		|| game->map[i][j] == 'W' || game->map[i][j] == 'E')
	{
		game->player.x = j + 0.5;
		game->player.y = i + 0.5;
		(*count_spawn)++;
	}
	if (!(game->map[i][j] == 'N') && !(game->map[i][j] == 'S') \
		&& !(game->map[i][j] == 'W') && !(game->map[i][j] == 'E') \
		&& !(game->map[i][j] == '1') && !(game->map[i][j] == '0') \
		&& !(game->map[i][j] == ' '))
		return (err("cub3d: the map has unknown charachter\n"));
	if (is_open(game->map[i][j]) && check_sides(game->map, i, j))
		return (err("cub3d: the map is not closed\n"));
	return (false);
}

bool	parse_map(char **map, t_game *game)
{
	int	i;
	int	j;
	int	count_spawn;

	i = 0;
	count_spawn = 0;
	if (!map || !map[0])
		return (err("cub3d: there is no map\n"));
	if (check_empty_lines(map))
		return (err("cub3d: the map isn't in one part\n"));
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (check_char(game, &count_spawn, i, j))
				return (true);
			j++;
		}
		i++;
	}
	if (count_spawn != 1)
		return (err("cub3d: the map hasn't the right number of spawnpoint\n"));
	return (false);
}
