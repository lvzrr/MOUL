#include "test.h"

#undef TESTNUM
#define TESTNUM 10000

int main()
{
	srand(time(NULL));
	int 			c;
	int 			c2;
	int 			l;
	char 			*d;

	c = 0;
	while (c < TESTNUM)
	{
		d = (char *)malloc(101 * sizeof(char));
		if (!d) {
			libft_printf_err("\n\t\t\e[1;91mMemory allocation failed\e[0m\n");
			return (1);
		}
		c2 = 0;
		l = rand() % 100;
		while (c2 < l) {
			d[c2++] = ' ' + rand() % 95;
		}
		d[c2] = '\0';
		if (libft_str_is_alpha(d) != ft_str_is_alpha(d))
		{
			libft_printf_err("\n\t\t\e[1;91mFAILED TEST\e[0m\n\t\t\tsrc: %s\n\t\t\tgot: %d\n\n", d, ft_str_is_alpha(d));
			free(d);
			return (1);
		}
		free(d);
		c++;
	}
	return (0);
}

