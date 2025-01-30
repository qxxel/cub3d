/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:26:02 by mreynaud          #+#    #+#             */
/*   Updated: 2025/01/30 17:36:49 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_white_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	else
		return (0);
}

int	ft_atod(const char *nptr)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (ft_is_white_space(nptr[i]) > 0)
		i++;
	if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (nb != (nb * 10 + (nptr[i] - '0')) / 10)
			return (-1);
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb);
}
