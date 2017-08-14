/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 09:38:50 by jcoutare          #+#    #+#             */
/*   Updated: 2017/04/26 17:31:21 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_list_size(t_list *begin_list)
{
	int i;

	i = 0;
	if (begin_list == NULL)
		return (i);
	while (begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}
