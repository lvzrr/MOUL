#include "testheads.h"

#undefine TESTNUM
#define TESTNUM 10000

int	main()
{
	int	c;
	int	c2;
	int	p;
	int	l;
	char *d;
	char *s;
	char *a;

	c = 0;
	while (c < TESTNUM)
	{
		d = (char *)malloc(101 * sizeof(char));
		s = (char *)malloc(101 * sizeof(char));
		c2 = 0;
		l = rand() % 100;
		while (l < 100)
			s[c2++] = 10 + rand() % 245;
		ft_strcpy(d, s);
		if (libft_strcmp(d, s) != 0)
		{
			libft_printf_err("\n\t\t\e[1;91mFAILED TEST\e[0m\n\t\t\tsrc: %s\n\t\t\tdest: %s\n\n", s,d);
			free(d);
			free(s);
			return (1)
		}
		free(d);
		free(s);
		c++;
	}
	return (0)
}
