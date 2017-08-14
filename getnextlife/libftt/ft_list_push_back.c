/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:07:33 by jcoutare          #+#    #+#             */
/*   Updated: 2017/04/26 17:29:12 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list, void *content,
						size_t content_size)
{
	t_list	*list;

	if (*begin_list == NULL)
		*begin_list = ft_lstnew(content, content_size);
	else
	{
		list = *begin_list;
		while (list->next)
			list = list->next;
		list->next = ft_lstnew(content, content_size);
	}
}
