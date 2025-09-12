/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:10:34 by agerbaud          #+#    #+#             */
/*   Updated: 2025/04/05 19:41:42 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parse_args(int argc, char **argv, t_game *game)
{
	char	**cub;

	if (argc != 1 || ft_strncmp(argv[0] + ft_strlen(argv[0]) - 4, ".cub", 4))
		return (err(MSG_ERR_USAGE));
	if (ft_isdir(argv[0], O_RDONLY, 0))
		return (err(MSG_ERR_PERM));
	cub = put_in_table(argv[0]);
	if (!cub)
		return (true);
	if (parse_file(cub) || get_textures(cub, &game->texture))
	{
		free_tab(cub);
		return (true);
	}
	game->map = get_map(cub);
	free_tab(cub);
	if (parse_map(game->map, game))
		return (true);
	return (false);
}
