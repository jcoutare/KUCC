/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_conv_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:10:58 by jcoutare          #+#    #+#             */
/*   Updated: 2017/10/09 13:55:42 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_s(t_struct *data)
{
	if (data->modif != 1)
		data->sarg = va_arg(*data->ap, char *);
	if (data->sarg == 0)
		data->sarg = "(null)";
	if (data->prec > 0)
		prec_s(data);
	else if (data->sarg != NULL && data->precfail != 1)
		data->resolved = ft_strjoin(data->resolved, data->sarg);
	le_cafe(data);
	data->modif = 0;
}

void	flag_c_moins(t_struct *data)
{
	ft_putstr(data->fstring);
	ft_putchar(0);
	le_cafe(data);
	ft_putstr(data->resolved);
	data->c_kc += ft_strlen(data->resolved)
		+ ft_strlen(data->fstring) + 1;
	ft_memset(data->resolved, '\0', ft_strlen(data->resolved));
	ft_memset(data->fstring, '\0', ft_strlen(data->fstring));
}

void	flag_c_else(t_struct *data)
{
	le_cafe(data);
	ft_putstr(data->fstring);
	ft_putstr(data->resolved);
	data->c_kc += ft_strlen(data->resolved) + ft_strlen(data->fstring) + 1;
	ft_memset(data->resolved, '\0', ft_strlen(data->resolved));
	ft_memset(data->fstring, '\0', ft_strlen(data->fstring));
	ft_putchar(0);
}

void	flag_c(t_struct *data)
{
	data->resolved[0] = '\0';
	if (data->modif != 1)
		data->arg = (unsigned char)va_arg(*data->ap, int);
	if (data->arg == 0)
	{
		data->larg--;
		if (data->f_moins && data->larg)
			flag_c_moins(data);
		else
			flag_c_else(data);
	}
	else
	{
		data->resolved[0] = data->arg;
		data->resolved[1] = 0;
		le_cafe(data);
	}
	data->modif = 0;
}
