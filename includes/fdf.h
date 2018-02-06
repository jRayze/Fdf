/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 14:10:33 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/30 12:04:33 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <limits.h>
# include <errno.h>

typedef struct		s_coord
{
	int				xa;
	int				ya;
	int				xb;
	int				yb;
	int				dx;
	int				dy;
	double			x;
	double			y;
	int				steps;
	double			x_inc;
	double			y_inc;
	int				i;
	int				xx;
	int				yy;
	int				zz;
	int				mid_x;
}					t_coord;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_map
{
	int				x;
	int				y;
	int				z;

	int				h_pic;
	int				w_pic;

	void			*mlx;
	void			*win;
	void			*img;

	int				endian;
	int				bpp;
	int				sl;

	int				zoom;

	int				height;
	int				width;

	char			*data;
	char			*sign;

	int				win_x;
	int				win_y;

	int				**map;
	int				x_max;
	int				y_max;

	int				x1;
	int				x2;
	int				y1;
	int				y2;

	int				dx;
	int				dy;

	int				color;
	float			top;

	int				xinc;
	int				yinc;
}					t_map;

void				ft_init_env(t_map *map);
int					main(int argc, char **argv);
void				init_map(t_map *map);
t_map				*check_the_map(int fd);
void				ft_free_str_double_tab(char **tab);
void				ft_destroy_img(t_map *map);
void				write_data_pixel(t_map *map);
void				draw_line_y(t_map *map);
void				draw_line_x(t_map *map);
int					ft_new(t_map *map);
int					define_y(t_map *map, int x, int y);
int					define_x(t_map *map, int x, int y);
int					print_error(char *str, int ret);
void				ft_errno(char *argv);
t_map				*create_map(t_map *map);
t_map				*stock_map(char **argv, t_map *map);
void				px2img(int x, int y, int color, t_map *map);
int					is_inhexa(char c);
int					close_hook(int button, t_map *map);

#endif
