/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 04:18:59 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/30 12:08:16 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			close_hook(int button, t_map *map)
{
	(void)button;
	(void)map;
	exit(0);
	return (0);
}

void		ft_free_str_double_tab(char **tab)
{
	int i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void		ft_init(t_map *map)
{
	map->width += (map->x_max * 100 < 1800) ? map->x_max * 100 : 1800;
	map->height += (map->y_max * 100 < 1100) ? map->x_max * 100 : 1100;
	map->sl = map->width * (map->bpp / 8);
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->width,
			map->height, "fdf - jamerlin");
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	map->data = mlx_get_data_addr(map->img, &map->bpp, &map->sl,
			&map->endian);
	map->color = 0xFF00FF;
	map->zoom = 5;
}

static int	key_func(int keycode, t_map *map)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 1)
		map->h_pic -= 50;
	else if (keycode == 13)
		map->h_pic += 50;
	else if (keycode == 0)
		map->w_pic += 50;
	else if (keycode == 2)
		map->w_pic -= 50;
	else if (keycode == 24)
		map->zoom += 1.5;
	else if (keycode == 27)
		map->zoom -= (map->zoom - 1.5) > 3 ? 1.5 : 0;
	else if (keycode == 12)
		map->top += 0.1;
	else if (keycode == 14)
		map->top -= 0.1;
	else if (keycode == 49)
		map->color += 150;
	return (1);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	fd = 0;
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (0);
	if (argc != 2)
		return (print_error("usage : fdf [map]\n", 1));
	ft_errno(argv[1]);
	if ((fd = open(argv[1], O_RDWR)) == -1)
	{
		close(fd);
		return (print_error("fdf : permission denied \n", 1));
	}
	else if ((map = check_the_map(fd)) == NULL)
		return (print_error("fdf : invalid map\n", 1));
	map = create_map(map);
	map = stock_map(argv, map);
	ft_init_env(map);
	ft_init(map);
	ft_new(map);
	mlx_loop_hook(map->mlx, ft_new, map);
	mlx_key_hook(map->win, key_func, map);
	mlx_loop(map->mlx);
	return (0);
}
