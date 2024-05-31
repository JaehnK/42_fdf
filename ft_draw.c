/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:41:04 by jaehukim          #+#    #+#             */
/*   Updated: 2024/05/23 11:07:41 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	ft_calcul_gap(t_map *map_info)
{
	int	gap;
	int	wmax_height;
	int	wmax_width;

	gap = 40;
	wmax_height = 1920;
	wmax_width = 1080;
	while (1)
	{
		if ((map_info->height * gap < wmax_height) && \
		(map_info->width * gap < wmax_width))
		{	
			map_info->gap = gap;
			return ;
		}
		else
			gap--;
	}
	map_info->gap = gap;
	return ;
}

void	ft_init_proj_x(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map->proj_x = (double **) malloc(sizeof(double *) * (map->height + 1));
	while (y < map->height)
	{
		map->proj_x[y] = (double *) malloc(sizeof(double) * (map->width + 1));
		x = 0;
		while (x < map->width)
		{
			map->proj_x[y][x] = x * map->gap * 1.2;
			x++;
		}
		y++;
	}
	map->proj_x[y] = NULL;
}

void	ft_init_proj_y(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map->proj_y = (double **) malloc(sizeof(double *) * (map->height + 1));
	while (y < map->height)
	{
		map->proj_y[y] = (double *) malloc(sizeof(double) * (map->width + 1));
		x = 0;
		while (x < map->width)
		{
			map->proj_y[y][x] = y * map->gap * 0.8;
			x++;
		}
		y++;
	}
	map->proj_y[y] = NULL;
}

void	ft_init_proj_z(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map->proj_z = (double **) malloc(sizeof(double *) * (map->height + 1));
	while (y < map->height)
	{
		map->proj_z[y] = (double *) malloc(sizeof(double) * (map->width + 1));
		x = 0;
		while (x < map->width)
		{
			map->proj_z[y][x] = map->altitude[y][x] * map->gap * .125;
			x++;
		}
		y++;
	}
	map->proj_z[y] = NULL;
}

void	ft_draw_img(t_param *param, t_map *map_info, int re)
{
	if (re == 1)
	{
		ft_double2d_free(map_info->proj_x);
		ft_double2d_free(map_info->proj_y);
		ft_double2d_free(map_info->proj_z);
	}
	if (re == 0)
		ft_calcul_gap(map_info);
	ft_init_proj_x(map_info);
	ft_init_proj_y(map_info);
	ft_init_proj_z(map_info);
	ft_isometric(map_info);
	ft_calcul_offset(map_info);
	ft_init_colour(map_info);
	ft_draw_line(map_info, &(param->img));
	mlx_put_image_to_window(param->mlx, param->win, param->img.img, 0, 0);
}
