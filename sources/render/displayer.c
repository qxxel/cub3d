/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:34:19 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/13 23:31:37 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	touch(t_game *game, int x_ray, int y_ray)
{
	if (game->map[(int)y_ray][(int)x_ray] == '1')
		return (true);
	return (false);
}

int	put_img_wall(t_image *north, float percent_y, float percent_x)
{
	int	y;
	int	x;
	int	pos;
	unsigned int	*color;

	x = percent_x * north->width;
	// printf("[%d]\n", x % 64);
	// x = percent_x;
	y = percent_y * north->height;
	pos = (y * north->img_data.size_line + x * (north->img_data.bpp / 8));
	color = (unsigned int *)(north->img_data.data + pos);
	return (*color);
}

static void	display_wall(t_game *game, float x_ray, float y_ray, int *i, float angle)
{
	float	distance;
	float	wall_height;
	int		start;
	int		start2;
	int		end;
	int		j = 0;

	distance = sqrt(pow(game->player.x - x_ray, 2) + pow(game->player.y - y_ray, 2)) * cos(game->player.angle - angle);
	wall_height = 1.6 * HEIGHT / distance;
	start = HEIGHT / 2 - wall_height / 2;
	start2 = start;
	end = start + wall_height;
	while (j < start)
		put_pixel(&game->img_data, game->texture.ceiling.color_code, *i, j++);
	while (start < end)
	{
		put_pixel(&game->img_data, put_img_wall(&game->texture.north, (start - start2) / wall_height, (float)((int)x_ray % 64) / 64), *i, start);
		start++;
	}
	j = end;
	while (j < HEIGHT)
		put_pixel(&game->img_data, game->texture.floor.color_code, *i, j++);
}

static void	send_ray(t_game *game, float angle, int	*i)
{
	float	angle_cos;
	float	angle_sin;
	float	x_ray;
	float	y_ray;

	angle_cos = cos(angle) / 64;
	angle_sin = -1 * (sin(angle) / 64);
	x_ray = game->player.x;
	y_ray = game->player.y;
	// (void)i;
	while (!touch(game, x_ray, y_ray))
	{
		// put_pixel(&game->img_data, 0xFF0000, x_ray * 64, y_ray * 64);
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
