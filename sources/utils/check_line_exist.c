/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_exist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:58:33 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/30 15:47:50 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*free_previous_lines(char **map, int j)
{
	perror("cub3d");
	while (j >= 0)
		free(map[j--]);
	free(map);
	return (NULL);
}
