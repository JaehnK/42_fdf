/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colour.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:44:47 by jaehukim          #+#    #+#             */
/*   Updated: 2024/05/22 23:44:52 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static int	create_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_init_colour(t_map *map_info)
{
	int		x;
	int		y;
	double	c_weight;

	y = 0;
	while (y < map_info->height)
	{
		x = 0;
		while (x < map_info->width)
		{
			if (map_info->colour[y][x] == -1)
			{
				if (map_info->top - map_info->bot != 0)
					c_weight = abs(map_info->altitude[y][x] \
					- map_info->bot / map_info->top - map_info->bot);
				else
					c_weight = 0.5;
				map_info->colour[y][x] = \
create_color(50, 255, 255, 255);
			}
			x++;
		}
		y++;
	}
}

int	ft_compute_colour(t_point *pt1, t_point *pt2, int x, int y)
{
	int		colour;
	double	ratio;

	if ((pt2->x == pt1->x) || (pt2->y == pt1->y))
		ratio = 0.5;
	else
		ratio = abs((x - pt1->x) / (pt2->x - pt1->x)) * \
		abs((y - pt1->y) / (pt2->y - pt1->y));
	colour = create_color(0, \
		(int)(1 - ratio)*\
			(pt1->colour >> 16 & 0xFF) + ratio * (pt2->colour >> 16 & 0xFF), \
		(int)(1 - ratio)*\
			(pt1->colour >> 8 & 0xFF) + ratio * (pt2->colour >> 8 & 0xFF), \
		(int)(1 - ratio)*(pt1->colour & 0xFF) + ratio * (pt2->colour & 0xFF) \
		);
	return (colour);
}
