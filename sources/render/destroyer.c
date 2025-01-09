/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:06:45 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/09 14:47:55 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	destroyer(t_game *game)
{
	if (game->map)
		free_tab(game->map);
	if (game->mlx)
	{
		mlx_loop_end(game->mlx);
		mlx_destroy_display(game->mlx);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		free(game->mlx);
		exit(0);
	}
	return (0);
}
