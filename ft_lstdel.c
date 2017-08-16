/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:57:35 by jcoutare          #+#    #+#             */
/*   Updated: 2017/04/20 19:15:08 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *tofree;

	if (alst == NULL)
		return ;
	tmp = *alst;
	while (tmp)
	{
		(*del)(tmp->content, tmp->content_size);
		tofree = tmp;
		tmp = tmp->next;
		free(tofree);
	}
	*alst = NULL;
}
