/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 15:19:25 by jcoutare          #+#    #+#             */
/*   Updated: 2017/09/29 15:24:32 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnfjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		i;
	size_t		j;
	size_t		size;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if ((str = malloc(sizeof(char) * (size + 1))) == 0)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	char		*str;
	size_t		i;
	size_t		j;
	size_t		size;

	i = -1;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if ((str = malloc(sizeof(char) * (size + 1))) == 0)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j] && (int)j < n)
	{
		str[i + j] = s2[j];
		j++;
	}
	if (s1)
		free((void *)s1);
	str[i + j] = '\0';
	return (str);
}

int		strichr(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		strichr_str(char *str, char *chr)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (chr[j])
		{
			if (str[i] == chr[j])
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int		strcheck(char *str, char *check)
{
	int i;
	int j;
	int ok;

	i = 0;
	while (str[i])
	{
		j = 0;
		ok = 0;
		while (check[j])
		{
			if (str[i] == check[j] || (str[i] <= '9' && str[i] >= '0'))
				ok = 1;
			j++;
		}
		if (ok == 0)
			return (i);
		i++;
	}
	return (-1);
}
