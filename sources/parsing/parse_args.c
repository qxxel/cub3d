/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:10:34 by agerbaud          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/01/08 13:56:57 by mreynaud         ###   ########.fr       */
=======
/*   Updated: 2025/01/08 13:46:49 by agerbaud         ###   ########.fr       */
>>>>>>> 5e01a958c50b114d8135458bb667a5d1c1418535
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parse_args(int argc, char **argv, t_game *game)
{
	char	**cub;

	if (argc != 1 || ft_strncmp(argv[0] + ft_strlen(argv[0]) - 4, ".cub", 4))
		return (err("cub3d: usage: ./cub3d [file.cub]\n"));
	if (ft_isdir(argv[0], O_RDONLY, 0))
		return (err("cub3d: open: permission denied\n"));
	cub = put_in_table(argv[0]);
	if (!cub)
		return (true);
	if (parse_file(cub) || get_textures(cub, &game->texture))
		return (true);
	game->map = get_map(cub);
	if (parse_map(game->map, game))
		return (true);
	return (false);
}
