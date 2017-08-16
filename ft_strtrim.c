/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:06:13 by jcoutare          #+#    #+#             */
/*   Updated: 2017/04/26 15:57:19 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*str;
	size_t		i;
	size_t		j;
	size_t		k;

	k = 0;
	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (s[i] != '\0')
		j = (ft_strlen(s) - 1);
	while ((s[i]) && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && (j > i))
		j--;
	if ((str = malloc(sizeof(char) * (j - i + 1))) == NULL)
		return (NULL);
	while (i <= j)
	{
		str[k++] = s[i];
		i++;
	}
	str[k] = '\0';
	return (str);
}
