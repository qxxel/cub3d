/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:41:50 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/21 15:42:59 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	find_define(char **cub, char *def, int i)
{
	int	j;

	j = 0;
	while (cub[i][j] == ' ' || cub[i][j] == '\t')
		j++;
	return (ft_strncmp(cub[i] + j, def, ft_strlen(def)));
}

static void	check_define(char **cub, t_countdef *countdef)
{
	int	i;

	i = 0;
	while (cub[i])
	{
		if (!find_define(cub, "NO ", i))
			countdef->no++;
		else if (!find_define(cub, "SO ", i))
			countdef->so++;
		else if (!find_define(cub, "WE ", i))
			countdef->we++;
		else if (!find_define(cub, "EA ", i))
			countdef->ea++;
		else if (!find_define(cub, "F ", i))
			countdef->f++;
		else if (!find_define(cub, "C ", i))
			countdef->c++;
		i++;
	}
}

static bool	check_define_first(char **cub)
{
	int	i;
	int	count[6];

	i = 0;
	ft_bzero_int(count, 6);
	while (cub[i] && !(count[0] && count[1] && count[2] \
		&& count[3] && count[4] && count[5]))
	{
		if (!find_define(cub, "NO ", i))
			count[0] = 1;
		else if (!find_define(cub, "SO ", i))
			count[1] = 1;
		else if (!find_define(cub, "WE ", i))
			count[2] = 1;
		else if (!find_define(cub, "EA ", i))
			count[3] = 1;
		else if (!find_define(cub, "F ", i))
			count[4] = 1;
		else if (!find_define(cub, "C ", i))
			count[5] = 1;
		else if (!(cub[i][0] == '\0'))
			return (true);
		i++;
	}
	return (false);
}

bool	parse_file(char **cub)
{
	t_countdef	countdef;

	countdef.no = 0;
	countdef.so = 0;
	countdef.we = 0;
	countdef.ea = 0;
	countdef.f = 0;
	countdef.c = 0;
	check_define(cub, &countdef);
	if (countdef.no > 1 || countdef.so > 1 || countdef.we > 1 \
		|| countdef.ea > 1 || countdef.f > 1 || countdef.c > 1)
		return (err("cub3d: multiple definition of textures\n"));
	if (!countdef.no || !countdef.so || !countdef.we \
		|| !countdef.ea || !countdef.f || !countdef.c)
		return (err("cub3d: missing definition of textures\n"));
	if (check_define_first(cub))
		return (err("cub3d: defines aren't before the map\n"));
	return (false);
}
