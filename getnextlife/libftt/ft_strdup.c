/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 17:48:39 by jcoutare          #+#    #+#             */
/*   Updated: 2017/04/26 15:31:39 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *s2;

	if ((s2 = malloc(sizeof(char) * (ft_strlen(src) + 1))) == 0)
		return (NULL);
	ft_strcpy(s2, src);
	return (s2);
}
