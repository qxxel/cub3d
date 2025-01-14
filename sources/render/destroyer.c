/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:06:45 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/14 10:20:41 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	destroyer(t_game *game)
{
	if (game->map)
		free_tab(game->map);
	free(game->texture.north.path);
	free(game->texture.south.path);
	free(game->texture.west.path);
	free(game->texture.east.path);
	if (game->mlx)
	{
		mlx_destroy_image(game->mlx, game->img);
		mlx_destroy_image(game->mlx, game->texture.north.img);
		mlx_destroy_image(game->mlx, game->texture.south.img);
		mlx_destroy_image(game->mlx, game->texture.west.img);
		mlx_destroy_image(game->mlx, game->texture.east.img);
		mlx_destroy_window(game->mlx, game->win);
		mlx_loop_end(game->mlx);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(0);
	}
	return (0);
}
