/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:34:20 by jaehukim          #+#    #+#             */
/*   Updated: 2024/05/23 11:09:00 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static size_t	ft_width_checker(char *s)
{
	int		i;
	int		cnt;
	char	c;

	cnt = 0;
	i = 1;
	c = ' ';
	if (!s[0])
		return (0);
	if (s[0] != c)
		cnt++;
	while (s[i] != '\0')
	{
		if (s[i - 1] == c && s[i] != c)
			cnt++;
		i++;
	}
	return (cnt);
}

static void	ft_hw_checker(char *file, t_map *map_info)
{
	int		fd;
	int		height;
	char	*line;

	height = 1;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	map_info->width = ft_width_checker(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	map_info->height = height - 1;
	close(fd);
}

size_t	ft_check_map(char *file, t_map *map_info)
{
	if (!ft_strnstr(file, ".fdf", ft_strlen(file)))
		return (-1);
	ft_hw_checker(file, map_info);
	return (0);
}
