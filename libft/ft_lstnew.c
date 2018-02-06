/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:20:39 by jamerlin          #+#    #+#             */
/*   Updated: 2016/11/18 11:57:26 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *maillon_faible;

	if (!(maillon_faible = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(maillon_faible))
		return (NULL);
	if (!(content))
	{
		maillon_faible->content = NULL;
		maillon_faible->content_size = 0;
	}
	else
	{
		maillon_faible->content = ft_memalloc(content_size);
		ft_memcpy(maillon_faible->content, content, content_size);
		maillon_faible->content_size = content_size;
	}
	maillon_faible->next = NULL;
	return (maillon_faible);
}
