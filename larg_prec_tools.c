/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   larg_prec_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 13:09:27 by jcoutare          #+#    #+#             */
/*   Updated: 2017/10/09 13:15:08 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*do_normal_prec(t_struct *data, char *str)
{
	str = ft_strnew(data->prec);
	ft_memset(str, '0', data->prec);
	str[data->prec + 1] = '\0';
	return (str);
}

char	*do_plus_prec(t_struct *data, char *str)
{
	str = ft_strnew(data->prec);
	str[data->prec + 1] = '\0';
	str[0] = '+';
	data->arg = (long long)data->arg * -1;
	ft_memset(str + 1, '0', data->prec);
	data->f_plus = 0;
	return (str);
}

char	*do_neg_prec(t_struct *data, char *str)
{
	str = ft_strnew(data->prec);
	str[data->prec + 1] = '\0';
	str[0] = '-';
	data->arg = (long long)data->arg * -1;
	ft_memset(str + 1, '0', data->prec);
	return (str);
}

char	*do_sharp_zero_prec(t_struct *data, char *str)
{
	if (!(str = ft_strnew(data->prec)))
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	str[data->prec + 1] = '\0';
	ft_memset(str + 2, '0', data->prec);
	data->f_sharp = 0;
	return (str);
}
