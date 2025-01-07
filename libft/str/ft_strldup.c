/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:15:18 by agerbaud          #+#    #+#             */
/*   Updated: 2024/11/08 01:02:11 by agerbaud         ###   ########.fr       */
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