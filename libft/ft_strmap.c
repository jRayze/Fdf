/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:46:55 by jamerlin          #+#    #+#             */
/*   Updated: 2016/11/17 14:20:35 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	char			*buff;
	unsigned int	i;

	i = 0;
	buff = NULL;
	if (s)
	{
		buff = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!(buff))
			return (NULL);
		while (*s)
		{
			buff[i] = (f)(*s);
			s++;
			i++;
		}
		buff[i] = '\0';
	}
	return (buff);
}
