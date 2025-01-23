/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:03:01 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/23 15:03:12 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_wall(t_game *game, float x_dest, float y_dest)
{
	if (game->map[(int)(y_dest - 0.1)][(int)(x_dest - 0.1)] == '1')
		return (true);
	if (game->map[(int)(y_dest + 0.1)][(int)(x_dest - 0.1)] == '1')
		return (true);
	if (game->map[(int)(y_dest - 0.1)][(int)(x_dest + 0.1)] == '1')
		return (true);
	if (game->map[(int)(y_dest + 0.1)][(int)(x_dest + 0.1)] == '1')
		return (true);
	return (false);
}
