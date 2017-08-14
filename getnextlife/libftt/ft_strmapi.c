/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 19:24:19 by jcoutare          #+#    #+#             */
/*   Updated: 2017/04/26 15:32:56 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		str[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	return (str);
}
