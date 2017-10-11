/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_modif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 14:11:24 by jcoutare          #+#    #+#             */
/*   Updated: 2017/10/04 17:01:05 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	modif_l(t_struct *data)
{
	int i;
	int lol;

	i = -1;
	lol = check_char(data, 'l');
	data->modif = 1;
	if (check_signe(data) == 1)
	{
		if (lol == 2)
			data->arg = va_arg(*data->ap, unsigned long long int);
		else
			data->arg = va_arg(*data->ap, unsigned long int);
	}
	else
	{
		if (lol == 2)
			data->arg = va_arg(*data->ap, long long int);
		else
			data->arg = va_arg(*data->ap, long int);
	}
}

void	modif_h(t_struct *data)
{
	int lol;

	lol = check_char(data, 'h');
	data->modif = 1;
	if (check_signe(data) == 1)
	{
		if (lol == 2)
			data->arg = (unsigned char)va_arg(*data->ap, unsigned long long);
		else if (data->flags[ft_strlen(data->flags) - 1] != 'U')
			data->arg = (unsigned short int)va_arg(*data->ap,
														unsigned long int);
		else
			data->arg = va_arg(*data->ap, unsigned long int);
	}
	else
	{
		if (lol == 2)
			data->arg = (signed char)va_arg(*data->ap, long long);
		else
			data->arg = (short int)va_arg(*data->ap, long long);
	}
}

void	modif_j(t_struct *data)
{
	data->modif = 1;
	if (data->flags[ft_strlen(data->flags - 1)] == 'o' ||
		data->flags[ft_strlen(data->flags - 1)] == 'u' ||
		data->flags[ft_strlen(data->flags - 1)] == 'x' ||
		data->flags[ft_strlen(data->flags - 1)] == 'X')
		data->arg = va_arg(*data->ap, unsigned long);
	else
		data->arg = va_arg(*data->ap, long);
}

void	modif_z(t_struct *data)
{
	data->modif = 1;
	if (data->flags[ft_strlen(data->flags - 1)] == 'o' ||
		data->flags[ft_strlen(data->flags - 1)] == 'u' ||
		data->flags[ft_strlen(data->flags - 1)] == 'x' ||
		data->flags[ft_strlen(data->flags - 1)] == 'X')
		data->arg = va_arg(*data->ap, size_t);
	else
		data->arg = va_arg(*data->ap, ssize_t);
}
