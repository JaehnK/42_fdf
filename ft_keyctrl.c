/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyctrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:53:16 by jaehukim          #+#    #+#             */
/*   Updated: 2024/05/24 18:53:18 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	ft_paint_black(t_map *map_info, t_param *param)
{
	int	x;
	int	y;

	x = 1;
	while (x < 1920)
	{
		y = 1;
		while (y < 1080)
		{
			my_mlx_pixel_put(&(param->img), x, y, 0x000000);
			y++;
		}
		x++;
	}
}

void	ft_ctrl_keys(t_param *param, int rx, int ry, int rz)
{
	ft_paint_black(param->map, param);
	param->map->keys.rot_x += rx;
	param->map->keys.rot_y += ry;
	param->map->keys.rot_z += rz;
	if (param->map->keys.rot_x > 360)
		param->map->keys.rot_x -= 360;
	if (param->map->keys.rot_y > 360)
		param->map->keys.rot_y -= 360;
	if (param->map->keys.rot_z > 360)
		param->map->keys.rot_z -= 360;
	ft_draw_img(param, param->map, 1);
}

void	ft_zero_keys(t_param *param)
{
	ft_paint_black(param->map, param);
	param->map->keys.rot_x = 0;
	param->map->keys.rot_y = 0;
	param->map->keys.rot_z = 0;
	ft_draw_img(param, param->map, 1);
}

void	ft_double2d_free(double **arr)
{
	int	i;

	i = 0;
	if (arr && arr[i])
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}
