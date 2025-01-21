/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:02:44 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/16 11:36:51 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update_img(t_game *param)
{
	actions(param);
	update_mouse(param);
	if (param->player.past_x != param->player.x \
		|| param->player.past_y != param->player.y \
		|| param->player.past_angle != param->player.angle)
	{
		clear_image(&param->img_data);
		display_rays(param);
		mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
		param->player.past_x = param->player.x;
		param->player.past_y = param->player.y;
		param->player.past_angle = param->player.angle;
	}
	display_map(param);
	display_square(&param->img_data, 8, param->player.x * 8 - 4, \
		param->player.y * 8 - 4, 0x0000FF);
	return (0);
}

void	init_game(t_game *game) // proteger toutes les fonctions mlx ??
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "game");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img_data.data = mlx_get_data_addr(game->img, &game->img_data.bpp, \
		&game->img_data.size_line, &game->img_data.endian);
	init_spawn(game);
	init_texture(game, &game->texture);
	/*init_minimap(game);*/
}

void	ft_raycast(t_game *game)
{
	init_game(game);
	mlx_mouse_move(game->mlx, game->win, HALF_WIDTH, HALF_HEIGHT);
	mlx_mouse_hide(game->mlx, game->win);
	mlx_hook(game->win, KEYPRESS, 1L << KEYPRESSMASK, keypress, game);
	mlx_hook(game->win, KEYRELEASE, 1L << KEYRELEASEMASK, keyrelease, game);
	mlx_hook(game->win, MOTIONNOTIFY, 1L << MOTIONNOTIFYMASK, \
		motionnotify, game);
	mlx_hook(game->win, DESTROYNOTIFY, 1L << DESTROYNOTIFYMASK, close_window,
		game);
	mlx_loop_hook(game->mlx, update_img, game);
	mlx_loop(game->mlx);
}
