/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:45:30 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/21 16:50:56 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	parse_image(char *path)
{
	int	fd;
	int	i;

	i = 0;
	if (ft_strncmp(path + ft_strlen(path) - 4, ".xpm", 4))
		return (err(MSG_ERR_PATH_XPM));
	if (path[0] == '/')
		return (err(MSG_ERR_PATH_REAL));
	if (ft_isdir(path, O_RDONLY, 0))
		return (err(MSG_ERR_PATH_DIR));
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("cub3d");
		return (true);
	}
	close (fd);
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
		while (cub[i][j] == ' ' || cub[i][j] == '\t')
			j++;
		result = ft_strncmp(cub[i] + j, direction, 3);
		if (!result)
		{
			j += 3;
			while (cub[i][j] == ' ' || cub[i][j] == '\t')
				j++;
			image->path = extract_path(cub[i] + j);
			return (parse_image(image->path));
		}
		i++;
	}
	return (err(MSG_ERR_MISSING_TEXTURES));
}
