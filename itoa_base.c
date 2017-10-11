/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 14:25:04 by jcoutare          #+#    #+#             */
/*   Updated: 2017/10/02 16:13:39 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(unsigned long long nbr, unsigned int base)
{
	static char			tab[16] = "0123456789ABCDEF";
	char				*str;
	int					len;
	unsigned long long	nb;

	nb = nbr;
	len = 1;
	while (nb >= base)
	{
		nb = nb / base;
		len++;
	}
	if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	str[len--] = 0;
	while (nbr >= base)
	{
		str[len--] = tab[nbr % base];
		nbr = nbr / base;
	}
	str[len] = tab[nbr % base];
	return (str);
}
