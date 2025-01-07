/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:03:26 by agerbaud          #+#    #+#             */
/*   Updated: 2024/11/14 12:09:19 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	init_buffer(char **buffer, char *memory, size_t count, int *fd)
{
	int	size;

	size = 0;
	(*buffer) = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buffer)
		return (*fd = -1, 0);
	if (count == 0 && memory[0] != '\0')
	{
		*buffer = ft_strcpy((*buffer), memory);
		while (memory[size])
			size++;
	}
	else
	{
		size = read(*fd, (*buffer), BUFFER_SIZE);
		if (size <= 0)
		{
			free(*buffer);
			if (size == -1)
				*fd = -1;
			return (size);
		}
	}
	(*buffer)[size] = '\0';
	return (size);
}

static char	*put_into_buffer(char *mem, size_t count, int *fd)
{
	int		size;
	char	*buffer;
	char	*line;

	size = init_buffer(&buffer, mem, count, fd);
	if (size <= 0)
		return (NULL);
	line = NULL;
	if (mem && (mem[size] == 0 || size == BUFFER_SIZE) && check_nl(buffer) != 1)
		line = put_into_buffer(mem, (count + size), fd);
	if (*fd == -1)
		return (free(buffer), NULL);
	if (!line)
	{
		line = malloc(sizeof(char) * (count + ft_last_index(buffer) + 2));
		if (!line)
			return (free(buffer), *fd = -1, NULL);
		line[count + ft_last_index(buffer) + 1] = 0;
		if (buffer[ft_last_index(buffer)] != 0)
			mem = ft_strcpy(mem, buffer + ft_last_index(buffer) + 1);
	}
	size = ft_last_index(buffer) + 1;
	while (--size >= 0)
		line[count + size] = buffer[size];
	return (free(buffer), line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	memory[BUFFER_SIZE + 1];
	size_t		count;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	count = 0;
	line = put_into_buffer(memory, count, &fd);
	if (fd == -1 || !line)
		ft_bzero(memory, sizeof(memory));
	return (line);
}
