/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:08:08 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/08 14:07:03 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdbool.h>

# define PI       3.14159265358979323846

# define WIDTH	1280
# define HEIGHT	720

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100
# define KEY_LEFT			65361
# define KEY_RIGHT			65363
# define KEY_P				112
# define KEY_Q				113
# define KEY_ESC			65307

# define KEYPRESS			02
# define KEYPRESSMASK		0
# define KEYRELEASE			03
# define KEYRELEASEMASK		1
# define DESTROYNOTIFY		17
# define DESTROYNOTIFYMASK	17
# define MOTIONNOTIFY		06
# define MOTIONNOTIFYMASK	06

# define WALL_HEIGHT	720
# define WALL_DISTANCE	360.138862107

# define SPEED			5
# define ANGLE_SPEED	0.05

typedef struct	s_countdef
{
	int	NO;
	int	SO;
	int	WE;
	int	EA;
	int	F;
	int	C;
}	t_countdef;

typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct	s_image
{
	char	*path;
}	t_image;

typedef struct	s_key
{
	bool	w;
	bool	s;
	bool	a;
	bool	d;
	bool	left;
	bool	right;
}	t_key;

typedef struct	s_texture
{
	t_image north;
	t_image south;
	t_image	west;
	t_image	east;
	t_color	floor;
	t_color	ceiling;
}	t_texture;

typedef struct	s_player
{
	float	x;
	float	y;
	float	angle;
}	t_player;

typedef struct	s_mouse
{
	int		past_x;
	int		past_y;
	bool	moved;
	bool	showed;
}	t_mouse;

typedef struct s_data
{
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}	t_data;


typedef struct	s_game
{
	t_texture	texture;
	t_key		key;
	t_player	player;
	t_mouse		mouse;
	char		**map;
	void		*mlx;
	void		*win;
	void		*img;
	t_data		img_data;
	void		*minimap_img;
	t_data		minimap_data;
}	t_game;

//	Parsing
bool	get_color(char **cub, char *part, t_color *color);
bool	get_image(char **cub, char *direction, t_image *path);
char	**get_map(char **cub);
bool	get_textures(char **cub, t_texture *texture);
bool	parse_args(int argc, char **argv, t_game *game);
int		parse_file(char **cub);
int 	parse_map(char **map, t_game *game);

//	Raycasting
int		actions(t_game *param);
int		close_window(t_game *param);
int		destroyer(t_game *game);
void	display_map(t_game *game);
void	display_rays(t_game *game);
void	display_square(t_data *data, int size, int x, int y, int color);
void	ft_raycast(t_game *game);
int		keypress(int keycode, t_game *param);
int		keyrelease(int keycode, t_game *param);
bool	init_minimap(t_game *game);
int		motionnotify(int x, int y, t_game *param);

//	Utils
void	clear_image(t_data *data);
int		count_lines(char *file);
bool	err(char *str);
void	*ft_bzero_int(int *s, size_t n);
char	**put_in_table(char	*file);
void	put_pixel(t_data *data, int color, int x, int y);

#endif