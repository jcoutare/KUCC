/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 14:11:33 by jcoutare          #+#    #+#             */
/*   Updated: 2017/04/13 15:02:17 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*cpy;
	unsigned char		*tocpy;

	i = 0;
	cpy = (unsigned char *)dest;
	tocpy = (unsigned char *)src;
	while (i < n)
	{
		cpy[i] = tocpy[i];
		if (tocpy[i] == (unsigned char)c)
			return ((char *)dest + (i + 1));
		i++;
	}
	return (NULL);
}
