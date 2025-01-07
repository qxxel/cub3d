/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:45:42 by agerbaud          #+#    #+#             */
/*   Updated: 2024/02/05 11:08:02 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocation;
	size_t	i;

	if (size && nmemb > (__SIZE_MAX__ / size))
		return (NULL);
	i = nmemb * size;
	allocation = (void *)malloc(i);
	if (!allocation)
		return (NULL);
	return (ft_bzero(allocation, i));
}
