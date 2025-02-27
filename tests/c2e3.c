#include "test.h"

int main(void)
{
	char *s;
	int	l;
	int	c;
	int	c2;

	c = 0;
	srand(time(NULL));
	while (c < TESTNUM)
	{
		s = (char *)malloc(101 * sizeof(char));
		l = rand() % 100;
		c++;
		c2 = 0;
		while(c2 < l)
			s[c2++] = 10 + rand() % 245;
		if (ft_str_is_numeric(s) != libft_str_is_numeric(s))
		{
			libft_printf_err("\n\t\t\e[1;91mFAILED TEST\e[0m\n\t\t\texpected: %d\n\t\t\tgot: %d\n\t\t\tstr: %s\n\n", libft_str_is_numeric(s), ft_str_is_numeric(s),s);
			free(s);
			return (1);
		}
		free(s);
	}
	return (0);
}
