/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:13:43 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/08 13:57:11 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int  check_open(char c)
{
    if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
        return (0);
    return (1);
}

static int check_rest_empty(char **map, int i)
{
    int j;

    while (map[i])
    {
        j = 0;
        if (map[i][0] == ' ')
        {
            while (map[i][j] == ' ')
                j++;
        }
        if (map[i][j] != '\0')
            return (1);
        i++;
    }
    return (0);
}

static int check_empty_lines(char **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        if (map[i][0] == '\0')
        {
            if (check_rest_empty(map, i))
                return (1);
            else
            {
                map[i] = NULL;
                return (0);
            }
        }
        i++;
    }
    return (0);
}

static int  check_sides(char **map, int i, int j)
{
    if (i == 0 || j == 0 ||\
        (size_t)j == ft_strlen(map[i]) - 1 || (size_t)i == ft_tablen(map) - 1)
        return (1);
    if (j > 0 && map[i][j - 1] == ' ')
        return (1);
    if (i > 0 && map[i - 1][j] == ' ')
        return (1);
    if (map[i][j + 1] && (map[i][j + 1] == ' ' || map[i][j + 1] == '\0'))
        return (1);
    if (map[i + 1] && map[i + 1][j] == ' ')
        return (1);
    return (0);
}

int parse_map(char **map, t_game *game)
{
    int i;
    int j;
    int count_spawn;

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
            if (map[i][j] == 'N' || map[i][j] == 'S'\
                || map[i][j] == 'W' || map[i][j] == 'E')
            {
                game->player.x = j * 64;
                game->player.y = i * 64;
                count_spawn++;
            }
            if (!(map[i][j] == 'N') && !(map[i][j] == 'S') && !(map[i][j] == 'W')\
                && !(map[i][j] == 'E') && !(map[i][j] == '1') && !(map[i][j] == '0')\
                && !(map[i][j] == ' '))
                return (err("cub3d: the map has unknown charachter\n"));
            if (!check_open(map[i][j]) && check_sides(map, i, j))
                return (err("cub3d: the map is not closed\n"));
            j++;
        }
        i++;
    }
    if (count_spawn != 1)
        return (err("cub3d: the map hasn't the right number of spawnpoint\n"));
    return (0);
}
