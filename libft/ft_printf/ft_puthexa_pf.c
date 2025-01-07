/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:51:35 by agerbaud          #+#    #+#             */
/*   Updated: 2024/02/05 11:15:28 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_puthexa_pf(unsigned int nbr, char *base, int *nb_char)
{
	unsigned int	base_len;

	base_len = 16;
	if (nbr >= base_len)
	{
		ft_puthexa_pf(nbr / base_len, base, nb_char);
		nbr %= base_len;
	}
	if ((*nb_char) >= 0)
		ft_putchar_pf(base[nbr], 1, nb_char);
}
