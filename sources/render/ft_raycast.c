/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:02:44 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/15 02:29:07 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update_img(t_game *param)
{
	actions(param);
	if (!param->mouse.showed\
		&& (param->mouse.past_x > WIDTH * 0.8 || param->mouse.past_x < WIDTH * 0.2 ||\
		param->mouse.past_y > HEIGHT * 0.8 || param->mouse.past_y < HEIGHT * 0.2))
	{
		param->mouse.moved = false;
		param->mouse.past_x = WIDTH / 2;
		param->mouse.past_y = HEIGHT / 2;
		mlx_mouse_move(param->mlx, param->win, WIDTH / 2, HEIGHT / 2);
	}
	if (param->player.past_x != param->player.x \
		|| param->player.past_y != param->player.y \
		|| param->player.past_angle != param->player.angle)
	{
		// dprintf(2, "\n%f - %f\n", param->player.x, param->player.y);
		clear_image(&param->img_data);
		display_rays(param);
		mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
		param->player.past_x = param->player.x;
		param->player.past_y = param->player.y;
		param->player.past_angle = param->player.angle;
	}
	display_map(param);
	display_square(&param->img_data, 8, param->player.x * 8 - 4, param->player.y * 8 - 4, 0x0000FF);
	return (0);
}

void	init_game(t_game *game) // proteger toutes les fonctions mlx ??
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "game");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img_data.data = mlx_get_data_addr(game->img, &game->img_data.bpp,\
		&game->img_data.size_line, &game->img_data.endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	if (game->player.spawn == 'E')
		game->player.angle = 0;
	if (game->player.spawn == 'N')
		game->player.angle = PI / 2;
	if (game->player.spawn == 'W')
		game->player.angle = PI;
	if (game->player.spawn == 'S')
		game->player.angle = (3 * PI) / 2;
	game->key.w = false;
	game->key.s = false;
	game->key.a = false;
	game->key.d = false;
	game->key.left = false;
	game->key.right = false;
	game->mouse.moved = false;
	game->mouse.showed = false;
	game->mouse.past_y = HEIGHT / 2;
	// init_minimap(game);
	init_texture(game, &game->texture);
}

void	ft_raycast(t_game *game)
{
	init_game(game);
	mlx_mouse_move(game->mlx, game->win, WIDTH / 2, HEIGHT / 2);
	mlx_mouse_hide(game->mlx, game->win);
	mlx_hook(game->win, KEYPRESS, 1L << KEYPRESSMASK, keypress, game);
	mlx_hook(game->win, KEYRELEASE, 1L << KEYRELEASEMASK, keyrelease, game);
	mlx_hook(game->win, MOTIONNOTIFY, 1L << MOTIONNOTIFYMASK, motionnotify, game);
	mlx_hook(game->win, DESTROYNOTIFY, 1L << DESTROYNOTIFYMASK, close_window,
		game);
	mlx_loop_hook(game->mlx, update_img, game);
	mlx_loop(game->mlx);
}
