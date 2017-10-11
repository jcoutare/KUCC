/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:55:28 by jcoutare          #+#    #+#             */
/*   Updated: 2017/09/29 15:24:02 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_signe(t_struct *data)
{
	if (data->flags[ft_strlen(data->flags) - 1] == 'o' ||
		data->flags[ft_strlen(data->flags) - 1] == 'u' ||
		data->flags[ft_strlen(data->flags) - 1] == 'x' ||
		data->flags[ft_strlen(data->flags) - 1] == 'X' ||
		data->flags[ft_strlen(data->flags) - 1] == 'U' ||
		data->flags[ft_strlen(data->flags) - 1] == 'O')
		return (1);
	return (0);
}

int		check_char(t_struct *data, char c)
{
	int i;
	int lol;

	lol = 0;
	i = 0;
	while (data->flags[i])
	{
		if (data->flags[i] == c)
			lol++;
		i++;
	}
	return (lol);
}
