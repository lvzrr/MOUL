#include "headtests.h"

int	main(void)
{
	int		c;
	int		l;
	int		lo;
	char	*str;

	srand(time(NULL));
	c = 0;
	while (c < TESTNUM)
	{
		l = rand() % 100;
		str = libft_gen_rand_str(l);
		lo = ft_strlen(str);
		if (lo != l)
		{
			libft_printf_err("\n\t\t\e[1;91mFAILED TEST\e[0m:\n\t\t\tinput: %s\n\t\t\toutput: %d\n\t\t\texpected: %d\n\n",str,l,lo);
			return (1);
		}
		c++;
	}
	return (TESTPASSED);
}
