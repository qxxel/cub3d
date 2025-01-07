/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_pf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:52:14 by agerbaud          #+#    #+#             */
/*   Updated: 2024/02/05 11:15:34 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_unsigned_pf(unsigned int n, int fd, int *nb_char)
{
	if (n > 9)
	{
		ft_putnbr_pf(n / 10, fd, nb_char);
		ft_putnbr_pf(n % 10, fd, nb_char);
	}
	else if ((*nb_char) >= 0)
		ft_putchar_pf(n + '0', fd, nb_char);
}
