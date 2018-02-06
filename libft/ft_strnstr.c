/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:00:38 by jamerlin          #+#    #+#             */
/*   Updated: 2016/11/17 13:54:19 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (*little == '\0')
		return ((char *)big);
	if (len > ft_strlen(big))
		len = ft_strlen(big);
	while (i < len)
	{
		while (big[i] != little[j] && big[i] && i < len)
			i++;
		while (big[i] == little[j] && (little[j] && i < len))
		{
			i++;
			j++;
		}
		if (j == ft_strlen(little))
			return ((char *)(big + i - j));
		i = i - j + 1;
		j = 0;
	}
	return (NULL);
}
