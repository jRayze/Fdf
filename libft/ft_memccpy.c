/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:58:47 by jamerlin          #+#    #+#             */
/*   Updated: 2016/11/14 10:58:52 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t j;

	j = 0;
	while (j < n)
	{
		((unsigned char *)dst)[j] = ((unsigned char *)src)[j];
		if (((unsigned char *)src)[j] == (unsigned char)c)
			return (dst + j + 1);
		j++;
	}
	return (NULL);
}
