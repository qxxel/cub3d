/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:08:08 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/30 17:31:03 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ============================ Includes ============================ */
# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdbool.h>
/* ================================================================== */

/* ============================ Defines ============================ */
# define PI		3.14159265358979323846

# define WIDTH			1280
# define HEIGHT			720
# define HALF_WIDTH		640
# define HALF_HEIGHT	360

# define SPEED			0.1
# define ANGLE_SPEED	0.05

# define MSG_ERR_USAGE				"cub3d: usage: ./cub3d [file.cub]\n"
# define MSG_ERR_PERM				"cub3d: open: permission denied\n"
# define MSG_ERR_MULTI_TEXTURES		"cub3d: multiple definition of textures\n"
# define MSG_ERR_MISSING_TEXTURES	"cub3d: missing definition of textures\n"
# define MSG_ERR_POS_TEXTURES		"cub3d: defines aren't before the map\n"
# define MSG_ERR_PATH_XPM			"cub3d: textures must be .xpm\n"
# define MSG_ERR_PATH_REAL			"cub3d: the texture path must be real\n"
# define MSG_ERR_PATH_DIR			"cub3d: textures cannot be folders\n"
# define MSG_ERR_GETTING_COLOR		"cub3d: error while getting colors\n"
# define MSG_ERR_RGB_EMPTY			"cub3d: the rgb code of %sis empty\n"
# define MSG_ERR_RGB_STANDARD		"cub3d: the rgb code of %sisn't good\n"
# define MSG_ERR_NO_COLOR			"cub3d: there is no %stextures\n"
# define MSG_ERR_NO_MAP				"cub3d: there is no map\n"
# define MSG_ERR_PART_MAP			"cub3d: the map isn't in one part\n"
# define MSG_ERR_MAP_TOO_BIG		"cub3d: the map is too big\n"
# define MSG_ERR_UNKNOWN_CHAR		"cub3d: the map has unknown character\n"
# define MSG_ERR_OPEN_MAP			"cub3d: the map is not closed\n"
# define MSG_ERR_NB_SPAWN			"cub3d: the map hasn't one spawnpoint\n"

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
/* ================================================================= */

/* ============================ Structures ============================ */
typedef struct s_countdef
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
}	t_countdef;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	color_code;
}	t_color;

typedef struct s_int_coordinates
{
	int	x;
	int	y;
}	t_icoord;

typedef struct s_float_coordinates
{
	float	x;
	float	y;
}	t_fcoord;

typedef struct s_data
{
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}	t_data;

typedef struct s_image
{
	char	*path;
	void	*img;
	t_data	img_data;
	int		width;
	int		height;
}	t_image;

typedef struct s_key
{
	bool	w;
	bool	s;
	bool	a;
	bool	d;
	bool	left;
	bool	right;
}	t_key;

typedef struct s_texture
{
	t_image	north;
	t_image	south;
	t_image	west;
	t_image	east;
	t_color	floor;
	t_color	ceiling;
}	t_texture;

typedef struct s_player
{
	float	x;
	float	y;
	float	new_x;
	float	new_y;
	float	angle;
	float	past_x;
	float	past_y;
	float	past_angle;
	bool	moved;
	char	spawn;
}	t_player;

typedef struct s_mouse
{
	int		past_x;
	int		past_y;
	bool	moved;
	bool	showed;
}	t_mouse;

typedef struct s_game
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
	void		*map_img;
	t_data		map_data;
	void		*minimap_img;
	t_data		minimap_data;
}	t_game;
/* ==================================================================== */

/* ============================ Parsing ============================ */
bool	get_color(char **cub, char *part, t_color *color);
bool	get_image(char **cub, char *direction, t_image *path);
char	**get_map(char **cub);
bool	get_textures(char **cub, t_texture *texture);
bool	parse_args(int argc, char **argv, t_game *game);
bool	parse_file(char **cub);
bool	parse_map(char **map, t_game *game);
/* ================================================================= */

/* ============================ Raycasting ============================ */
int		actions(t_game *param);
int		close_window(t_game *param);
int		destroyer(t_game *game);
void	display_rays(t_game *game);
void	display_square(t_data *data, int size, t_icoord coord, int color);
void	display_wall(t_game *game, t_fcoord ray, int *i, float angle);
void	fill_minimap(t_game *game);
void	ft_raycast(t_game *game);
int		keypress(int keycode, t_game *param);
int		keyrelease(int keycode, t_game *param);
void	init_map(t_game *game);
void	init_minimap(t_game *game);
bool	init_texture(t_game *game, t_texture *txr);
int		motionnotify(int x, int y, t_game *param);
void	update_mouse(t_game *game);
/* ==================================================================== */

/* ============================ Utils ============================ */
int		ft_atod(const char *nptr);
int		bigger_line(char **tab, int i);
void	*free_previous_lines(char **map, int j);
bool	check_wall(t_game *game, float x_dest, float y_dest);
void	clear_image(t_data *data);
int		count_lines(char *file);
bool	err(char *str);
int		find_color_code(int r, int g, int b);
void	fix_angle(t_game *game);
void	free_tab(char **map);
void	*ft_bzero_int(int *s, size_t n);
void	init_spawn(t_game *game);
void	init_variables(t_game *game);
bool	is_open(char c);
char	**put_in_table(char	*file);
void	put_pixel(t_data *data, int color, int x, int y);
/* =============================================================== */

#endif
