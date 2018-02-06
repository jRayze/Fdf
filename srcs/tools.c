/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 14:10:27 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/28 04:20:38 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		define_x(t_map *map, int x, int y)
{
	return (map->zoom * (x - y) + (map->width / 2 + map->w_pic));
}

int		define_y(t_map *map, int x, int y)
{
	map->z = map->top * map->map[y][x];
	return ((map->zoom * ((x + y) - map->z)) + (map->height / 3 + map->h_pic));
}

void	px2img(int x, int y, int color, t_map *map)
{
	if (x > 0 && y > 0 && x < map->width && y < map->height)
		((int *)map->data)[x + y * map->width] = color;
}

void	init_map(t_map *map)
{
	map->x = 0;
	map->y = 0;
	map->z = 0;
	map->x_max = 0;
	map->y_max = 0;
	map->map = NULL;
}

void	ft_init_env(t_map *map)
{
	map->color = 0xFFFFFF;
	map->zoom = 4;
	map->top = 0.5f;
	map->h_pic = 0;
	map->w_pic = 0;
	map->width = 0;
	map->height = 0;
}
