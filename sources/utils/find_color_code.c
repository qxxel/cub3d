/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_color_code.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:06:06 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/13 17:40:07 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_color_code(t_color *color)
{
	color->color_code += (color->r << 16);
	color->color_code += (color->g << 8);
	color->color_code += color->b;
}
