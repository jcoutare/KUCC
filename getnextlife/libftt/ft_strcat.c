/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:07:42 by jcoutare          #+#    #+#             */
/*   Updated: 2017/04/26 15:30:54 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
		j++;
	k = i + j;
	dest[k] = '\0';
	j = 0;
	while (i < k)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	return (dest);
}
