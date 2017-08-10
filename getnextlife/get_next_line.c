/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 21:14:35 by jcoutare          #+#    #+#             */
/*   Updated: 2017/08/10 11:22:48 by jcoutare         ###   ########.fr       */
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
			ft_putstr(":)");
			tmp = str + (strichr(str, '\n') + 1);
			str = tmp;
			return (1);
		}
	}
	if (!(str = malloc(sizeof(char))))
		return (-1);
	if (fd < 0 || BUFF_SIZE == 0)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		printf(">%s\n", str);
		str = ft_strjoin(str, buffer);
		printf(">>%s\n", str);
		if (newline(str, line) > 0)
		{
			tmp = str + (strichr(str, '\n') + 1);
			str = tmp;
			printf(">>>%s\n", str);
			return (1);
		}
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
	printf("buff_size = %d\n", BUFF_SIZE);

	int vGNL = get_next_line(fd, &line);
	printf("[%d] >%s| vGNL = [%d]\n",i++, line, vGNL);
	vGNL = get_next_line(fd, &line);
	printf("[%d] >%s| vGNL = [%d]\n",i++, line, vGNL);
	vGNL = get_next_line(fd, &line);
	printf("[%d] >%s| vGNL = [%d]\n",i++, line, vGNL);
	vGNL = get_next_line(fd, &line);
	printf("[%d] >%s| vGNL = [%d]\n",i++, line, vGNL);
	vGNL = get_next_line(fd, &line);
	printf("[%d] >%s| vGNL = [%d]\n",i++, line, vGNL);
	return(0);
}
