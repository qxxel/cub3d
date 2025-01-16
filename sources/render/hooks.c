/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:29:51 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/16 10:48:06 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pause_menu(t_game *game)
{
	if (!game->mouse.showed)
	{
		mlx_mouse_show(game->mlx, game->win);
		game->mouse.showed = true;
	}
	else
	{
		mlx_mouse_hide(game->mlx, game->win);
		game->mouse.showed = false;
	}
}

int	keypress(int keycode, t_game *param)
{
	if (keycode == KEY_W)
		param->key.w = true;
	if (keycode == KEY_S)
		param->key.s = true;
	if (keycode == KEY_A)
		param->key.a = true;
	if (keycode == KEY_D)
		param->key.d = true;
	if (keycode == KEY_LEFT)
		param->key.left = true;
	if (keycode == KEY_RIGHT)
		param->key.right = true;
	if (keycode == KEY_P)
		pause_menu(param);
	if (keycode == KEY_Q || keycode == KEY_ESC)
	{
		ft_putstr_fd("Why did you ragequit ??\n", 1);
		destroyer(param);
	}
	return (0);
}

int	keyrelease(int keycode, t_game *param)
{
	if (keycode == KEY_W)
		param->key.w = false;
	if (keycode == KEY_S)
		param->key.s = false;
	if (keycode == KEY_A)
		param->key.a = false;
	if (keycode == KEY_D)
		param->key.d = false;
	if (keycode == KEY_LEFT)
		param->key.left = false;
	if (keycode == KEY_RIGHT)
		param->key.right = false;
	return (0);
}

int motionnotify(int x, int y, t_game *param)
{
	if (param->mouse.moved)	
		param->player.angle -= (x - param->mouse.past_x) * 0.0008;
	param->mouse.past_x = x;
	param->mouse.past_y = y;
	param->mouse.moved = true;
	return (0);
}

int	close_window(t_game *param)
{
	ft_putstr_fd("Why did you ragequit ??\n", 1);
	destroyer(param);
	return (0);
}
