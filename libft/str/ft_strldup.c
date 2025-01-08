/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:15:18 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/08 14:08:26 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strldup(const char *s, size_t size)
{
	size_t	i;
	char	*cpy;

	cpy = ft_calloc(size + 1, sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < size - 1 && s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	return (cpy);
}
