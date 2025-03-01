#include "test.h"

int	main(void)
{
	int w = 0;
	while (w < TESTNUM)
	{
		char *c = (char *)malloc(101 * sizeof(char)); 
		char *o = (char *)malloc(101 * sizeof(char)); 
		char *lo = (char *)malloc(101 * sizeof(char)); 
		memset(o, 0, 101);
		memset(lo, 0, 101);
		int l = rand() % 100;
		int c2 = 0;
		while (c2 < l)
			c[c2++] =  ' ' + rand() % 95;
		c[l] = '\0';
		int s = rand() % 100;
		ft_strlcpy(o,c,s);
		libft_strlcpy(lo,c,s);
		if (strcmp(o, lo) != 0)
		{
			libft_printf_err("\n\t\t\e[1;91mFAILED TEST\e[0m\n\t\t\tsrc: %s\n\t\t\tgot: %s\n\t\t\texpected: %s\n\t\t\tsize: %d\n\n", c, o, lo, l);
			free(c);
			free(o);
			free(lo);
			return (1);
		}
		free(c);
		free(o);
		free(lo);
		w++;
	}
	return (0);
}
