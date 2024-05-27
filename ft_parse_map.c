/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:48:05 by jaehukim          #+#    #+#             */
/*   Updated: 2024/05/22 17:02:30 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	ft_char2hexint(char *str)
{
	int	i;
	int	digit;
	int	ret;

	i = 7;
	digit = 1;
	ret = 0;
	while (i > 1)
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			ret += (str[i] - 'a' + 10) * digit;
		else if (str[i] >= 'A' && str[i] <= 'F')
			ret += (str[i] - 'A' + 10) * digit;
		else if (str[i] >= '0' && str[i] <= '9')
			ret += (str[i] - '0') * digit;
		digit *= 16;
		i--;
	}
	return (ret);
}

void	ft_get_elems(char *line, int *alts, int *colos)
{
	int		idx;
	char	**elems;
	char	**altitude_colour;

	idx = 0;
	elems = ft_split(line, ' ');
	while (elems[idx])
	{
		altitude_colour = ft_split(elems[idx], ',');
		alts[idx] = ft_atoi(altitude_colour[0]);
		if (altitude_colour[1])
			colos[idx] = ft_char2hexint(altitude_colour[1]);
		else
			colos[idx] = -1;
		free_arr(altitude_colour);
		idx++;
	}
	free_arr(elems);
}

void	ft_get_topbot(t_map *map_info)
{
	int	x;
	int	y;

	map_info->top = -1;
	map_info->bot = 1;
	y = 0;
	while (y < map_info->height)
	{
		x = 0;
		while (x < map_info->width)
		{
			if (map_info->top < map_info->altitude[y][x])
				map_info->top = map_info->altitude[y][x];
			if (map_info->bot > map_info->altitude[y][x])
				map_info->bot = map_info->altitude[y][x];
			x++;
		}
		y++;
	}
}

void	ft_parse_map(char *file, t_map *map_info)
{
	int		fd;
	int		idx;
	char	*line;

	idx = 0;
	fd = open(file, O_RDONLY);
	map_info->altitude = (int **) malloc(sizeof(int *) \
		* (map_info->height + 1));
	map_info->colour = (int **) malloc(sizeof(int *) \
		* (map_info->height + 1));
	while (idx < map_info->height)
	{
		line = get_next_line(fd);
		map_info->altitude[idx] = (int *) malloc(sizeof(int) \
		* (map_info->width + 1));
		map_info->colour[idx] = (int *) malloc(sizeof(int) \
		* (map_info->width + 1));
		ft_get_elems(line, map_info->altitude[idx], map_info->colour[idx]);
		free(line);
		idx++;
	}
	map_info->altitude[idx] = NULL;
	map_info->colour[idx] = NULL;
	ft_get_topbot(map_info);
}
