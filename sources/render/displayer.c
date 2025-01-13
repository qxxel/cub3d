/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:34:19 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/13 23:27:27 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	touch(t_game *game, int x_ray, int y_ray)
{
	if (game->map[(int)y_ray][(int)x_ray] == '1')
		return (true);
	return (false);
}

static int	put_img_wall(t_image *img_txr, float percent_y, float percent_x)
{
	unsigned int	*color;
	int	pos;
	int	x;
	int	y;

	x = percent_x * img_txr->width;
	y = percent_y * img_txr->height;
	pos = (y * img_txr->img_data.size_line + x * (img_txr->img_data.bpp / 8));
	color = (unsigned int *)(img_txr->img_data.data + pos);
	return (*color);
}

static int	put_txr_wall(t_texture *txr, float percent_y, float x_ray, float y_ray)
{
	y_ray = (y_ray - (int)y_ray);
	x_ray = (x_ray - (int)x_ray);
	if (y_ray >= 1 - 1 / 64.0)
		return(put_img_wall(&txr->north, percent_y, x_ray));
	else if (x_ray <= 0 + 1 / 64.0)
		return(put_img_wall(&txr->east, percent_y, y_ray));
	else if (y_ray <= 0 + 1 / 64.0)
		return(put_img_wall(&txr->south, percent_y, x_ray));
	else if (x_ray >= 1 - 1 / 64.0)
		return(put_img_wall(&txr->west, percent_y, y_ray));
	return (0);
}

static void	display_wall(t_game *game, float x_ray, float y_ray, int *i, float angle)
{
	float	distance;
	float	wall_height;
	int		start;
	int		j;

	distance = sqrt(pow(game->player.x - x_ray, 2) + pow(game->player.y - y_ray, 2)) * cos(game->player.angle - angle);
	wall_height = 1.6 * HEIGHT / distance;
	start = HEIGHT / 2 - wall_height / 2;
	printf("");
	j = 0;
	while (j < start)
		put_pixel(&game->img_data, game->texture.ceiling.color_code, *i, j++);
	while (j < start + wall_height)
	{
		put_pixel(&game->img_data, put_txr_wall(&game->texture, (j - start) / wall_height, x_ray, y_ray), *i, j);
		j++;
	}
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
	angle_sin = sin(angle) / 64;
	x_ray = game->player.x;
	y_ray = game->player.y;
	while (!touch(game, x_ray, y_ray))
	{
		// put_pixel(&game->img_data, 0xFF0000, x_ray, y_ray);
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
				display_square(&game->img_data, 1, x, y, 0x0000FF);
			x++;
		}
		y++;
	}
}
