/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:06:45 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/08 13:57:23 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_tab(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map[i]);
	free(map);
}

int	destroyer(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_loop_end(game->mlx);
	mlx_destroy_display(game->mlx);
	free_tab(game->map);
	free(game->mlx);
	exit(0);
	return (0);
}