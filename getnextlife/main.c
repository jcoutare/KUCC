#include "get_next_line.h"

int     main(int ac, char **av)
{
    char *line;
    int fd;
    int i = 0;

    if ((fd = open(av[1], O_RDONLY)) == -1)
        return (0);

	int vGNL = get_next_line(fd, &line);
	printf("[%d] >%s| vGNL = [%d]\n",i++, line, vGNL);
	vGNL = get_next_line(fd, &line);
    printf("[%d] >%s| vGNL = [%d]\n",i++, line, vGNL);
    vGNL = get_next_line(fd, &line);
    printf("[%d] >%s| vGNL = [%d]\n",i++, line, vGNL);
    vGNL = get_next_line(fd, &line);
    printf("[%d] >%s| vGNL = [%d]\n",i++, line, vGNL);
    vGNL = get_next_line(fd, &line);
    printf("[%d] >%s [%d]\n",i++, line, vGNL);
	return(0);
}

