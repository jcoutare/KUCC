/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 21:14:35 by jcoutare          #+#    #+#             */
/*   Updated: 2017/08/10 13:42:31 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int strichr(char *str, char c)
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

int newline(char *str, char **line)
{
	int ibackn;

	if ((ibackn = strichr(str, '\n')) == -1)
		return (0);
	if (*line == NULL)
	{
		if (!(*line = malloc(sizeof(char))))
			return (-1);
		*line = ft_strsub(str, 0, ibackn);
		return (1);
	}
	else
	{
		*line = ft_strsub(str, 0, ibackn);
		return (1);
	}
	return (0);
}
int		get_next_line(const int fd, char **line)
{
	char buffer[BUFF_SIZE + 1];
	int ret;
	static char *str;
	char *tmp;

	if (str != NULL)
	{
		if (newline(str, line) > 0)
		{
			tmp = str + (strichr(str, '\n') + 1);
			str = tmp;
			return (1);
		}
	}
	if (str == NULL)
	{
		if (!(str = malloc(sizeof(char))))
			return (-1);
	}
	if (fd < 0 || BUFF_SIZE == 0)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		str = ft_strjoin(str, buffer);
		if (newline(str, line) > 0)
		{
			tmp = str + (strichr(str, '\n') + 1);
			str = tmp;
			return (1);
		}
	}
	*line = str;
	return (0);
}
