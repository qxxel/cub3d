/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:44:16 by agerbaud          #+#    #+#             */
/*   Updated: 2024/02/05 11:15:24 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putchar_pf(char c, int fd, int *nb_char)
{
	char	c_unsigned;

	if ((*nb_char) < 0)
		return ;
	c_unsigned = (unsigned char)c;
	if (write(fd, &c_unsigned, 1) < 0)
	{
		(*nb_char) = -1;
		return ;
	}
	(*nb_char)++;
}
