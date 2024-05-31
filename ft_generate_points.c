/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_points.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:07:01 by jaehukim          #+#    #+#             */
/*   Updated: 2024/05/23 11:08:20 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	*ft_generate_pt(int x, int y, t_map *map)
{
	t_point	*point;

	point = (t_point *) malloc(sizeof(t_point *));
	point->x = (int) map->proj_x[y][x] + map->x_offset + map->keys.x_keyoffset;
	point->y = (int) map->proj_y[y][x] + map->y_offset + map->keys.y_keyoffset;
	point->z = (int) map->altitude[y][x];
	point->colour = map->colour[y][x];
	return (point);
}

void	free_points(t_point **pts)
{
	int	i;

	i = 0;
	while ((pts)[i])
	{
		free((pts)[i]);
		i++;
	}
	free(pts);
}

t_point	**ft_gen_fourpts(int x, int y, t_map *map)
{
	t_point	**points;

	points = (t_point **) malloc(sizeof(t_point *) * 5);
	points[0] = ft_generate_pt(x, y, map);
	points[1] = ft_generate_pt(x + 1, y, map);
	points[2] = ft_generate_pt(x, y + 1, map);
	points[3] = ft_generate_pt(x + 1, y + 1, map);
	points[4] = NULL;
	return (points);
}
