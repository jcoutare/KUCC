/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:19:45 by jcoutare          #+#    #+#             */
/*   Updated: 2017/04/26 15:38:12 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		cpt_words(const char *str, char c)
{
	size_t i;
	size_t cpt_w;

	i = 0;
	cpt_w = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			cpt_w++;
		i++;
	}
	return (cpt_w);
}

static int		*cpt_ltr(const char *str, char c)
{
	int			*tab;
	size_t		i;
	size_t		cpt_ltr;
	size_t		j;

	j = 0;
	cpt_ltr = 0;
	if ((tab = malloc(sizeof(int) * (cpt_words(str, c) + 1))) == NULL)
		return (NULL);
	tab[cpt_words(str, c)] = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			cpt_ltr++;
		if ((str[i] == c || str[i + 1] == '\0') && cpt_ltr != 0)
		{
			tab[j] = cpt_ltr;
			cpt_ltr = 0;
			j++;
		}
		i++;
	}
	return (tab);
}

static char		**malloc_tab(const char *str, char c)
{
	char		**tab;
	int			*ltr;
	size_t		nb_w;
	size_t		words;

	words = 0;
	if ((ltr = cpt_ltr(str, c)) == NULL)
		return (NULL);
	nb_w = cpt_words(str, c);
	if ((tab = malloc(sizeof(char *) * (nb_w + 1))) == NULL)
		return (NULL);
	tab[nb_w] = 0;
	while (words < nb_w)
	{
		if ((tab[words] = malloc(sizeof(char) * (ltr[words] + 1))) == NULL)
			return (NULL);
		tab[words][ltr[words]] = '\0';
		words++;
	}
	free(ltr);
	return (tab);
}

char			**ft_strsplit(const char *str, char c)
{
	char		**tab;
	size_t		i;
	size_t		words;
	size_t		ltr;

	if (str == NULL)
		return (NULL);
	i = 0;
	words = 0;
	ltr = 0;
	if ((tab = malloc_tab(str, c)) == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] != c)
			tab[words][ltr++] = str[i];
		if (str[i] == c && ltr != 0)
		{
			words++;
			ltr = 0;
		}
		i++;
	}
	return (tab);
}
