/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:20:09 by agerbaud          #+#    #+#             */
/*   Updated: 2024/02/05 11:15:31 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_pf(int n, int fd, int *nb_char)
{
	if (n == -2147483648)
		ft_putstr_pf("-2147483648", fd, nb_char);
	else if (n < 0)
	{
		ft_putchar_pf('-', fd, nb_char);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_pf(n / 10, fd, nb_char);
		ft_putnbr_pf(n % 10, fd, nb_char);
	}
	else if (n >= 0 && (*nb_char) >= 0)
		ft_putchar_pf(n + '0', fd, nb_char);
}
