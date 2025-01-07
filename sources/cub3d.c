/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:05:16 by agerbaud          #+#    #+#             */
/*   Updated: 2024/12/14 01:42:01 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	
	if (parse_args(--argc, ++argv, &game))
		return (1);
	ft_raycast(&game);
	// ft_printf("NO %s\nSO %s\nWE %s\nEA %s\nF %i,%i,%i\nC %i,%i,%i\n\n",\
	// 	game.texture.north.path, game.texture.south.path, game.texture.west.path, game.texture.east.path, \
	// 	game.texture.floor.r, game.texture.floor.g, game.texture.floor.b, \
	// 	game.texture.ceiling.r, game.texture.ceiling.g, game.texture.ceiling.b);
	// int i = 0;
	// while (game.map[i])
	// {
	// 	ft_printf("%s\n", game.map[i]);
	// 	i++;
	// }
	return (0);
}