#include "test.h"

#undef TESTNUM
#define TESTNUM 100000

int	main(void)
{
	int c = 0;
	while (c < TESTNUM)
	{
		int l = rand() % 100;
		int c2 = 0;
		char *str = (char *)malloc(101 * sizeof(char));
		char *cpy = (char *)malloc(101 * sizeof(char));
		while (c2 < l)
		{
			int t = ' ' + rand() % 95;
			str[c2] = t;
			cpy[c2++] = t;
		}
		str[c2] = 0;
		cpy[c2] = 0;
		if (c % 10000 == 0)
			w_trace("To uppercase: %s\n",str);
		char *s = ft_strupcase(str);
		if (c % 10000 == 0)
			w_trace("Result: %s\n", s);
		while (*s)
		{
			if(*s >= 'a' && *s <= 'z')
			{
				libft_printf_err("\n\t\t\e[1;91mFAILED TEST\e[0m\n\t\t\tsrc: %s\n\t\t\tgot: %s\n\n", str, cpy);
				free(str);
				free(cpy);
				return (1);
			}
			s++;
		}
		free(str);
		free(cpy);
		c++;
	}
	return (TESTPASSED);
}
