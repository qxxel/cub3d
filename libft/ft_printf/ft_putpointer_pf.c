/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:51:35 by agerbaud          #+#    #+#             */
/*   Updated: 2024/02/05 11:15:37 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putpointer_pf(unsigned long long nbr, int *nb_char, int first)
{
	unsigned long long	base_len;
	char				*base;

	if (!nbr)
	{
		ft_putstr_pf("(nil)", 1, nb_char);
		return ;
	}
	base_len = 16;
	base = "0123456789abcdef";
	if (first == 1)
	{
		ft_putstr_pf("0x", 1, nb_char);
		first = 0;
	}
	if (nbr >= base_len)
	{
		ft_putpointer_pf(nbr / base_len, nb_char, first);
		nbr %= base_len;
	}
	if ((*nb_char) >= 0)
		ft_putchar_pf(base[nbr], 1, nb_char);
}
