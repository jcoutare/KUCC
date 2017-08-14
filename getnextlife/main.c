#include "get_next_line.h"

int     main(int ac, char **av)
{
    char *line;
    int fd;
    int i = 0;
	int fd2;
	char *str;

    if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
/*	while (1)
	get_next_line(fd, &line);
	printf("[%d] - %s\n", i++, line); */
	while (get_next_line(fd, &line) > 0)
	{
		ft_putchar('|');
		ft_putstr(line);
		ft_putchar('|');
	}
	return(0);
}

