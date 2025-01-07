/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:08:55 by agerbaud          #+#    #+#             */
/*   Updated: 2024/11/08 00:10:31 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void    ft_free_table(char **table)
{
    int i;
    
    i = 0;
    if (!table)
        return ;
    while (table[i])
    {
        free(table[i]);
        i++;
    }
    free(table);
}