/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:30:39 by agerbaud          #+#    #+#             */
/*   Updated: 2024/02/05 11:08:05 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_abs(int n)
{
	return (n * ((n > 0) - (n < 0)));
}

char	*ft_itoa(int n)
{
	int		n_tmp;
	size_t	len;
	char	*number;

	n_tmp = n;
	len = 1 + (n <= 0);
	while (n_tmp != 0)
	{
		n_tmp /= 10;
		len++;
	}
	number = (char *)malloc(len * sizeof(char));
	if (!number)
		return (NULL);
	number[--len] = 0;
	if (n < 0)
		number[0] = '-';
	else
		number[0] = '0';
	while (n)
	{
		number[--len] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (number);
}
