/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:40:18 by jcoutare          #+#    #+#             */
/*   Updated: 2017/04/26 15:40:30 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	char		*string;
	size_t		i;
	size_t		j;

	string = ((char *)(str));
	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return (string);
	while (string[i])
	{
		j = 0;
		while (string[i + j] == to_find[j])
		{
			j++;
			if (to_find[j] == '\0')
				return (string + i);
		}
		i++;
	}
	return (0);
}
