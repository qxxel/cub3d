/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:33:13 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/23 23:41:56 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_img_to_img(t_data *src, t_data *dst, int x_start, int y_start)
{
	int				x;
	int				y;
	int				pos;
	unsigned int	*color;

	y = 0;
	while (y < 160)
	{
		x = 0;
		while (x < 160)
		{
			if (x < 5 || x > 154 || y < 5 || y > 154)
				put_pixel(dst, 0x0000FF, x, y);
			else
			{
				pos = ((y_start + y) * src->size_line + \
					(x_start + x) * (src->bpp / 8));
				color = (unsigned int *)(src->data + pos);
				put_pixel(dst, *color, x, y);
			}
			x++;
		}
		y++;
	}
}

void	fill_minimap(t_game *game)
{
	int			x_start;
	int			y_start;
	t_icoord	coord;

	x_start = (game->player.x - 1) * 8;
	y_start = (game->player.y - 1) * 8;
	put_img_to_img(&game->map_data, &game->minimap_data, x_start, y_start);
	coord.x = 77;
	coord.y = 77;
	display_square(&game->minimap_data, 6, coord, 0xFF0000);
}

void	init_minimap(t_game *game)
{
	game->minimap_img = mlx_new_image(game->mlx, 160, 160);
	game->minimap_data.data = mlx_get_data_addr(game->minimap_img, \
		&game->minimap_data.bpp, &game->minimap_data.size_line, \
		&game->minimap_data.endian);
}

static void	fill_map(t_game *game)
{
	int			x;
	int			y;
	t_icoord	coord;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			coord.x = x * 8 + 72;
			coord.y = y * 8 + 72;
			if (game->map[y][x] == '1' || game->map[y][x] == ' ')
				display_square(&game->map_data, 8, coord, 0x000000);
			else
				display_square(&game->map_data, 8, coord, 0xCECECE);
			x++;
		}
		y++;
	}
}

void	init_map(t_game *game)
{
	game->map_img = mlx_new_image(game->mlx, \
		bigger_line(game->map) * 8 + 144, \
		ft_tablen(game->map) * 8 + 144);
	game->map_data.data = mlx_get_data_addr(game->map_img, \
		&game->map_data.bpp, &game->map_data.size_line, \
		&game->map_data.endian);
	fill_map(game);
}
