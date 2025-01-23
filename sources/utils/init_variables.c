/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:02:25 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/23 21:04:04 by agerbaud         ###   ########.fr       */
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
	game->mouse.past_x = HALF_WIDTH;
	game->mouse.past_y = HALF_HEIGHT;
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
	game->map_img = NULL;
	game->map_data.data = NULL;
	game->map_data.bpp = 0;
	game->map_data.size_line = 0;
	game->map_data.endian = 0;
}

void	init_variables(t_game *game)
{
	init_textures_variables(&game->texture);
	init_game_variables(game);
	init_mlx_variables(game);
}
