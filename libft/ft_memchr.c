/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:36:44 by jamerlin          #+#    #+#             */
/*   Updated: 2016/11/17 14:15:43 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t j;

	j = 0;
	while (j < n)
	{
		if (((unsigned char*)(s))[j] == (unsigned char)c)
			return ((void *)s + j);
		j++;
	}
	return (NULL);
}
