/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:32:42 by jaehukim          #+#    #+#             */
/*   Updated: 2024/05/25 16:25:22 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"


typedef	struct s_keyval
{
	double rot_x;
	double	rot_y;
	double rot_z;
}	t_keyval;

typedef struct s_map
{
	int			height;
	int			width;
	int			gap;
	int			top;
	int			bot;
	int			x_offset;
	int			y_offset;
	int			**altitude;
	int			**colour;
	double		**proj_x;
	double		**proj_y;
	double		**proj_z;
	t_keyval	keys;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_param
{
	void	*mlx;
	void	*win;
	t_data	img;
	t_map	*map;
}	t_param;

typedef	struct s_point
{
	int	x;
	int	y;
	int	z;
	int colour;
}	t_point;


size_t 	ft_check_map(char *file, t_map *map_info);
void	ft_parse_map(char * file, t_map *map_info);
void    ft_draw_line(t_map *map, t_data *img);
void	ft_draw_img(t_param *param, t_map *map_info, int re);
void	my_mlx_pixel_put(t_data *img, int x, int y, int colour);
void    ft_isometric(t_map *map_info);
t_point	**ft_gen_fourpts(int x, int y, t_map *map);
void	free_points(t_point **pts);
void	ft_init_colour(t_map *map_info);
int		ft_compute_colour(t_point *pt1, t_point *pt2, int x, int y);
void	ft_free_int_arr(int	**arr);
void	ft_free_dbl_arr(double **arr);
void	ft_paint_black(t_map *map_info, t_param *param);
void	ft_ctrl_keys(t_param *param, int rx, int ry, int rz);
void	ft_double2d_free(double **arr);
void	ft_calcul_offset(t_map *map);
void	ft_zero_keys(t_param *param);
#endif
