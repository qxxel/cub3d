/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:43:21 by agerbaud          #+#    #+#             */
/*   Updated: 2024/02/05 11:07:14 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_tmp = s1;
	const unsigned char	*s2_tmp = s2;
	size_t				i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1_tmp[i] == s2_tmp[i])
		i++;
	return (s1_tmp[i] - s2_tmp[i]);
}
