/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:47:35 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/08 14:13:53 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_rgb(char **rgb, char *part)
{
	int	i;
	int	j;

	i = 0;
	while (rgb[i] && rgb[i][0])
	{
		j = 0;
		if (rgb[i][j] && rgb[i][j] == '\0')
		{
			ft_printf("cub3d: the rgb code of %s is empty\n", part); // a mettre en dprintf (fd ==> 2)
			return (1);
		}
		while (rgb[i][j] == ' ')
			j++;
		if (rgb[i][j] == '-')
			j++;
		while (rgb[i][j])
		{
			if (!ft_isnum(rgb[i][j]))
			{
				if (j > 0 && ft_isnum(rgb[i][j - 1]))
				{
					while (rgb[i][j] == ' ')
						j++;
					if (rgb[i][j] == '\0')
						return (0);
				}
				ft_printf("cub3d: the rgb code of %s\
					is not only made up of numbers\n", part); // a mettre en dprintf (fd ==> 2)
				return (1);
			}
			j++;
		}
		i++;
	}
	if (i != 3)
	{
		ft_printf("cub3d: the rgb code of %s is empty\n", part); // a mettre en dprintf (fd ==> 2)
		return (1);
	}
	return (0);
}

static int	check_color(t_color *color, char *part)
{
	if (color->r < 0 || 255 < color->r)
	{
		ft_printf("cub3d: the rgb code of %s is not up to standard\n", part); // a mettre en dprintf (fd ==> 2)
		return (1);
	}
	if (color->g < 0 || 255 < color->g)
	{
		ft_printf("cub3d: the rgb code of %s is not up to standard\n", part); // a mettre en dprintf (fd ==> 2)
		return (1);
	}
	if (color->b < 0 || 255 < color->b)
	{
		ft_printf("cub3d: the rgb code of %s is not up to standard\n", part); // a mettre en dprintf (fd ==> 2)
		return (1);
	}
	return (0);
}

static char	*find_color(char **cub, char *part)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	while (cub[i])
	{
		j = 0;
		while (cub[i][j] == ' ')
			j++;
		result = ft_strncmp(cub[i] + j, part, 2);
		if (!result)
		{
			j += 2;
			while (cub[i][j] == ' ')
				j++;
			return (cub[i] + j);
		}
		i++;
	}
	ft_printf("cub3d: there is no %s\
		color in the file put as argument\n", part); // have to dprintf (fd ==> 2)
	return (NULL);
}

int	get_color(char **cub, char *part, t_color *color)
{
	char	**rgb;

	rgb = ft_split(find_color(cub, part), ',');
	if (!rgb)
		return (1); // add error message
	if (parse_rgb(rgb, part))
		return (1);
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	ft_free_table(rgb); // free(): invalid pointer??
	if (check_color(color, part))
		return (1);
	return (0);
}
