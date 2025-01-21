/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:05:16 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/21 19:07:16 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	init_variables(&game);
	if (parse_args(--argc, ++argv, &game))
	{
		destroyer(&game);
		return (1);
	}
	ft_raycast(&game);
	return (0);
}
