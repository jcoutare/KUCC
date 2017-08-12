/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 07:58:36 by jcoutare          #+#    #+#             */
/*   Updated: 2017/08/12 13:12:09 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (str[i] == c)
		return (i);
	return (-1);
}

int		newline(char *str, char **line)
{
	int ibackn;

	if ((ibackn = strichr(str, '\n')) == -1)
		return (0);
	else
	{
		*line = ft_strsub(str, 0, ibackn);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char buffer[BUFF_SIZE + 1];
	int ret;
	char *tmp;

	if (fd < 0 || BUFF_SIZE == 0 || !line)
		return (-1);
	if (newline(buffer, line) == 1)
	{
		ft_strcpy(buffer, ft_strchr(buffer, '\n') + 1);
		return (1);
	}
	else
		tmp = ft_strdup(buffer);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		if (newline(tmp, line) == 1)
		{
			ft_strcpy(buffer, ft_strchr(buffer, '\n') + 1);
			return (1);
		}
	}
	if (ret == -1)
		return (-1);
	if (buffer[0] != '\0')
	{
		*line = tmp;
		buffer[0] = '\0';
		return (1);
	}
	return (0);
}
