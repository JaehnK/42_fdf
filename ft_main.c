/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:01:19 by jaehukim          #+#    #+#             */
/*   Updated: 2024/05/12 22:19:14 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	ft_init_keys(t_map *map_info)
{
	map_info->keys.rot_x = 35.264;
	map_info->keys.rot_y = 45;
	map_info->keys.rot_z = 0;
}

static int	mlx_close(t_param *param)
{
	mlx_destroy_image(param->mlx, param->img.img);
	mlx_destroy_window(param->mlx, param->win);
	mlx_destroy_display(param->mlx);
	exit (0);
	return (0);
}

static int	mlx_key_handle(int keycode, t_param *param)
{
	if (keycode == 65307)
		mlx_close(param);
	else if (keycode == 65429)
		ft_ctrl_keys(param, 1, 0, 0);
	else if (keycode == 65431)
		ft_ctrl_keys(param, 0, 1, 0);
	else if (keycode == 65434)
		ft_ctrl_keys(param, 0, 0, 1);
	else if (keycode == 65437)
	{
		ft_paint_black(param->map, param);
		ft_init_keys(param->map);
		ft_draw_img(param, param->map, 1);
	}
	else if (keycode == 65430)
		ft_zero_keys(param);
	return (0);
}

static void	ft_mlx_init(t_param *param, t_map *map_info)
{
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, 1920, 1080, "Fil de Fer");
	param->img.img = mlx_new_image(param->mlx, 1920, 1080);
	param->img.addr = mlx_get_data_addr(param->img.img, \
	&(param->img.bits_per_pixel), \
	&(param->img.line_length), &(param->img.endian));
	ft_init_keys(map_info);
}

int	main(int argc, char **argv)
{
	t_param	param;
	t_map	*map_info;

	if (argc != 2)
		return (-1);
	map_info = (t_map *) malloc(sizeof(t_map));
	if (!map_info)
		return (-1);
	ft_check_map(argv[1], map_info);
	ft_parse_map(argv[1], map_info);
	param.map = map_info;
	ft_mlx_init(&param, param.map);
	ft_draw_img(&param, param.map, 0);
	mlx_hook(param.win, 17, 0, &mlx_close, &param);
	mlx_key_hook(param.win, &mlx_key_handle, &param);
	mlx_loop(param.mlx);
	exit(1);
	return (0);
}
