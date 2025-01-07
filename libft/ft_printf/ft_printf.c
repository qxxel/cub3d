/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:26:20 by agerbaud          #+#    #+#             */
/*   Updated: 2024/02/05 15:21:39 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_what_type(char c, va_list *ap, int *nb_char)
{
	if (c == 'c')
		ft_putchar_pf(va_arg(*ap, int), 1, nb_char);
	else if (c == 's')
		ft_putstr_pf(va_arg(*ap, char *), 1, nb_char);
	else if (c == 'p')
		ft_putpointer_pf(va_arg(*ap, unsigned long long), nb_char, 1);
	else if (c == 'd')
		ft_putnbr_pf(va_arg(*ap, int), 1, nb_char);
	else if (c == 'i')
		ft_putnbr_pf(va_arg(*ap, int), 1, nb_char);
	else if (c == 'u')
		ft_putnbr_unsigned_pf(va_arg(*ap, unsigned int), 1, nb_char);
	else if (c == 'x')
		ft_puthexa_pf(va_arg(*ap, unsigned int), "0123456789abcdef", nb_char);
	else if (c == 'X')
		ft_puthexa_pf(va_arg(*ap, unsigned int), "0123456789ABCDEF", nb_char);
	else if (c == '%')
		ft_putchar_pf(c, 1, nb_char);
	else if (c == '\0')
		(*nb_char) = -1;
	else
		return (0);
	return (1);
}

static int	return_value(const char *format, int nb_char)
{
	if (!format)
		return (-1);
	else
		return (nb_char);
}

int	ft_printf(const char *format, ...)
{
	int		nb_char;
	size_t	i;
	size_t	ok;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	nb_char = 0;
	while (i < ft_strlen(format) && nb_char >= 0)
	{
		if (format[i] != '%')
			ft_putchar_pf(format[i++], 1, &nb_char);
		else
		{
			ok = ft_what_type(format[i + 1], &ap, &nb_char);
			if (!ok)
			{
				ft_putchar_pf(format[i], 1, &nb_char);
				ft_putchar_pf(format[i + 1], 1, &nb_char);
			}
			i = i + 2;
		}
	}
	va_end(ap);
	return (return_value(format, nb_char));
}
