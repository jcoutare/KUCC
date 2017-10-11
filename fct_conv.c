/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:40:34 by jcoutare          #+#    #+#             */
/*   Updated: 2017/10/09 13:18:39 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_hex_unsigned(t_struct *data)
{
	char		*arg;
	int			i;

	i = 0;
	data->conv = 1;
	if (data->modif != 1)
		data->arg = va_arg(*data->ap, unsigned int);
	if (data->f_sharp == 1 && data->arg != 0 &&
		(data->f_zero == 0 || data->f_moins == 1))
		data->resolved = ft_strjoin(data->resolved, "0X");
	if (data->prec > 0)
		prec_hexa(data, 16);
	arg = ft_itoa_base(data->arg, 16);
	if (data->precfail != 1 || data->arg != 0)
		data->resolved = ft_strjoin(data->resolved, arg);
	free(arg);
	le_cafe(data);
	while (data->resolved[i])
	{
		data->resolved[i] = ft_tolower(data->resolved[i]);
		i++;
	}
}

void	flag_hex_unsigned_maj(t_struct *data)
{
	char		*arg;
	int			i;

	i = 0;
	data->conv = 1;
	if (data->modif != 1)
		data->arg = va_arg(*data->ap, unsigned int);
	if (data->f_sharp == 1 && data->arg != 0 &&
		(data->f_zero == 0 || data->f_moins == 1))
		data->resolved = ft_strjoin(data->resolved, "0X");
	if (data->prec > 0)
		prec_hexa(data, 16);
	arg = ft_itoa_base(data->arg, 16);
	if (data->precfail != 1 || data->arg != 0)
		data->resolved = ft_strjoin(data->resolved, arg);
	free(arg);
	le_cafe(data);
	while (data->resolved[i])
	{
		data->resolved[i] = ft_toupper(data->resolved[i]);
		i++;
	}
}

void	flag_p(t_struct *data)
{
	char		*arg;
	int			i;

	i = 0;
	data->conv = 1;
	if (data->modif != 1)
		data->arg = (unsigned long)va_arg(*data->ap, void *);
	data->resolved = ft_strjoin(data->resolved, "0x");
	if (data->prec > 0)
		prec_hexa(data, 16);
	arg = ft_itoa_base(data->arg, 16);
	if (data->precfail != 1 || data->arg != 0)
		data->resolved = ft_strjoin(data->resolved, arg);
	free(arg);
	le_cafe(data);
	while (data->resolved[i])
	{
		data->resolved[i] = ft_tolower(data->resolved[i]);
		i++;
	}
}

void	flag_pourcent(t_struct *data)
{
	data->resolved = ft_strjoin(data->resolved, "%");
	le_cafe(data);
}
