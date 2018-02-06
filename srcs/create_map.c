/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 04:18:38 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/28 08:35:58 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*stock_tab_int(char **str, int *map)
{
	int	j;

	j = -1;
	while (str[++j])
		map[j] = ft_atoi(str[j]);
	return (map);
}

int		is_inhexa(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' &&
				c <= 'F') || (c >= 'a' && c <= 'f'))
		return (1);
	return (0);
}

t_map	*stock_map(char **argv, t_map *map)
{
	char	*line;
	char	**split;
	int		i;
	int		fd;
	int		j;

	i = 0;
	j = 0;
	line = NULL;
	split = NULL;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		stock_tab_int(split, map->map[i]);
		ft_free_str_double_tab(split);
		free(line);
		i++;
	}
	free(line);
	map->map[i] = NULL;
	close(fd);
	return (map);
}

t_map	*create_map(t_map *map)
{
	int	i;
	int	*line;

	i = 0;
	if (!(map->map = (int **)malloc(sizeof(int *) * (map->y_max + 1))))
		return (NULL);
	if (!(line = (int *)malloc(sizeof(int) * (map->y_max * map->x_max))))
		return (NULL);
	while (i < map->y_max)
	{
		map->map[i] = &line[i * map->x_max];
		i++;
	}
	map->map[i] = NULL;
	return (map);
}
