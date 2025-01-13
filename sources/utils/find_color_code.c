/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_color_code.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:06:06 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/13 17:50:01 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		find_color_code(int r, int g, int b)
{
	int res;

	res = (r << 16);
	res += (g << 8);
	res += b;
	return (res);
}
