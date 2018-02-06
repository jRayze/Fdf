/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:11:25 by jamerlin          #+#    #+#             */
/*   Updated: 2016/11/17 14:21:12 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	unsigned int	j;
	char			*buff;

	i = 0;
	j = 0;
	buff = NULL;
	if (s)
	{
		buff = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
		if (!(buff))
			return (NULL);
		while (*s)
		{
			buff[j] = (f)(i, *s);
			j++;
			i++;
			s++;
		}
		buff[j] = '\0';
	}
	return (buff);
}
