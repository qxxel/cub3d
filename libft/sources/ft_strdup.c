/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:45:46 by deydoux           #+#    #+#             */
/*   Updated: 2024/11/14 17:28:56 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*ptr;

	size = sizeof(char) * (ft_strlen(s) + 1);
	ptr = malloc(size);
	if (ptr)
		ft_strlcpy(ptr, s, size);
	return (ptr);
}
