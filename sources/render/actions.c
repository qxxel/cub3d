/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:27:44 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/07 15:00:29 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static bool	check_wall(t_game *game, float x_dest, float y_dest)
{
	if (game->map[(int)y_dest / 64][(int)x_dest / 64] == '1')
		return (true);
	if (game->map[(int)(y_dest + 20) / 64][(int)x_dest / 64] == '1')
		return (true);
	if (game->map[(int)y_dest / 64][(int)(x_dest + 20) / 64] == '1')
		return (true);
	if (game->map[(int)(y_dest + 20) / 64][(int)(x_dest + 20) / 64] == '1')
		return (true);
	return (false);
}

static void	move_x(t_game *game, float angle_cos_sin)
{
	int		i;
	float	x_dest;

	i = 0;
	x_dest = game->player.x + angle_cos_sin * SPEED;
	while (i < SPEED)
	{
		if (!check_wall(game, x_dest - i * angle_cos_sin, game->player.y))
		{
			game->player.x = x_dest - i * angle_cos_sin;
			return ;
		}
		i++;
	}
}

static void	move_y(t_game *game, float angle_cos_sin)
{
	int		i;
	float	y_dest;

	i = 0;
	y_dest = game->player.y + angle_cos_sin * SPEED;
	while (i < SPEED)
	{
		if (!check_wall(game, game->player.x, y_dest - i * angle_cos_sin))
		{
			game->player.y = y_dest - i * angle_cos_sin;
			return ;
		}
		i++;
	}
}

int	actions(t_game *param)
{
	float 	angle_cos;
	float 	angle_sin;

	if (param->key.left)
		param->player.angle -= ANGLE_SPEED;
	if (param->key.right)
		param->player.angle += ANGLE_SPEED;
	if (param->player.angle > 2 * PI)
		param->player.angle -= 2 * PI;
	if (param->player.angle < 0)
		param->player.angle += 2 * PI;
	angle_cos = cosf(param->player.angle);
	angle_sin = sinf(param->player.angle);
	if (param->key.w == 1)
	{
		move_x(param, angle_cos);
		move_y(param, angle_sin);
	}
	if (param->key.s == 1)
	{
		move_x(param, -angle_cos);
		move_y(param, -angle_sin);
	}
	if (param->key.a == 1)
	{
		move_x(param, angle_sin);
		move_y(param, -angle_cos);
	}
	if (param->key.d == 1)
	{
		move_x(param, -angle_sin);
		move_y(param, angle_cos);
	}
	return (0);
}