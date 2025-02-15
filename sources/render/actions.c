/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:27:44 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/23 22:56:18 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	move_x(t_game *game, float agl_cos_sin)
{
	int		i;
	float	x_dest;

	i = 0;
	x_dest = game->player.new_x + agl_cos_sin * SPEED;
	while (i < SPEED)
	{
		if (!check_wall(game, x_dest - i * agl_cos_sin, game->player.new_y))
			return (x_dest - i * agl_cos_sin);
		i++;
	}
	return (game->player.new_x);
}

static float	move_y(t_game *game, float agl_cos_sin)
{
	int		i;
	float	y_dest;

	i = 0;
	y_dest = game->player.new_y + agl_cos_sin * SPEED;
	while (i < SPEED)
	{
		if (!check_wall(game, game->player.new_x, y_dest - i * agl_cos_sin))
			return (y_dest - i * agl_cos_sin);
		i++;
	}
	return (game->player.new_y);
}

static void	move_coords(t_game *game, float agl_cos, float agl_sin, int side)
{
	if (!side)
	{
		game->player.new_x = move_x(game, agl_cos);
		game->player.new_y = move_y(game, -agl_sin);
		game->player.moved = true;
	}
	else
	{
		game->player.new_x = move_x(game, -agl_sin);
		game->player.new_y = move_y(game, agl_cos);
		game->player.moved = true;
	}
}

static void	move_player(t_game *game, float agl_cos, float agl_sin)
{
	game->player.new_x = game->player.x;
	game->player.new_y = game->player.y;
	if (game->key.w)
		move_coords(game, agl_cos, agl_sin, 0);
	if (game->key.s)
		move_coords(game, -agl_cos, -agl_sin, 0);
	if (game->key.a)
		move_coords(game, -agl_cos, agl_sin, 1);
	if (game->key.d)
		move_coords(game, agl_cos, -agl_sin, 1);
}

int	actions(t_game *param)
{
	float	agl_cos;
	float	agl_sin;

	if (param->key.left)
		param->player.angle += ANGLE_SPEED;
	if (param->key.right)
		param->player.angle -= ANGLE_SPEED;
	fix_angle(param);
	agl_cos = cosf(param->player.angle);
	agl_sin = sinf(param->player.angle);
	move_player(param, agl_cos, agl_sin);
	if (param->player.moved)
	{
		param->player.x = param->player.new_x;
		param->player.y = param->player.new_y;
		param->player.moved = false;
	}
	return (0);
}
