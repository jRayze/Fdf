/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:55:08 by jamerlin          #+#    #+#             */
/*   Updated: 2016/11/17 14:08:46 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*buff;
	unsigned long	i;

	i = 0;
	if (!(s1 && s2))
		return (NULL);
	buff = ft_strnew((size_t)ft_strlen(s1) + (size_t)ft_strlen(s2));
	if (!(buff))
		return (NULL);
	ft_strcpy(buff, s1);
	ft_strcat(buff, s2);
	return ((char *)buff);
}
