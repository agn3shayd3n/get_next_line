/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnesgar <agnesgar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:34:26 by agnesgar          #+#    #+#             */
/*   Updated: 2024/09/30 23:58:01 by agnesgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	if (!src || !dst)
		return (0);
	i = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (size != 0)
		dst[i] = '\0';
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*new;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strjoin("", s2));
	if (!s2)
		return (ft_strjoin(s1, ""));
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, ft_strlen(s1) + 1);
	ft_strlcpy(new + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (new);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

const char	*find_newline(const char *str, char c)
{
	if (!str)
		return (NULL);
	while (*str != '\0')
	{
		if (*str == c)
			return ((const char *)str);
		str++;
	}
	return (NULL);
}
