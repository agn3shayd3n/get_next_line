/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnesgar <agnesgar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:34:26 by agnesgar          #+#    #+#             */
/*   Updated: 2024/09/30 23:58:01 by agnesgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

static char	*read_from_file(char *holder, int fd)
{
	int				bytes_read;
	char			*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (free(holder), NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !find_newline(holder, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0 && bytes_read <= BUFFER_SIZE)
		{
			buffer[bytes_read] = '\0';
			holder = append_to_holder(holder, buffer);
		}
		else if (bytes_read == -1)
		{
			free(buffer);
			return (free(holder), NULL);
		}
	}
	free (buffer);
	return (holder);
}

char	*get_next_line(int fd)
{
	static char	*holder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!holder)
		holder = ft_calloc(1, sizeof(char));
	if (!holder || !find_newline(holder, '\n'))
	{
		holder = read_from_file(holder, fd);
		if (!holder)
			return (NULL);
	}
	line = hold_line(holder);
	if (!line)
	{
		free (holder);
		holder = NULL;
		return (NULL);
	}
	holder = rest_of_fd(holder);
	return (line);
}

char	*hold_line(char *holder)
{
	const char	*newline;
	int			len;
	char		*line;
	int			holder_len;
	char		*new_holder;

	if (!holder)
		return (NULL);
	newline = find_newline(holder, '\n');
	if (!newline && *holder != '\0')
	{
		holder_len = ft_strlen(holder);
		new_holder = (char *)malloc(sizeof(char) * holder_len + 1);
		if (!new_holder)
			return (NULL);
		ft_strlcpy(new_holder, holder, holder_len + 1);
		return (new_holder);
	}
	if (!newline)
		return (NULL);
	len = newline - holder + 1;
	line = (char *)malloc(sizeof(char) * len + 1);
	ft_strlcpy(line, holder, len + 1);
	return (line);
}

char	*rest_of_fd(char *holder)
{
	const char	*newline;
	char		*rest;
	int			newline_len;

	if (!holder)
		return (NULL);
	newline = find_newline(holder, '\n');
	if (!newline)
		return (free(holder), NULL);
	newline_len = ft_strlen(newline);
	rest = (char *)malloc(sizeof(char) * newline_len + 1);
	if (!rest)
		return (free(holder), NULL);
	ft_strlcpy(rest, newline + 1, newline_len + 1);
	return (free (holder), rest);
}

char	*append_to_holder(char *str, char *str2)
{
	char	*temp;
	int		str2_len;

	if (!str2)
		return (NULL);
	if (!str)
	{
		str2_len = ft_strlen(str2);
		str = (char *)malloc(sizeof(char) * str2_len + 1);
		if (!str)
			return (NULL);
		ft_strlcpy(str, str2, str2_len + 1);
		return (str);
	}
	temp = ft_strjoin(str, str2);
	return (free(str), temp);
}
