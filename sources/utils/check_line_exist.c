/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_exist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:58:33 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/24 14:17:52 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_line_exist(char **map, int j)
{
	if (!map[j])
	{
		perror("cub3d");
		while (j >= 0)
			free(map[j--]);
		free(map);
		return (false);
	}
	return (true);
}
