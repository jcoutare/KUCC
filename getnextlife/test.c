#include "libft/libft.h"

int cpy(char *str, int i)
{
	int k = 0;
	while (k < i && str[i])
	{
		str[k] = str[i];
		k++;
		i++;
	}
	str[k] = '\0';
	return (0);
}

int main(void)
{
	static char buffer[10 + 1] = "0123456789\0";
	char *tmp = buffer;
	printf("%s\n", buffer);
	cpy(tmp, 4);
	printf("%s\n", buffer);
}
