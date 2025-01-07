/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:11:33 by agerbaud          #+#    #+#             */
/*   Updated: 2024/02/05 11:15:40 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putstr_pf(char *s, int fd, int *nb_char)
{
	size_t	i;

	if (!s)
	{
		ft_putstr_pf("(null)", 1, nb_char);
		return ;
	}
	i = 0;
	while (s[i] && (*nb_char) >= 0)
	{
		ft_putchar_pf(s[i], fd, nb_char);
		i++;
	}
}
