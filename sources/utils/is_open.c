/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:37:09 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/09 14:17:05 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_open(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	return (false);
}
