/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 04:19:16 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/30 12:02:44 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line(t_map *map, t_point a, t_point b)
{
	t_coord		c;

	c.dx = b.x - a.x;
	c.dy = b.y - a.y;
	c.steps = (abs(c.dx) > abs(c.dy) ? abs(c.dx) : abs(c.dy));
	c.x_inc = c.dx * (1.0 / c.steps);
	c.y_inc = c.dy * (1.0 / c.steps);
	c.x = a.x;
	c.y = a.y;
	c.i = 0;
	while (c.i <= c.steps)
	{
		px2img(c.x, c.y, map->color, map);
		c.y += c.y_inc;
		c.x += c.x_inc;
		c.i++;
	}
}

void	ft_destroy_img(t_map *map)
{
	mlx_destroy_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	map->data = mlx_get_data_addr(map->img, &map->bpp, &map->sl,
			&map->endian);
}

void	write_info(t_map *map)
{
	mlx_string_put(map->mlx, map->win, 5, 5, 0xFFFFFF, "Input Commands:");
	mlx_string_put(map->mlx, map->win, 10, 30, 0xFFFFFF, "* ZOOM UP    : +");
	mlx_string_put(map->mlx, map->win, 10, 55, 0xFFFFFF, "* ZOOM DOWN  : -");
	mlx_string_put(map->mlx, map->win, 10, 80, 0xFFFFFF, "* MOVE UP    : w");
	mlx_string_put(map->mlx, map->win, 10, 105, 0xFFFFFF, "* MOVE DOWN  : s");
	mlx_string_put(map->mlx, map->win, 10, 130, 0xFFFFFF, "* MOVE LEFT  : a");
	mlx_string_put(map->mlx, map->win, 10, 155, 0xFFFFFF, "* MOVE RIGHT : d");
	mlx_string_put(map->mlx, map->win, 10, 180, 0xFFFFFF, "* ALTITUDE + : q");
	mlx_string_put(map->mlx, map->win, 10, 205, 0xFFFFFF, "* ALTITUDE - : e");
	mlx_string_put(map->mlx, map->win, 10, 230, 0xFFFFFF, "* COLOR MOD  : spc");
}

void	fdf(t_map *map)
{
	int			i;
	int			j;

	i = 0;
	while (i < map->x_max)
	{
		j = 0;
		while (j < map->y_max)
		{
			if (i < map->x_max - 1)
				ft_draw_line(map,
						(t_point){define_x(map, i, j), define_y(map, i, j)},
						(t_point){define_x(map, i + 1, j),
						define_y(map, i + 1, j)});
			if (j < map->y_max - 1)
				ft_draw_line(map,
						(t_point){define_x(map, i, j), define_y(map, i, j)},
						(t_point){define_x(map, i, j + 1),
						define_y(map, i, j + 1)});
			j++;
		}
		i++;
	}
}

int		ft_new(t_map *map)
{
	fdf(map);
	mlx_hook(map->win, 17, 0, close_hook, map);
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
	ft_destroy_img(map);
	if (map->width >= 200 && map->height >= 200)
		write_info(map);
	return (0);
}
