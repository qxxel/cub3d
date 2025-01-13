/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:34:19 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/10 15:34:37 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	touch(t_game *game, int x_ray, int y_ray)
{
	int	x;
	int	y;

	x = x_ray / 64;
	y = y_ray / 64;
	if (game->map[y][x] == '1')
		return (true);
	return (false);
}

static void	display_wall(t_game *game, float x_ray, float y_ray, int *i, float angle)
{
	float	distance;
	float	wall_height;
	int		start;
	int		end;

	distance = sqrt(pow(game->player.x - x_ray, 2) + pow(game->player.y - y_ray, 2)) * cos(game->player.angle - angle);
	wall_height = 100 * HEIGHT / distance;
	start = HEIGHT / 2 - wall_height / 2;
	end = start + wall_height;
	(void)i;
	while (start < end)
	{
		// put_pixel(&game->img_data, 0x0000FF, *i, start);
		start++;
	}
}

static void	send_ray(t_game *game, float angle, int	*i)
{
	float	angle_cos;
	float	angle_sin;
	float	x_ray;
	float	y_ray;

	angle_cos = cos(angle);
	angle_sin = sin(angle);
	x_ray = game->player.x + 10;
	y_ray = game->player.y + 10;
	while (!touch(game, x_ray, y_ray))
	{
		put_pixel(&game->img_data, 0xFF0000, x_ray, y_ray);
		x_ray += angle_cos;
		y_ray += angle_sin;
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
	i = 0;
	while (i < WIDTH)
	{
		send_ray(game, angle, &i);
		angle += fraction;
		i++;
	}
}

void	display_square(t_data *data, int size, int x, int y, int color)
{
	int i;
	int j;

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
				display_square(&game->img_data, 64, x * 64, y * 64, 0x0000FF);
			x++;
		}
		y++;
	}
}
