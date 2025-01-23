/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:34:19 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/23 22:56:18 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	touch(t_game *game, int x_ray, int y_ray)
{
	if (game->map[(int)y_ray][(int)x_ray] == '1')
		return (true);
	return (false);
}

static void	send_ray(t_game *game, float angle, int *i)
{
	float	agl_cos;
	float	agl_sin;
	float	x_ray;
	float	y_ray;

	agl_cos = cos(angle) / 64;
	agl_sin = -1 * (sin(angle) / 64);
	x_ray = game->player.x;
	y_ray = game->player.y;
	while (!touch(game, x_ray, y_ray))
	{
		x_ray += agl_cos;
		if (touch(game, x_ray, y_ray))
			break ;
		y_ray += agl_sin;
	}
	display_wall(game, x_ray, y_ray, i, angle);
}

void	display_rays(t_game *game)
{
	int		i;
	float	fraction;
	float	angle;

	fraction = PI / 3 / WIDTH;
	angle = game->player.angle - (PI / 6);
	i = WIDTH;
	while (i > 0)
	{
		send_ray(game, angle, &i);
		angle += fraction;
		i--;
	}
}

void	display_square(t_data *data, int size, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(data, color, x + i, y + j);
			j++;
		}
		i++;
	}
}

void	display_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				display_square(&game->img_data, 8, x * 8, y * 8, 0x000000);
			else if (game->map[y][x] != ' ')
				display_square(&game->img_data, 8, x * 8, y * 8, 0xFFFFFF);
			x++;
		}
		y++;
	}
}
