/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigger_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:46:42 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/30 15:35:55 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	bigger_line(char **tab, int i)
{
	int	tmp;
	int	bigger;

	bigger = 0;
	while (tab && tab[i])
	{
		tmp = ft_strlen(tab[i]);
		if (tmp > bigger)
			bigger = tmp;
		i++;
	}
	return (bigger);
}
