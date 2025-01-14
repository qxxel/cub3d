/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:27:44 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/14 11:06:48 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_wall(t_game *game, float x_dest, float y_dest)
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

static float	move_x(t_game *game, float angle_cos_sin)
{
	int		i;
	float	x_dest;

	i = 0;
	x_dest = game->player.new_x + angle_cos_sin * SPEED;
	while (i < SPEED)
	{
		if (!check_wall(game, x_dest - i * angle_cos_sin, game->player.new_y))
			return (x_dest - i * angle_cos_sin);
		i++;
	}
	return (game->player.new_x);
}

static float	move_y(t_game *game, float angle_cos_sin)
{
	int		i;
	float	y_dest;

	i = 0;
	y_dest = game->player.new_y + angle_cos_sin * SPEED;
	while (i < SPEED)
	{
		if (!check_wall(game, game->player.new_x, y_dest - i * angle_cos_sin))
			return (y_dest - i * angle_cos_sin);
		i++;
	}
	return (game->player.new_y);
}

void	move_player(t_game *game, float angle_cos, float angle_sin, int side)
{
	game->player.new_x = game->player.x;
	game->player.new_y = game->player.y;
	if (!side)
	{
		game->player.new_x = move_x(game, angle_cos);
		game->player.new_y = move_y(game, -angle_sin);
		game->player.moved = true;
	}
	else
	{
		game->player.new_x = move_x(game, -angle_sin);
		game->player.new_y = move_y(game, angle_cos);
		game->player.moved = true;
	}
}

int	actions(t_game *param)
{
	float 	angle_cos;
	float 	angle_sin;

	if (param->key.left)
		param->player.angle += ANGLE_SPEED;
	if (param->key.right)
		param->player.angle -= ANGLE_SPEED;
	if (param->player.angle > 2 * PI)
		param->player.angle -= 2 * PI;
	if (param->player.angle < 0)
		param->player.angle += 2 * PI;
	angle_cos = cosf(param->player.angle);
	angle_sin = sinf(param->player.angle);
	if (param->key.w)
		move_player(param, angle_cos, angle_sin, 0);
	if (param->key.s)
		move_player(param, -angle_cos, -angle_sin, 0);
	if (param->key.a)
		move_player(param, -angle_cos, angle_sin, 1);
	if (param->key.d)
		move_player(param, angle_cos, -angle_sin, 1);
	if (param->player.moved)
	{
		param->player.x = param->player.new_x;
		param->player.y = param->player.new_y;
		param->player.moved = false;
	}
	return (0);
}
