/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_conv_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:09:13 by jcoutare          #+#    #+#             */
/*   Updated: 2017/10/09 13:51:17 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_d_signed(t_struct *data)
{
	char *arg;

	arg = NULL;
	data->conv = 1;
	if (data->modif != 1)
		data->arg = va_arg(*data->ap, int);
	le_the(data);
	if (data->prec >= 0)
		prec(data);
	if (data->f_zero == 1 && (long long)data->arg < 0 && data->larg > 0)
	{
		arg = ft_itoa(data->arg * -1);
		data->resolved = ft_strjoin(data->resolved, arg);
		data->larg -= 2;
	}
	else if (data->precfail != 1 || data->arg != 0)
	{
		arg = ft_itoa(data->arg);
		data->resolved = ft_strjoin(data->resolved, arg);
	}
	if (arg)
		free(arg);
	le_cafe(data);
}

void	flag_bigd_signed(t_struct *data)
{
	char *arg;

	arg = NULL;
	data->conv = 1;
	if (data->modif != 1)
		data->arg = va_arg(*data->ap, long long int);
	le_the(data);
	if (data->prec >= 0)
		prec(data);
	if (data->f_zero == 1 && (long long)data->arg < 0)
	{
		arg = ft_itoa(data->arg * -1);
		data->resolved = ft_strjoin(data->resolved, arg);
		data->larg -= 2;
	}
	else if (data->precfail != 1 || data->arg != 0)
	{
		arg = ft_itoa(data->arg);
		data->resolved = ft_strjoin(data->resolved, arg);
	}
	if (arg)
		free(arg);
	le_cafe(data);
}

void	flag_d_unsigned(t_struct *data)
{
	char *arg;

	arg = NULL;
	data->conv = 1;
	if (data->modif != 1)
		data->arg = va_arg(*data->ap, unsigned int);
	data->f_plus = 0;
	data->f_space = 0;
	le_the(data);
	if (data->prec > 0)
		prec(data);
	arg = ft_itoa_ull(data->arg);
	if (data->precfail != 1 || data->arg != 0)
		data->resolved = ft_strjoin(data->resolved, arg);
	free(arg);
	le_cafe(data);
}

void	flag_bigu_unsigned(t_struct *data)
{
	char *arg;

	data->conv = 1;
	if (data->modif != 1)
		data->arg = va_arg(*data->ap, unsigned long int);
	data->f_plus = 0;
	data->f_space = 0;
	le_the(data);
	if (data->prec > 0)
		prec(data);
	arg = ft_itoa_ull(data->arg);
	if (data->precfail != 1 || data->arg != 0)
		data->resolved = ft_strjoin(data->resolved, arg);
	free(arg);
	le_cafe(data);
}

void	flag_o_unsigned(t_struct *data)
{
	char		*arg;
	int			i;

	i = -1;
	if (data->modif != 1)
		data->arg = va_arg(*data->ap, long int);
	if (data->precfail == 1)
		data->f_zero = 0;
	make_o_sharp(data);
	if (data->prec > 0)
		prec_hexa(data, 8);
	arg = ft_itoa_base(data->arg, 8);
	if (data->precfail != 1 || data->arg != 0)
	{
		if (data->arg == 0 && data->f_sharp == 1)
			data->conv = 1;
		else
			data->resolved = ft_strjoin(data->resolved, arg);
	}
	free(arg);
	le_cafe(data);
	while (data->resolved[++i])
		data->resolved[i] = ft_tolower(data->resolved[i]);
}
