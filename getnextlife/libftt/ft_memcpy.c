/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 14:02:54 by jcoutare          #+#    #+#             */
/*   Updated: 2017/04/13 14:38:38 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*cpy;
	char		*tocpy;

	i = 0;
	cpy = (char *)dest;
	tocpy = (char *)src;
	while (i < n)
	{
		cpy[i] = tocpy[i];
		i++;
	}
	return (dest);
}
