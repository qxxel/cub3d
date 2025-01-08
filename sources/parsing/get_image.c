/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:45:30 by agerbaud          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/01/08 13:56:40 by mreynaud         ###   ########.fr       */
=======
/*   Updated: 2025/01/08 14:19:19 by agerbaud         ###   ########.fr       */
>>>>>>> 5e01a958c50b114d8135458bb667a5d1c1418535
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
			image->path = extract_path(cub[i] + j); // maybe check if its a good path ??
			return (parse_image(image->path));
		}
		i++;
	}
	err("cub3d: there is no ");
	err(direction);
	err(" texture in the file put as argument\n"); // dprintf
	return (true);
}
