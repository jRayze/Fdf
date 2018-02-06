/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:23:31 by jamerlin          #+#    #+#             */
/*   Updated: 2016/11/17 14:40:59 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int l;

	i = 0;
	l = 0;
	if (*big == '\0' && *little == '\0')
		return ((char *)big);
	while (big[i])
	{
		i = l;
		j = 0;
		while (((char*)big)[i] != ((char *)little)[j] && (big[i] && little[j]))
			i++;
		l = i;
		while (((char *)big)[i] == ((char *)little)[j] && (little[j] && big[i]))
		{
			j++;
			i++;
		}
		if (j == (int)(ft_strlen(little)))
			return ((char *)(big + l));
		l++;
	}
	return (NULL);
}
