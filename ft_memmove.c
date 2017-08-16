/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 13:54:28 by jcoutare          #+#    #+#             */
/*   Updated: 2017/04/13 14:16:07 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (dest > src && (int)n - 1 >= 0)
	{
		((char *)(dest))[n - 1] = ((const char *)(src))[n - 1];
		n--;
	}
	while (dest < src && i < n)
	{
		((char *)(dest))[i] = ((const char *)(src))[i];
		i++;
	}
	return (dest);
}
