/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:42:16 by mreynaud          #+#    #+#             */
/*   Updated: 2025/01/22 16:43:05 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	put_img_wall(t_image *img_txr, char c, float prct_y, float prct_x)
{
	int				x;
	int				y;
	int				pos;
	unsigned int	*color;

	x = prct_x * img_txr->width;
	y = prct_y * img_txr->height;
	if (c == 'n' || c == 'e')
		pos = (y * img_txr->img_data.size_line + x * (img_txr->img_data.bpp / 8));
	else
		pos = ((y + 1) * img_txr->img_data.size_line - x * (img_txr->img_data.bpp / 8));
	color = (unsigned int *)(img_txr->img_data.data + pos);
	return (*color);
}

static int	put_txr_wall(t_game *game, float prct_y, float x_ray, float y_ray, float angle)
{
	t_texture	*txr;
	int			int_x_ray;
	int			int_y_ray;

	txr = &game->texture;
	while (angle < (float)0)
		angle += 2 * PI;
	while (angle > (float)(2 * PI))
		angle -= 2 * PI;
	int_x_ray = (int)x_ray;
	int_y_ray = (int)y_ray;
	x_ray -= int_x_ray;
	y_ray -= int_y_ray;

	if (((game->map[int_y_ray][int_x_ray + 1] && game->map[int_y_ray][int_x_ray + 1] == '0') || \
		(int_x_ray - 1 > 0 && game->map[int_y_ray][int_x_ray - 1] == '0')) && \
		!((game->map[int_y_ray + 1] && game->map[int_y_ray + 1][int_x_ray] == '0') || \
		(int_y_ray - 1 > 0 && game->map[int_y_ray - 1] && game->map[int_y_ray - 1][int_x_ray] == '0')))
	{

		if (x_ray <= 1 / 64.0 && (angle < PI / 2 || angle > 3 * PI / 2))
			return(put_img_wall(&txr->east, 'e', prct_y, y_ray)); // return (0xFF0000); // red
		else if (x_ray >= 1 - 1 / 64.0 && angle > PI / 2 && angle < 3 * PI / 2)
			return(put_img_wall(&txr->west, 'w', prct_y, y_ray)); // return (0xFF00FF); // pink
	}
	else if (((game->map[int_y_ray + 1] && game->map[int_y_ray + 1][int_x_ray] == '0') || \
		(int_y_ray - 1 > 0 && game->map[int_y_ray - 1] && game->map[int_y_ray - 1][int_x_ray] == '0')) && \
		(!((game->map[int_y_ray][int_x_ray + 1] && game->map[int_y_ray][int_x_ray + 1] == '0') || \
		(int_x_ray - 1 > 0 && game->map[int_y_ray][int_x_ray - 1] == '0'))))
	{
		if (y_ray >= 1 - 1 / 64.0 && angle < PI && angle > 0)
			return(put_img_wall(&txr->north, 'n', prct_y, x_ray)); // return (0xFFFF00); // yellow
		else if (y_ray <= 1 / 64.0 && angle > PI && angle < 2 * PI)
			return(put_img_wall(&txr->south, 's', prct_y, x_ray)); // return (0x00FF00); // green
	}
	if (y_ray >= 1 - 1 / 64.0 && angle < PI && angle > 0)
		return(put_img_wall(&txr->north, 'n', prct_y, x_ray)); // return (0xFFFF00); // yellow
	else if (y_ray <= 1 / 64.0 && angle > PI && angle < 2 * PI)
		return(put_img_wall(&txr->south, 's', prct_y, x_ray)); // return (0x00FF00); // green
	else if (x_ray <= 1 / 64.0 && (angle < PI / 2 || angle > 3 * PI / 2))
		return(put_img_wall(&txr->east, 'e', prct_y, y_ray)); // return (0xFF0000); // red
	else if (x_ray >= 1 - 1 / 64.0 && angle > PI / 2 && angle < 3 * PI / 2)
		return(put_img_wall(&txr->west, 'w', prct_y, y_ray)); // return (0xFF00FF); // pink
	return (0);
}

void	display_wall(t_game *game, float x_ray, float y_ray, int *i, float angle)
{
	float	distance;
	float	wall_height;
	int		start;
	int		j;

	distance = sqrt(pow(game->player.x - x_ray, 2) \
		+ pow(game->player.y - y_ray, 2)) * cos(game->player.angle - angle);
	wall_height = 1.6 * HEIGHT / distance;
	start = HALF_HEIGHT - wall_height / 2;
	j = 0;
	while (j < start)
		put_pixel(&game->img_data, game->texture.ceiling.color_code, *i, j++);
	while (j < start + wall_height)
	{
		put_pixel(&game->img_data, put_txr_wall(game, (j - start) \
			/ wall_height, x_ray, y_ray, angle), *i, j);
		j++;
	}
	while (j < HEIGHT)
		put_pixel(&game->img_data, game->texture.floor.color_code, *i, j++);
}
