/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:23:49 by jcoutare          #+#    #+#             */
/*   Updated: 2017/04/26 15:42:08 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c && s[i] != '\0')
			return ((char *)s + i);
		i++;
	}
	if (s[i] == '\0' && s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}
