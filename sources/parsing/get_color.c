/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:47:35 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/13 17:45:17 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_rgb(char **rgb, char *part, int i, int j)
{
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
					return (false);
			}
			ft_dprintf(2, "cub3d: the rgb code of %s\
				is not only made up of numbers\n", part);
			return (true);
		}
		j++;
	}
	return (false);
}

static bool	parse_rgb(char **rgb, char *part)
{
	int	i;
	int	j;

	i = 0;
	while (rgb[i] && rgb[i][0])
	{
		j = 0;
		if (rgb[i][j] && rgb[i][j] == '\0')
		{
			ft_dprintf(2, "cub3d: the rgb code of %s is empty\n", part);
			return (true);
		}
		if (check_rgb(rgb, part, i, j))
			return (true);
		i++;
	}
	if (i != 3)
	{
		ft_dprintf(2, "cub3d: the rgb code of %s is empty\n", part);
		return (true);
	}
	return (false);
}

static bool	check_color(t_color *color, char *part)
{
	if (color->r < 0 || 255 < color->r)
	{
		ft_dprintf(2, "cub3d: the rgb code of %s is not up to standard\n", \
			part);
		return (true);
	}
	if (color->g < 0 || 255 < color->g)
	{
		ft_dprintf(2, "cub3d: the rgb code of %s is not up to standard\n", \
			part);
		return (true);
	}
	if (color->b < 0 || 255 < color->b)
	{
		ft_dprintf(2, "cub3d: the rgb code of %s is not up to standard\n", \
			part);
		return (true);
	}
	return (false);
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
	ft_dprintf(2, "cub3d: there is no %s \
		texture in the file put as argument\n", part);
	return (NULL);
}

bool	get_color(char **cub, char *part, t_color *color)
{
	char	**rgb;

	rgb = ft_split(find_color(cub, part), ',');
	if (!rgb)
		return (err("cub3d: error while getting colors\n"));
	if (parse_rgb(rgb, part))
		return (true);
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	ft_free_table(rgb);
	if (check_color(color, part))
		return (true);
	color->color_code = find_color_code(color->r, color->g, color->b);
	return (false);
}
