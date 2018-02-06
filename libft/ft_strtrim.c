/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:48:46 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/30 11:31:18 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	int		i;
	int		j;
	int		k;
	char	*dst;

	if (!(s))
		return (NULL);
	i = 0;
	k = 0;
	j = ft_strlen(s) - 1;
	while ((s[k] == '\t') || (s[k] == '\n' || s[k] == ' '))
		k++;
	while ((s[j] == '\t') || ((s[j] == '\n' || s[j] == ' ') && s[k] != '\0'))
		j--;
	if (!(dst = (char *)malloc(sizeof(char) * (j - k + 2))))
		return (NULL);
	while (s[k] && k <= j)
	{
		dst[i] = s[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (dst);
}
