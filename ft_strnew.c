/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:31:50 by jcoutare          #+#    #+#             */
/*   Updated: 2017/04/15 15:38:42 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while (size > 0)
		str[size--] = '\0';
	str[size] = '\0';
	return (str);
}
