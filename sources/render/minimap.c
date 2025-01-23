/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:33:13 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/23 21:04:04 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1' || game->map[y][x] == ' ')
				display_square(&game->map_data, 8, x * 8, y * 8, 0xFFFFFF);
			else
				display_square(&game->map_data, 8, x * 8, y * 8, 0x000000);
			x++;
		}
		y++;
	}
}

void init_map(t_game *game)
{
	game->map_img = mlx_new_image(game->mlx, bigger_line(game->map) * 8 + 160, ft_tablen(game->map) * 8 + 160);
	game->map_data.data = mlx_get_data_addr(game->map_img,
												&game->map_data.bpp, &game->map_data.size_line,
												&game->map_data.endian);
	fill_map(game);
}
