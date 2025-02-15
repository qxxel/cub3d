/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:03:29 by mreynaud          #+#    #+#             */
/*   Updated: 2025/01/23 22:54:00 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	init_img_texture(void *mlx_ptr, t_image *img)
{
	img->img = mlx_xpm_file_to_image(mlx_ptr, img->path, &img->width, \
		&img->height);
	if (!img->img)
		return (false);
	img->img_data.data = mlx_get_data_addr(img->img, &img->img_data.bpp, \
		&img->img_data.size_line, &img->img_data.endian);
	return (true);
}

bool	init_texture(t_game *game, t_texture *txr)
{
	if (init_img_texture(game->mlx, &txr->north) \
			&& init_img_texture(game->mlx, &txr->south) \
			&& init_img_texture(game->mlx, &txr->west) \
			&& init_img_texture(game->mlx, &txr->east))
		return (true);
	return (false);
}
