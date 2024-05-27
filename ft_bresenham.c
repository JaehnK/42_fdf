/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:32:55 by jaehukim          #+#    #+#             */
/*   Updated: 2024/05/23 11:05:21 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	ft_stepper(t_point *pt1, t_point *pt2, int is_low)
{
	int	step;

	if (is_low == 1)
	{
		if (pt2->y - pt1->y >= 0)
			step = 1;
		else
			step = -1;
	}
	else
	{
		if (pt2->x - pt1->x >= 0)
			step = 1;
		else
			step = -1;
	}
	return (step);
}

void	ft_draw_line_low(t_point *pt1, t_point *pt2, t_data *img)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	seed;

	dx = (int)(pt2->x - pt1->x);
	dy = (int)(pt2->y - pt1->y);
	dy = abs(dy);
	x = (int) pt1->x;
	y = (int) pt1->y;
	seed = 2 * dy - dx;
	while (x <= (int)pt2->x)
	{
		if (x > 0 && y > 0 && x < 1920 && y < 1080)
			my_mlx_pixel_put(img, x, y, ft_compute_colour(pt1, pt2, x, y));
		if (seed > 0)
		{
			y += ft_stepper(pt1, pt2, 1);
			seed -= 2 * dx;
		}
		seed += 2 * dy;
		x++;
	}
}

void	ft_draw_line_high(t_point *pt1, t_point *pt2, t_data *img)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	seed;

	dx = (int)(pt2->x - pt1->x);
	dy = (int)(pt2->y - pt1->y);
	dx = abs(dx);
	y = (int) pt1->y;
	x = (int) pt1->x;
	seed = 2 * dx - dy;
	while (y <= (int)pt2->y)
	{
		if (x > 0 && y > 0 && x < 1920 && y < 1080)
			my_mlx_pixel_put(img, x, y, ft_compute_colour(pt1, pt2, x, y));
		if (seed > 0)
		{
			x += ft_stepper(pt1, pt2, 0);
			seed -= 2 * dy;
		}
		seed += 2 * dx;
		y++;
	}
}

void	ft_bresenham(t_point *pt1, t_point *pt2, t_data *img)
{
	int	dx;
	int	dy;

	dx = (int) abs(pt1->x - pt2->x);
	dy = (int) abs(pt1->y - pt2->y);
	if (dx > dy)
	{
		if (pt1->x > pt2->x)
			ft_draw_line_low(pt2, pt1, img);
		else
			ft_draw_line_low(pt1, pt2, img);
	}
	else
	{
		if (pt1->y > pt2->y)
			ft_draw_line_high(pt2, pt1, img);
		else
			ft_draw_line_high(pt1, pt2, img);
	}
}

void	ft_draw_line(t_map *map, t_data *img)
{
	int			x;
	int			y;
	t_point		**points;

	y = 0;
	while (y < map->height - 1)
	{
		x = 0;
		while (x < map->width - 1)
		{
			points = ft_gen_fourpts(x, y, map);
			ft_bresenham(points[0], points[1], img);
			ft_bresenham(points[0], points[2], img);
			ft_bresenham(points[1], points[3], img);
			ft_bresenham(points[2], points[3], img);
			free_points(points);
			x++;
		}
		y++;
	}
}
