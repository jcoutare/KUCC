/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:22:45 by jcoutare          #+#    #+#             */
/*   Updated: 2017/04/26 15:31:11 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}
