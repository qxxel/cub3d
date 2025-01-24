/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:02:25 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/24 16:15:10 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_spawn(t_game *game)
{
	if (game->player.spawn == 'E')
		game->player.angle = 0;
	if (game->player.spawn == 'N')
		game->player.angle = PI / 2;
	if (game->player.spawn == 'W')
		game->player.angle = PI;
	if (game->player.spawn == 'S')
		game->player.angle = (3 * PI) / 2;
}

void	init_variables(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->mouse.past_x = HALF_WIDTH;
	game->mouse.past_y = HALF_HEIGHT;
}
