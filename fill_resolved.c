/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_resolved.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 14:56:49 by jcoutare          #+#    #+#             */
/*   Updated: 2017/10/09 13:52:34 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	le_the(t_struct *data)
{
	if ((data->f_plus == 1 || data->f_space == 1) && data->f_zero != 1)
	{
		if (data->f_plus == 1)
		{
			if ((long long)data->arg >= 0)
				data->resolved[0] = '+';
			data->f_plus = 0;
		}
		else if (data->f_space == 1)
		{
			if ((long long)data->arg >= 0)
				data->resolved[0] = ' ';
			data->f_space = 0;
		}
	}
}

void	le_cafe(t_struct *data)
{
	if (data->f_moins == 1 || data->f_zero == 1)
	{
		if (data->f_moins == 1)
			make_moins(data);
		else if (data->f_zero == 1)
			make_zero(data);
	}
	else if (data->larg > 0)
		larg(data);
}
