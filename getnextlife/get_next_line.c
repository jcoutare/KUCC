/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 07:58:36 by jcoutare          #+#    #+#             */
/*   Updated: 2017/08/11 13:06:16 by jcoutare         ###   ########.fr       */
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
	return (-1);
}

int newline(char *str, char **line)
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

int get_next_line(const int fd, char **line)
{
	static char buffer[BUFF_SIZE + 1];
	int ret;
	char *tmp;

	if (fd < 0 || BUFF_SIZE == 0)
		return (-1);
	if (!(tmp = malloc(sizeof(char))))
		return (-1);
	if (newline(buffer, line) == 1)
	{
		printf("@> %s\n", buffer);
		ft_strcpy(buffer, ft_strchr(buffer, '\n') + 1);
		return (1);
	}
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		if (newline(buffer, line)== 1)
		{
			printf("1>%s\n", buffer);
			ft_strcpy(buffer, ft_strchr(buffer, '\n') + 1);
			return (1);
		}
	}
	if (newline(buffer, line))
		*line = buffer;
	if (ret == 0)
	{
		*line = tmp;
		return (0);
	}
	return (0);
}
