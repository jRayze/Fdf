/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 14:09:59 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/30 11:05:39 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_errno(char *argv)
{
	char	*str;
	int		i;

	if ((i = open(argv, O_RDONLY)) == -1)
	{
		if (errno != EACCES)
		{
			str = ft_strdup("fdf: ");
			write(2, str, ft_strlen(str));
			write(2, argv, ft_strlen(argv));
			ft_putstr(": ");
			write(2, strerror(errno), ft_strlen(strerror(errno)));
			ft_putchar('\n');
			ft_strdel(&str);
			close(i);
			exit(EXIT_SUCCESS);
		}
	}
}

int		print_error(char *str, int ret)
{
	ft_putstr_fd(str, 2);
	return (ret);
}
