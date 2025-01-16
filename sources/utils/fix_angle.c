/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_angle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:42:43 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/16 11:43:28 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fix_angle(t_game *game)
{
	if (game->player.angle > 2 * PI)
		game->player.angle -= 2 * PI;
	if (game->player.angle < 0)
		game->player.angle += 2 * PI;
}
