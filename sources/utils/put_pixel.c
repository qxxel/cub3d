/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:37:47 by agerbaud          #+#    #+#             */
/*   Updated: 2024/12/15 22:05:56 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	put_pixel(t_data *data, int color, int x, int y)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * data->size_line + x * data->bpp / 8;
	data->data[index] = color & 0xFF;
	data->data[index + 1] = (color >> 8) & 0xFF;
	data->data[index + 2] = (color >> 16) & 0xFF;
}
