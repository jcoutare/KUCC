/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 10:20:56 by jcoutare          #+#    #+#             */
/*   Updated: 2017/10/09 13:22:52 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_sharp(t_struct *data)
{
	if (data->flags[ft_strlen(data->flags - 1)] != 'o' &&
		data->flags[ft_strlen(data->flags - 1)] != 'x')
		return ;
	if (data->flags[ft_strlen(data->flags - 1)] == 'o')
		if (!(data->resolved = ft_strjoin(data->resolved, "o")))
			return ;
	if (data->flags[ft_strlen(data->flags - 1)] == 'x'
		|| data->flags[ft_strlen(data->flags - 1)] == 'X')
		if (!(data->resolved = ft_strjoin(data->resolved, "0X")))
			return ;
}

void	make_moins(t_struct *data)
{
	char *str;

	data->larg = data->larg - (int)ft_strlen(data->resolved);
	if (data->larg > 0)
	{
		str = ft_strnew(data->larg);
		ft_memset(str, ' ', data->larg);
		data->resolved = ft_strjoin(data->resolved, str);
		free(str);
	}
	data->larg = 0;
}

void	make_o_sharp(t_struct *data)
{
	if (data->f_sharp == 1)
	{
		data->resolved = ft_strjoin(data->resolved, "0");
		if (data->arg != 0)
			data->prec--;
	}
}
