/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:37:47 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/24 18:53:45 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_data *data, int color, int x, int y)
{
	int	index;
	int *tab;

	tab = (int *)(data->data);
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * (data->size_line >> 2) + x;
	tab[index] = color;
}
