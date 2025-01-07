/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:41:50 by agerbaud          #+#    #+#             */
/*   Updated: 2024/12/10 12:25:20 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	find_define(char **cub, char *def, int i)
{
    int j;
    
	j = 0;
    while (cub[i][j] == ' ')
		j++;
	return (ft_strncmp(cub[i] + j, def, ft_strlen(def)));
}


static void check_define(char **cub, t_countdef *countdef)
{
    int     i;

    i = 0;
    while (cub[i])
    {
        if (!find_define(cub, "NO ", i))
            countdef->NO++;
        else if (!find_define(cub, "SO ", i))
            countdef->SO++;
        else if (!find_define(cub, "WE ", i))
            countdef->WE++;
        else if (!find_define(cub, "EA ", i))
            countdef->EA++;
        else if (!find_define(cub, "F ", i))
            countdef->F++;
        else if (!find_define(cub, "C ", i))
            countdef->C++;
        i++;
    }
}

static int check_define_first(char **cub)
{
    int     i;
    int     count[6];

    i = 0;
    
    while (cub[i] && !(count[0] && count[1] && count[2]\
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
            return (1);
        i++;
    }
    return (0);
}

int parse_file(char **cub)
{
    t_countdef  countdef;

    countdef.NO = 0;
    countdef.SO = 0;
    countdef.WE = 0;
    countdef.EA = 0;
    countdef.F = 0;
    countdef.C = 0;
    check_define(cub, &countdef);
    if (countdef.NO > 1 || countdef.SO > 1 || countdef.WE > 1\
        || countdef.EA > 1 || countdef.F > 1 || countdef.C > 1)
        return (err("cub3d: multiple definition of textures\n"));
    if (!countdef.NO || !countdef.SO || !countdef.WE\
        || !countdef.EA || !countdef.F || !countdef.C)
        return (err("cub3d: missing definition of textures\n"));
    if (check_define_first(cub))
        return (err("cub3d: defines aren't before the map\n"));
    return (0);
}