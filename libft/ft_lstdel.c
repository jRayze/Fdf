/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:48:39 by jamerlin          #+#    #+#             */
/*   Updated: 2016/11/18 12:37:29 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *maillon;
	t_list *first;

	if (!(alst || del))
		return ;
	maillon = *alst;
	while (maillon)
	{
		first = maillon->next;
		(del)(maillon->content, maillon->content_size);
		free(maillon);
		maillon = first;
	}
	*alst = NULL;
}
