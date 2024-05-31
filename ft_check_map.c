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

static size_t	ft_hw_checker(char *file, t_map *map_info)
{
	int		fd;
	int		height;
	char	*line;

	height = 1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(1, "error: fail to open fdf file\n", 30);
		return (1);
	}
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
	return (0);
}

static size_t	ft_check_extension(char *file, char *extension)
{
	int	i;
	int	j;

	i = ft_strlen(file) - ft_strlen(extension);
	j = 0;
	while (j < ft_strlen(extension))
	{
		if (file[i + j] != extension[j])
		{
			write(1, "error: extension not expected\n", 30);
			return (1);
		}
		j++;
	}
	return (0);
}

size_t	ft_check_map(char *file, t_map *map_info)
{
	if (ft_check_extension(file, ".fdf") == 1)
		return (1);
	if (ft_hw_checker(file, map_info) == 1)
		return (1);
	return (0);
}
