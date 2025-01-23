/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:34:19 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/23 23:39:37 by agerbaud         ###   ########.fr       */
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
	float		agl_cos;
	float		agl_sin;
	t_fcoord	ray;

	agl_cos = cos(angle) / 64;
	agl_sin = -1 * (sin(angle) / 64);
	ray.x = game->player.x;
	ray.y = game->player.y;
	while (!touch(game, ray.x, ray.y))
	{
		ray.x += agl_cos;
		if (touch(game, ray.x, ray.y))
			break ;
		ray.y += agl_sin;
	}
	display_wall(game, ray, i, angle);
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

void	display_square(t_data *data, int size, t_icoord coord, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(data, color, coord.x + i, coord.y + j);
			j++;
		}
		i++;
	}
}
