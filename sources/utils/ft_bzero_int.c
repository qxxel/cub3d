/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:22:07 by agerbaud          #+#    #+#             */
/*   Updated: 2024/12/10 12:25:20 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	*ft_bzero_int(int *s, size_t n)
{
	int	*j;

	j = s;
	while (n--)
		j[n] = 0;
	return (s);
}