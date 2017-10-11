/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 15:44:30 by jcoutare          #+#    #+#             */
/*   Updated: 2017/10/09 14:07:01 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct		*fill_struct(t_struct *data, va_list *ap)
{
	if (!(data = malloc(sizeof(t_struct))))
		return (NULL);
	data->arg = 0;
	data->sarg = 0;
	data->ap = ap;
	if (!(data->fstring = malloc(sizeof(char *))))
		return (NULL);
	data->fstring[0] = 0;
	data->f_sharp = 0;
	data->f_zero = 0;
	data->f_plus = 0;
	data->f_moins = 0;
	data->f_space = 0;
	if (!(data->resolved = malloc(sizeof(char *))))
		return (NULL);
	data->resolved[0] = 0;
	data->flags = NULL;
	data->conv = 0;
	data->larg = 0;
	data->precfail = 0;
	data->fail = 0;
	data->c_kc = 0;
	data->flag_tab['C'] = &flag_bigc;
	fill_struct2(data);
	return (data);
}

void			fill_struct2(t_struct *data)
{
	data->prec = -1;
	data->modif = 0;
	data->flag_tab['S'] = &flag_bigs;
	data->flag_tab['%'] = &flag_pourcent;
	data->flag_tab['0'] = &flag_zero;
	data->flag_tab['d'] = &flag_d_signed;
	data->flag_tab['D'] = &flag_bigd_signed;
	data->flag_tab['i'] = &flag_d_signed;
	data->flag_tab['o'] = &flag_o_unsigned;
	data->flag_tab['O'] = &flag_o_unsigned;
	data->flag_tab['u'] = &flag_d_unsigned;
	data->flag_tab['U'] = &flag_bigu_unsigned;
	data->flag_tab['x'] = &flag_hex_unsigned;
	data->flag_tab['X'] = &flag_hex_unsigned_maj;
	data->flag_tab['c'] = &flag_c;
	data->flag_tab['s'] = &flag_s;
	data->flag_tab['p'] = &flag_p;
	data->flag_tab['-'] = &flag_moins;
	data->flag_tab['+'] = &flag_plus;
	data->flag_tab[' '] = &flag_space;
	data->flag_tab['#'] = &flag_diese;
	data->flag_tab['h'] = &modif_h;
	data->flag_tab['l'] = &modif_l;
	data->flag_tab['j'] = &modif_j;
	data->flag_tab['z'] = &modif_z;
}
