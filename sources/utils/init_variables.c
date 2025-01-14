/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:02:25 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/14 10:52:17 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_textures_variables(t_texture *texture)
{
	texture->ceiling.r = 0;
	texture->ceiling.g = 0;
	texture->ceiling.b = 0;
	texture->floor.r = 0;
	texture->floor.g = 0;
	texture->floor.b = 0;
	texture->north.path = NULL;
	texture->south.path = NULL;
	texture->west.path = NULL;
	texture->east.path = NULL;
}

static void	init_game_variables(t_game *game)
{
	game->key.w = false;
	game->key.s = false;
	game->key.a = false;
	game->key.d = false;
	game->key.left = false;
	game->key.right = false;
	game->player.x = 0;
	game->player.y = 0;
	game->player.new_x = 0;
	game->player.new_y = 0;
	game->player.angle = 0;
	game->player.past_x = 0;
	game->player.past_y = 0;
	game->player.past_angle = 0;
	game->player.moved = false;
	game->player.spawn = 0;
	game->mouse.past_x = WIDTH / 2;
	game->mouse.past_y = HEIGHT / 2;
	game->mouse.moved = false;
	game->mouse.showed = false;
	game->map = NULL;
}

static void	init_mlx_variables(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	game->img_data.data = NULL;
	game->img_data.bpp = 0;
	game->img_data.size_line = 0;
	game->img_data.endian = 0;
	game->minimap_img = NULL;
	game->minimap_data.data = NULL;
	game->minimap_data.bpp = 0;
	game->minimap_data.size_line = 0;
	game->minimap_data.endian = 0;
}

void	init_variables(t_game *game)
{
	init_textures_variables(&game->texture);
	init_game_variables(game);
	init_mlx_variables(game);
}