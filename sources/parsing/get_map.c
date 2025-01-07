/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:19:03 by agerbaud          #+#    #+#             */
/*   Updated: 2024/12/10 12:55:26 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	check_rest_empty(char **map, int *i)
{
    int j;

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

static char	**copy_map(char **cub, int i)
{
	int		j;
	char	**map;

	j = 0;
	while (cub[j])
		j++;
	map = malloc((j - i + 1) * sizeof(char *));
	if (!map)
		return (NULL); // add error message
	j = 0;
	while (cub[i])
	{
		map[j] = ft_strdup(cub[i]);
		if (!map[j])
			return (NULL); // add error message & free
		// ft_printf("%s\n", map[j]);
		i++;
		j++;
	}
	map[j] = NULL;
	return (map);
}

static int	find_map(char **cub)
{
	int	i;
	int	j;
	int	all_good[6];
	
	i = 0;
	ft_bzero_int(all_good, 6);
	while (cub[i] && (!all_good[0] || !all_good[1] || !all_good[2]\
		|| !all_good[3] || !all_good[4] || !all_good[5]))
	{
		j = 0;
		while (cub[i][j] == ' ')
			j++;
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