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

static int	ft_init_colour_gen(double weight)
{
	int	min_col[3];
	int	max_col[3];

	min_col[0] = 255;
	min_col[1] = 100;
	min_col[2] = 100;
	max_col[0] = 100;
	max_col[1] = 200;
	max_col[2] = 255;
	return (create_color(0, \
	(int)((1 - weight) * min_col[0] + weight * max_col[0]), \
	(int)((1 - weight) * min_col[1] + weight * max_col[2]), \
	(int)((1 - weight) * min_col[1] + weight * max_col[2])));
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
					c_weight = abs((map_info->altitude[y][x] \
	- map_info->bot) / (map_info->top - map_info->bot));
				else
					c_weight = 0.5;
				map_info->colour[y][x] = ft_init_colour_gen(c_weight);
			}
			x++;
		}
		y++;
	}
}

double	ft_compute_ratio(t_point *pt1, t_point *pt2, int x, int y)
{
	double	total_dist;
	double	current_dist;

	total_dist = sqrt(pow((pt2->x - pt1->x), 2) + pow((pt2->y - pt1->y), 2));
	current_dist = sqrt(pow((x - pt1->x), 2) + pow((y - pt1->y), 2));
	return (current_dist / total_dist);
}

int	ft_compute_colour(t_point *pt1, t_point *pt2, int x, int y)
{
	int		colour;
	double	ratio;

	ratio = ft_compute_ratio(pt1, pt2, x, y);
	colour = create_color(0, \
	(int)((1 - ratio) * (pt1->colour >> 16 & 0xFF) + ratio * \
	(pt2->colour >> 16 & 0xFF)), \
	(int)((1 - ratio) * (pt1->colour >> 8 & 0xFF) + ratio * \
	(pt2->colour >> 8 & 0xFF)), \
	(int)((1 - ratio) * (pt1->colour & 0xFF) + ratio * (pt2->colour & 0xFF)) \
	);
	return (colour);
}
