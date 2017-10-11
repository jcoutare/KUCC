/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_unicode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 13:57:26 by jcoutare          #+#    #+#             */
/*   Updated: 2017/10/09 14:07:20 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_bigc(t_struct *data)
{
	va_arg(*data->ap, wint_t);
}

void	flag_bigs(t_struct *data)
{
	va_arg(*data->ap, char *);
}
