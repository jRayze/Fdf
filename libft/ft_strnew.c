/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 13:58:09 by jamerlin          #+#    #+#             */
/*   Updated: 2016/11/17 13:56:49 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *buff;

	buff = (char *)malloc(sizeof(char) * (size + 1));
	if (!(buff))
		return (NULL);
	ft_memset((void *)buff, '\0', size);
	buff[size] = '\0';
	return (buff);
}
