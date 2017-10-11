/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 15:15:33 by jcoutare          #+#    #+#             */
/*   Updated: 2017/10/09 13:08:00 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_data(t_struct *data)
{
	data->f_plus = 0;
	data->f_space = 0;
	data->f_zero = 0;
	data->f_moins = 0;
	data->f_sharp = 0;
	data->precfail = 0;
	data->modif = 0;
}

void	la_resolvance(t_struct *data)
{
	int i;
	int c;

	i = 0;
	while (data->flags[i])
	{
		if (data->flags[i] <= '9' && data->flags[i] >= '1')
		{
			i += flag_larg(data, data->flags + i);
		}
		if (data->flags[i] == '.')
		{
			i += flag_prec(data, (data->flags + i + 1));
		}
		if (data->flags[i] == 'h' && data->flags[i + 1] == 'h')
			i++;
		if (data->flags[i] == 'l' && data->flags[i + 1] == 'l')
			i++;
		c = data->flags[i];
		if (data->flag_tab[c] != 0)
			data->flag_tab[c](data);
		i++;
	}
	reset_data(data);
	data->modif = 0;
}

char	*get_flags(char *str, t_struct *data)
{
	int validflags;

	data->flags = ft_strsub(str, 1,
							strichr_str(str + 1, "%spdDioOuUxXc") + 1);
	if ((validflags = strcheck(data->flags, "%-+ #hljzspdDioOuUxXc.") != -1))
	{
		if (data->flags)
			free(data->flags);
		return (str + validflags + 1);
	}
	if (str[0] == '%' && str[1] == '%')
	{
		flag_pourcent(data);
		str += 2;
	}
	else
	{
		la_resolvance(data);
		str += strichr_str(str + 1, "%spdDioOuUxXc") + 2;
	}
	free(data->flags);
	return (str);
}

void	decoupe(char *str, t_struct *data)
{
	int	i;

	i = 0;
	while (strichr(str, '%') != -1)
	{
		data->fstring = ft_strnjoin(data->fstring, str, strichr(str, '%'));
		str = get_flags(str + strichr(str, '%'), data);
		data->fstring = ft_strjoin(data->fstring, data->resolved);
		ft_memset(data->resolved, '\0', ft_strlen(data->resolved));
		i++;
	}
	data->fstring = ft_strjoin(data->fstring, str);
}

int		ft_printf(char *str, ...)
{
	va_list		ap;
	char		*copy;
	t_struct	*data;
	int			ret;

	if (str == NULL)
		return (-1);
	data = NULL;
	copy = ft_strdup(str);
	va_start(ap, str);
	data = fill_struct(data, &ap);
	decoupe(copy, data);
	ft_putstr(data->fstring);
	va_end(ap);
	if (data->fail == 1)
		ret = -1;
	else
		ret = (int)ft_strlen(data->fstring) + (int)data->c_kc;
	free(copy);
	free(data->fstring);
	free(data->resolved);
	free(data);
	return (ret);
}
