/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 14:10:16 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/28 08:22:09 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		check_hexa(char *str, int k)
{
	int		l;

	l = -1;
	if (!(str[k]))
		return (0);
	else if (str[k] && str[k] != ',')
		return (-1);
	k++;
	if (str[k] && str[k + 1] && (str[k] != '0' || str[k + 1] != 'x'))
		return (-1);
	k++;
	k++;
	while (++l < 8 && ((str[k + l] != ' ' && str[k + l])
			|| l == 0))
		if (!is_inhexa(str[k + l]))
			return (-1);
	k += l;
	if (l == 8 && str[k] != ' ' && str[k])
		return (-1);
	return (k);
}

int		check_split(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			j = (split[i][j] == '-') ? j + 1 : j;
			if (split[i][j] >= 48 && split[i][j] <= 57)
				j++;
			else if (split[i][j] == ',')
			{
				if ((j = check_hexa(split[i], j)) == -1)
					return (print_error("hexa error\n", -1));
			}
			else
				return (-1);
		}
		i++;
	}
	return (i);
}

int		check_map(char *line)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_strsplit(line, ' ');
	i = check_split(split);
	ft_free_str_double_tab(split);
	return (i);
}

int		res_check_line(t_map *map, int j, char *line)
{
	if ((j = check_map(line)) > 0)
	{
		if (map->x_max == 0)
			map->x_max = j;
		else if (map->x_max != 0 && map->x_max != j)
			return (1);
		return (0);
	}
	else
		return (1);
}

t_map	*check_the_map(int fd)
{
	t_map	*map;
	int		i;
	char	*line;
	char	*tmp;
	int		j;

	i = 0;
	j = 0;
	line = NULL;
	tmp = NULL;
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	init_map(map);
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strdup(line);
		if (res_check_line(map, j, line) == 1)
			return (NULL);
		ft_memdel((void**)&tmp);
		i++;
	}
	map->y_max = i;
	close(fd);
	return (map);
}
