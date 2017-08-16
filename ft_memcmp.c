/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 14:52:05 by jcoutare          #+#    #+#             */
/*   Updated: 2017/04/15 15:15:42 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*str;
	unsigned char		*cmp;

	i = 0;
	str = (unsigned char *)s1;
	cmp = (unsigned char *)s2;
	while (i < n)
	{
		if (str[i] - cmp[i] != 0)
			return (str[i] - cmp[i]);
		i++;
	}
	return (0);
}
