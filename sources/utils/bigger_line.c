/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigger_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:46:42 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/23 20:50:39 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	bigger_line(char **tab)
{
	int	i;
	int	tmp;
	int	bigger;

	i = 0;
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
