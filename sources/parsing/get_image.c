/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:45:30 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/08 18:00:12 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	parse_image(char *path)
{
	int	i;

	i = 0;
	if (ft_strncmp(path + ft_strlen(path) - 4, ".xpm", 4))
		return (err("cub3d: textures must be .xpm\n"));
	if (ft_isdir(path, O_RDONLY, 0))
		return (err("cub3d: textures cannot be folders\n"));
	return (false);
}

static char	*extract_path(char *line)
{
	int		i;
	char	*path;

	i = 0;
	path = ft_strdup(line);
	if (!path)
		return (NULL);
	path[ft_strlen(path)] = 0;
	return (path);
}

bool	get_image(char **cub, char *direction, t_image *image)
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
		result = ft_strncmp(cub[i] + j, direction, 3);
		if (!result)
		{
			j += 3;
			while (cub[i][j] == ' ')
				j++;
			image->path = extract_path(cub[i] + j);
			return (parse_image(image->path));
		}
		i++;
	}
	ft_dprintf(2, "cub3d: there is no %s \
		texture in the file put as argument\n", direction);
	return (true);
}
