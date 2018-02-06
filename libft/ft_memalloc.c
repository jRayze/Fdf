/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 13:44:06 by jamerlin          #+#    #+#             */
/*   Updated: 2016/11/17 14:13:52 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *buff;

	buff = (void *)malloc(sizeof(size_t) * (size));
	if (!(buff))
		return (NULL);
	ft_bzero(buff, size);
	return (buff);
}
