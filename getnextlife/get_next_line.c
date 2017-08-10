/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 21:14:35 by jcoutare          #+#    #+#             */
/*   Updated: 2017/08/10 09:19:40 by jcoutare         ###   ########.fr       */
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
		str[ibackn] = ' ';
		*line = ft_strsub(str, 0, ibackn);
		return (1);
	}
	else
	{
		str[ibackn] = ' ';
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

	str = NULL;
	if (!(str = malloc(sizeof(char))))
		return (-1);
	if (fd < 0 || BUFF_SIZE == 0)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		str = ft_strjoin(str, buffer);
		if (newline(str, line) > 0)
			return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	char *line;
	int fd;
	int i = 0;

	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	printf("fd = %d\n", fd);

	while (get_next_line(fd, &line))
		printf("[%d] >%s\n",i++, line);
	return(0);
}
