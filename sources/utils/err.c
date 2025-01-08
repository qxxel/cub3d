/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:07:29 by agerbaud          #+#    #+#             */
/*   Updated: 2025/01/08 13:57:59 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int err(char *str)
{
    int i;

    i = ft_strlen(str);
    write(2, str, i);
    return (1);
}
