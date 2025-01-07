/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:36:22 by agerbaud          #+#    #+#             */
/*   Updated: 2024/02/05 11:08:38 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_how_many(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 1;
	while (s[i])
	{
		if ((s[i + 1] == c || !s[i + 1]) && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static char	**ft_null_terminated(char **s, int i)
{
	s[i] = NULL;
	return (s);
}

static char	**ft_free_all(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		end;
	int		start;
	char	**final;

	if (!s)
		return (NULL);
	final = (char **)malloc(sizeof(char *) * (ft_how_many(s, c)));
	if (!final)
		return (NULL);
	start = 0;
	end = 0;
	i = 0;
	while (s[end] && final)
	{
		if (s[end++] == c)
			start = end;
		else if (s[end] == '\0' || s[end] == c)
		{
			final[i++] = ft_substr(s, start, end - start);
			if (!final[i - 1])
				return (ft_free_all(final, i - 1));
		}
	}
	return (ft_null_terminated(final, i));
}
