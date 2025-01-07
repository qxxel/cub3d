/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:57:46 by agerbaud          #+#    #+#             */
/*   Updated: 2024/02/05 11:08:41 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (s[0] != 0 || (unsigned char)c == 0)
	{
		if (s[0] == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
