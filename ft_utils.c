/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 23:45:59 by jaehukim          #+#    #+#             */
/*   Updated: 2024/05/25 23:46:00 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	ft_calcul_offset(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	map->x_offset = 1;
	map->y_offset = 1;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			if (map->x_offset >= (int) map->proj_x[y][x] - 1)
				map->x_offset = (int) map->proj_x[y][x] - 1;
			if (map->y_offset >= (int) map->proj_y[y][x] - 1)
				map->y_offset = (int) map->proj_y[y][x] - 1;
			y++;
		}
		x++;
	}
	map->x_offset *= -1;
	map->y_offset *= -1;
	return ;
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int colour)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
	return ;
}

void	ft_zoom(int keycode, t_param *param)
{
	ft_paint_black(param->map, param);
	if (keycode == 61)
		param->map->gap *= 1.2;
	else if (keycode == 45)
		param->map->gap *= 0.8;
	else if (keycode == 48)
		ft_calcul_gap(param->map);
	ft_draw_img(param, param->map, 1);
}
