/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnesgar <agnesgar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:34:26 by agnesgar          #+#    #+#             */
/*   Updated: 2024/09/30 23:58:01 by agnesgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h> // malloc
# include <stdio.h>
# include <fcntl.h>

// original functions
char				*get_next_line(int fd);
char				*append_to_holder(char *str, char *str2);
const char			*find_newline(const char *str, char c);
char				*hold_line(char *holder);
char				*rest_of_fd(char *holder);
// functions from library
void				*ft_calloc(size_t count, size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
int					ft_strlen(const char *str);

#endif