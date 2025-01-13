/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_color_code.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:06:06 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/13 17:22:57 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_color_code(t_color *color)
{
	int	final_color;

	final_color = 0;
	final_color += (color->r << 16);
	final_color += (color->g << 8);
	final_color += color->b;
	return (final_color);
}
