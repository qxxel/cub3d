/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:47:35 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/30 19:14:20 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_rgb(char **rgb, char *part, int i, int j)
{
	while (rgb[i][j] == ' ' || rgb[i][j] == '\t')
		j++;
	if (rgb[i][j] == '-')
		j++;
	while (rgb[i][j])
	{
		if (!ft_isnum(rgb[i][j]))
		{
			if (j > 0 && ft_isnum(rgb[i][j - 1]))
			{
				while (rgb[i][j] == ' ' || rgb[i][j] == '\t')
					j++;
				if (rgb[i][j] == '\0')
					return (false);
			}
			ft_dprintf(2, MSG_ERR_RGB_STANDARD, part);
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
			ft_dprintf(2, MSG_ERR_RGB_EMPTY, part);
			return (true);
		}
		if (check_rgb(rgb, part, i, j))
			return (true);
		i++;
	}
	if (i != 3)
	{
		ft_dprintf(2, MSG_ERR_RGB_EMPTY, part);
		return (true);
	}
	return (false);
}

static bool	check_color(t_color *color, char *part)
{
	if (color->r < 0 || 255 < color->r)
	{
		ft_dprintf(2, MSG_ERR_RGB_STANDARD, part);
		return (true);
	}
	if (color->g < 0 || 255 < color->g)
	{
		ft_dprintf(2, MSG_ERR_RGB_STANDARD, part);
		return (true);
	}
	if (color->b < 0 || 255 < color->b)
	{
		ft_dprintf(2, MSG_ERR_RGB_STANDARD, part);
		return (true);
	}
	return (false);
}

static char	*find_color(char **cub, char *part)
{
	int	i;
	int	j;

	i = 0;
	while (cub[i])
	{
		j = 0;
		while (cub[i][j] == ' ' || cub[i][j] == '\t')
			j++;
		if (!ft_strncmp(cub[i] + j, part, 2))
		{
			j += 2;
			while (cub[i][j] == ' ' || cub[i][j] == '\t')
				j++;
			return (cub[i] + j);
		}
		i++;
	}
	ft_dprintf(2, MSG_ERR_NO_COLOR, part);
	return (NULL);
}

bool	get_color(char **cub, char *part, t_color *color)
{
	char	**rgb;

	rgb = ft_split(find_color(cub, part), ',');
	if (!rgb)
		return (err(MSG_ERR_GETTING_COLOR));
	if (ft_tablen(rgb) < 3)
	{
		if (ft_tablen(rgb) >= 2)
			free(rgb[1]);
		if (ft_tablen(rgb) >= 1)
			free(rgb[0]);
		free(rgb);
		ft_dprintf(2, MSG_ERR_RGB_EMPTY, part);
		return (true);
	}
	if (parse_rgb(rgb, part))
		return (true);
	color->r = ft_atod(rgb[0]);
	color->g = ft_atod(rgb[1]);
	color->b = ft_atod(rgb[2]);
	free_tab(rgb);
	if (check_color(color, part))
		return (true);
	color->color_code = find_color_code(color->r, color->g, color->b);
	return (false);
}
