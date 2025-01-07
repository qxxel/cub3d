/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:10:34 by agerbaud          #+#    #+#             */
/*   Updated: 2024/12/11 13:56:06 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	set_textures(char **cub, t_texture *texture)
{
	if (get_image(cub, "NO ", &texture->north)\
		|| get_image(cub, "SO ", &texture->south)\
		|| get_image(cub, "WE ", &texture->west)\
		|| get_image(cub, "EA ", &texture->east)\
		|| get_color(cub, "F ", &texture->floor)\
		|| get_color(cub, "C ", &texture->ceiling))
		return (1);
	return (0);
}

int parse_args(int argc, char **argv, t_game *game)
{
	char	**cub;
	
	if (argc != 1 || ft_strncmp(argv[0] + ft_strlen(argv[0]) - 4, ".cub", 4))
		return (err("cub3d: usage: ./cub3d [file.cub]\n"));
	if (ft_isdir(argv[0], O_RDONLY, 0))
		return (err("cub3d: open: permission denied\n"));
	cub = put_in_table(argv[0]);
	if (!cub)
		return (1);
	if (parse_file(cub) || set_textures(cub, &game->texture))
		return (1);
	game->map = get_map(cub);
	if (parse_map(game->map, game))
		return (1);
	return (0);
}
