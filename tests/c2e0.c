#include "test.h"

#undef TESTNUM
#define TESTNUM 10000

int main()
{
	int c;
	int c2;
	int l;
	char *d;
	char *s;
	char *r;

	c = 0;
	while (c < TESTNUM)
	{
		d = (char *)malloc(101 * sizeof(char));
		s = (char *)malloc(101 * sizeof(char));
		if (!d || !s) {
			libft_printf_err("\n\t\t\e[1;91mMemory allocation failed\e[0m\n");
			return (1);
		}
		c2 = 0;
		l = rand() % 100;
		while (c2 < l) {
			s[c2++] = ' '+ rand() % 95;
		}
		s[c2] = '\0'; 
		r = ft_strcpy(d, s);
		if (libft_strcmp(r , s) != 0)
		{
			libft_printf_err("\n\t\t\e[1;91mFAILED TEST\e[0m\n\t\t\tsrc: %s\n\t\t\tdest: %s\n\n", s, d);
			free(d);
			free(s);
			return (1);
		}
		
		free(d);
		free(s);
		c++;
	}
	return (0);
}

