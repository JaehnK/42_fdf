/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:24:27 by jaehukim          #+#    #+#             */
/*   Updated: 2024/03/29 10:41:52 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

void	*ft_gnl_calloc(size_t nmemb, size_t size);
char	*ft_gnl_substr(char const *s, unsigned int start, size_t len);
char	*ft_gnl_strdup(char *s, int extra_size);
char	*ft_gnl_strjoin(char *s1, char const *s2);
size_t	ft_gnl_strlen(const char *s, char c);
char	*get_next_line(int fd);

#endif
