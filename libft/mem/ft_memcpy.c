/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:34:36 by agerbaud          #+#    #+#             */
/*   Updated: 2024/02/05 11:07:16 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_tmp;
	const char	*src_tmp;
	size_t		i;

	if (!dest && !src)
		return (dest);
	dest_tmp = dest;
	src_tmp = src;
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			dest_tmp[i] = src_tmp[i];
			i++;
		}
	}
	else
	{
		while (n--)
			dest_tmp[n] = src_tmp[n];
	}
	return (dest);
}
