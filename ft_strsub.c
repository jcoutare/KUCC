/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 16:55:28 by jcoutare          #+#    #+#             */
/*   Updated: 2017/04/26 15:41:55 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char				*str;
	unsigned int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while ((size_t)i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
