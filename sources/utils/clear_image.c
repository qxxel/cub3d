/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:25:37 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/08 14:57:50 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_image(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			put_pixel(data, 0x000000, x, y);
			x++;
		}
		y++;
	}
}
