/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:13:43 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/24 16:09:19 by agerbaud         ###   ########.fr       */
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
			while (map[i][j] == ' ' || map[i][j] == '\t')
				j++;
		}
		if (map[i][j] != '\0')
			return (false);
		i++;
	}
	return (true);
}

static bool	check_empty_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == '\0')
		{
			if (!check_rest_empty(map, i))
				return (true);
			else
				return (false);
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
	if (map[i + 1] && (map[i + 1][j] == ' ' || map[i + 1][j] == '\0'))
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
		game->player.spawn = game->map[i][j];
		(*count_spawn)++;
	}
	if (!(game->map[i][j] == 'N') && !(game->map[i][j] == 'S') \
		&& !(game->map[i][j] == 'W') && !(game->map[i][j] == 'E') \
		&& !(game->map[i][j] == '1') && !(game->map[i][j] == '0') \
		&& !(game->map[i][j] == ' '))
		return (err(MSG_ERR_UNKNOWN_CHAR));
	if (is_open(game->map[i][j]) && check_sides(game->map, i, j))
		return (err(MSG_ERR_OPEN_MAP));
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
		return (err(MSG_ERR_NO_MAP));
	if (check_empty_lines(map))
		return (err(MSG_ERR_PART_MAP));
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
		return (err(MSG_ERR_NB_SPAWN));
	return (false);
}
