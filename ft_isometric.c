/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:39:48 by jaehukim          #+#    #+#             */
/*   Updated: 2024/05/16 10:39:49 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	rotate_x(t_map *map_info, int x, int y)
{
	double	prev_x;
	double	prev_y;
	double	prev_z;
	double	theta;

	prev_x = map_info->proj_x[y][x];
	prev_y = map_info->proj_y[y][x] * -1;
	prev_z = map_info->proj_z[y][x] * -1;
	theta = map_info->keys.rot_x;
	if (theta != 0)
	{
		map_info->proj_x[y][x] = prev_x;
		map_info->proj_y[y][x] = (prev_y * cos(theta)) - (prev_z * sin(theta));
		map_info->proj_z[y][x] = (prev_y * sin(theta)) + (prev_z * cos(theta));
	}
}

void	rotate_y(t_map *map_info, int x, int y)
{
	double	prev_x;
	double	prev_y;
	double	prev_z;
	double	theta;

	prev_x = map_info->proj_x[y][x];
	prev_y = map_info->proj_y[y][x];
	prev_z = map_info->proj_z[y][x];
	theta = map_info->keys.rot_y;
	if (theta != 0)
	{
		map_info->proj_x[y][x] = (prev_x * cos(theta)) + (prev_z * sin(theta));
		map_info->proj_y[y][x] = prev_y;
		map_info->proj_z[y][x] = (prev_y * sin(theta)) + (prev_z * cos(theta));
	}
}

void	rotate_z(t_map *map_info, int x, int y)
{
	double	prev_x;
	double	prev_y;
	double	prev_z;
	double	theta;

	prev_x = map_info->proj_x[y][x];
	prev_y = map_info->proj_y[y][x];
	prev_z = map_info->proj_z[y][x];
	theta = map_info->keys.rot_z;
	if (theta != 0)
	{
		map_info->proj_x[y][x] = (prev_x * cos(theta)) - (prev_y * sin(theta));
		map_info->proj_y[y][x] = (prev_x * cos(theta)) + (prev_y * sin(theta));
		map_info->proj_z[y][x] = prev_z;
	}
}

void	ft_isometric(t_map *map_info)
{
	int	x;
	int	y;

	x = 0;
	while (x < map_info->width)
	{
		y = 0;
		while (y < map_info->height)
		{
			rotate_x(map_info, x, y);
			rotate_y(map_info, x, y);
			rotate_z(map_info, x, y);
			y++;
		}
		x++;
	}
}
