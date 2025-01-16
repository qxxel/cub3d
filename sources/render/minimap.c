/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:33:13 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/16 11:46:46 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// bool	minimap(t_game *game)
// {

// }

bool	init_minimap(t_game *game)
{
	int	i;
	int	x;
	int	y;
	int	higher_len;

	i = 0;
	higher_len = 0;
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) > higher_len)
			higher_len = ft_strlen(game->map[i]);
		i++;
	}
	game->minimap_img = mlx_new_image(game->mlx, higher_len, \
		ft_tablen(game->map));
	game->minimap_data.data = mlx_get_data_addr(game->minimap_img, \
		&game->minimap_data.bpp, &game->minimap_data.size_line, \
		&game->minimap_data.endian);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				display_square(&game->minimap_data, 20, x * 20, \
					y * 20, 0x0000FF);
			x++;
		}
		y++;
	}
	return (false);
}
