/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:44:14 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/08 15:08:24 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	get_textures(char **cub, t_texture *texture)
{
	if (get_image(cub, "NO ", &texture->north) \
		|| get_image(cub, "SO ", &texture->south) \
		|| get_image(cub, "WE ", &texture->west) \
		|| get_image(cub, "EA ", &texture->east) \
		|| get_color(cub, "F ", &texture->floor) \
		|| get_color(cub, "C ", &texture->ceiling))
		return (true);
	return (false);
}
