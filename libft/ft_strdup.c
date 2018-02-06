/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:41:15 by jamerlin          #+#    #+#             */
/*   Updated: 2016/11/17 14:17:48 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(char *s1)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = ft_strlen(s1);
	if ((dest = (char *)malloc(sizeof(char) * j + 1)) == NULL)
		return (NULL);
	while (i < j)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
