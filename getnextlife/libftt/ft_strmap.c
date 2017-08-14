/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 19:01:14 by jcoutare          #+#    #+#             */
/*   Updated: 2017/04/26 15:43:31 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t		size;
	char		*str;
	size_t		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	str[size] = '\0';
	while (i < size)
	{
		str[i] = (*f)(s[i]);
		i++;
	}
	return (str);
}
