/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:03:29 by mreynaud          #+#    #+#             */
/*   Updated: 2025/01/13 23:03:37 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_texture(t_image *img)
{
	printf("path = %s\n", img->path);
	printf("[width][height] = [%d][%d]\n", img->width, img->height);
	printf("bpp = [%d]\n", img->img_data.bpp);
	printf("size_line = [%d]\n", img->img_data.size_line);
	printf("endian = [%d]\n", img->img_data.endian);

}

static bool init_img_texture(void *mlx_ptr, t_image *img)
{
	img->img = mlx_xpm_file_to_image(mlx_ptr, img->path, &img->width, &img->height);
	if (!img->img)
		return (false);
	img->img_data.data = mlx_get_data_addr(img->img, &img->img_data.bpp, &img->img_data.size_line, &img->img_data.endian);
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
