/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:57:40 by agerbaud          #+#    #+#             */
/*   Updated: 2024/02/05 11:09:04 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((big == NULL && len == 0) || (little == NULL && len == 0))
		return (NULL);
	if (little[0] == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 1;
			while (big [i + j] && little[j] == big[i + j])
				j++;
			if (i + j > len)
				return (NULL);
			if (j == ft_strlen((char *)little))
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
