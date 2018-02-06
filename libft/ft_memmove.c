/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:11:23 by jamerlin          #+#    #+#             */
/*   Updated: 2016/11/18 13:19:07 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *str_dst;
	unsigned char *str_src;

	str_dst = (unsigned char *)dst;
	str_src = (unsigned char *)src;
	if (dst > src)
	{
		str_dst = str_dst + len;
		str_src = str_src + len;
		while (len--)
			*--str_dst = *--str_src;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
