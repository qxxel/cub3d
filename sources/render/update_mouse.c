/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:18:19 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/16 11:35:49 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_mouse(t_game *game)
{
	if (!game->mouse.showed && game->mouse.moved \
		&& (game->mouse.past_x > WIDTH * 0.8 \
		|| game->mouse.past_x < WIDTH * 0.2 \
		|| game->mouse.past_y > HEIGHT * 0.8 \
		|| game->mouse.past_y < HEIGHT * 0.2))
	{
		mlx_mouse_move(game->mlx, game->win, HALF_WIDTH, HALF_HEIGHT);
		game->mouse.moved = false;
		game->mouse.past_x = HALF_WIDTH;
		game->mouse.past_y = HALF_HEIGHT;
	}
}
